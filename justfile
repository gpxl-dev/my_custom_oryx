# Build local firmware only. Never download, switch branches, commit, or push.
default: build

build:
    #!/usr/bin/env bash
    set -euo pipefail
    repo_dir="$PWD"
    geometry=$(jq -er '.geometry' config.json)
    layout=$(jq -er '.layout' config.json | tr '[:upper:]' '[:lower:]')
    if [[ "$(uname -s)" == "Darwin" ]] && command -v brew >/dev/null; then
        arm_gcc_bin="$(brew --prefix arm-none-eabi-gcc@8 2>/dev/null || true)/bin"
        arm_binutils_bin="$(brew --prefix arm-none-eabi-binutils 2>/dev/null || true)/bin"
        if [[ -x "$arm_gcc_bin/arm-none-eabi-gcc" ]]; then
            export PATH="$arm_gcc_bin:$arm_binutils_bin:$PATH"
        fi
    fi
    cd qmk_firmware
    qmk config user.overlay_dir="$repo_dir/userspace"
    qmk compile -kb "zsa/$geometry" -km "oryx.$layout"
