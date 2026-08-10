#!/usr/bin/env bash
set -Eeuo pipefail

original_dir=$PWD
script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
repo_dir=$(cd -- "$script_dir/.." && pwd)
config_file="$repo_dir/config.json"
source_zip="$repo_dir/source.zip"
trap 'rm -f "$source_zip"; cd "$original_dir"' EXIT

cd "$repo_dir"

# Read and validate configuration before switching to the oryx branch, where
# config.json might not exist.
if [[ ! -f "$config_file" ]]; then
    echo "Error: config.json was not found at $config_file" >&2
    exit 1
fi

hash_id_config=$(jq -er '.layout | select(type == "string" and length > 0)' "$config_file")
geometry=$(jq -er '.geometry | select(type == "string" and length > 0)' "$config_file")
keymap_dir="oryx.$(printf '%s' "$hash_id_config" | tr '[:upper:]' '[:lower:]')"

request=$(jq -n \
    --arg hash_id "$hash_id_config" \
    --arg geometry "$geometry" \
    '{
        query: "query getLayout($hashId: String!, $revisionId: String!, $geometry: String) { layout(hashId: $hashId, geometry: $geometry, revisionId: $revisionId) { revision { hashId qmkVersion title } } }",
        variables: {hashId: $hash_id, geometry: $geometry, revisionId: "latest"}
    }')

response=$(curl --fail-with-body --silent --show-error \
    'https://oryx.zsa.io/graphql' \
    --header 'Content-Type: application/json' \
    --data-binary "$request")

if jq -e '.errors or (.data.layout.revision == null)' >/dev/null <<<"$response"; then
    echo "Error: Oryx did not return a revision for layout $hash_id_config ($geometry)." >&2
    jq . <<<"$response" >&2
    exit 1
fi

revision_hash=$(jq -er '.data.layout.revision.hashId' <<<"$response")
firmware_version=$(jq -er '.data.layout.revision.qmkVersion | tonumber | floor' <<<"$response")
change_description=$(jq -r '.data.layout.revision.title // empty' <<<"$response")

if (( firmware_version >= 24 )); then
    keyboard_directory="zsa"
else
    keyboard_directory=""
fi

if [[ -z "$change_description" ]]; then
    change_description="latest layout modification made with Oryx"
fi

echo "Using Oryx revision $revision_hash and ZSA firmware$firmware_version"

# Download the latest Oryx keymap and commit it to the oryx branch.
git checkout -B oryx origin/oryx
curl --fail-with-body --location --silent --show-error \
    "https://oryx.zsa.io/source/$revision_hash" \
    --output "$source_zip"

keymap_path="$repo_dir/userspace/keyboards"
if [[ -n "$keyboard_directory" ]]; then
    keymap_path+="/$keyboard_directory"
fi
keymap_path+="/$geometry/keymaps/$keymap_dir"
mkdir -p "$keymap_path"
unzip -oj "$source_zip" '*_source/*' -d "$keymap_path"
rm -f "$source_zip"

git add "$keymap_path"
git commit -m "✨(oryx): $change_description" || echo "No layout change"
git push origin oryx

# Merge Oryx output into main, which contains the custom QMK changes.
git fetch origin main
git checkout -B main origin/main
git merge -Xignore-all-space oryx -m "Merging ✨(oryx): $change_description"
git push origin main

# Select the matching ZSA firmware branch without updating to the remote's
# default branch first.
git submodule update --init qmk_firmware
git -C qmk_firmware fetch --depth=1 origin "firmware$firmware_version"
git -C qmk_firmware checkout -B "firmware$firmware_version" FETCH_HEAD
git -C qmk_firmware submodule update --init --recursive

git add qmk_firmware
git commit -m "✨(qmk): Update firmware" || echo "No QMK change"
git push origin main

# qmk_firmware is already present and initialized, so qmk setup is neither
# needed nor allowed to prompt for replacing it.
cd qmk_firmware
qmk config user.overlay_dir="$repo_dir/userspace"
if [[ -n "$keyboard_directory" ]]; then
    keyboard="$keyboard_directory/$geometry"
else
    keyboard="$geometry"
fi
qmk compile -kb "$keyboard" -km "$keymap_dir"
