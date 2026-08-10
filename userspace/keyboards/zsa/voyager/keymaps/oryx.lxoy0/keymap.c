#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
};

#define DUAL_FUNC_0 LT(15, KC_X)
#define DUAL_FUNC_1 LT(4, KC_H)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_CAPS,        
    KC_CAPS,        KC_Q,           KC_W,           LT(4, KC_E),    LT(5, KC_R),    KC_T,                                           KC_Y,           ALL_T(KC_U),    KC_I,           MT(MOD_RCTL, KC_O),KC_P,           KC_BSPC,        
    KC_TAB,         MT(MOD_LSFT, KC_A),MT(MOD_LCTL, KC_S),LT(3, KC_D),    ALL_T(KC_F),    MEH_T(KC_G),                                    KC_H,           KC_J,           KC_K,           KC_L,           KC_RIGHT_SHIFT, KC_QUOTE,       
    KC_LEFT_CTRL,   TD(DANCE_0),    KC_X,           KC_C,           MT(MOD_LALT, KC_V),LT(2, KC_B),                                    LT(2, KC_N),    MT(MOD_RALT, KC_M),KC_COMMA,       DUAL_FUNC_0,    MT(MOD_RALT, KC_SLASH),TD(DANCE_1),    
                                                    MT(MOD_LGUI, KC_ENTER),MO(1),                                          LT(1, KC_BSPC), MT(MOD_RGUI, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_ESCAPE,      ST_MACRO_0,     KC_AT,          UK_PND,         KC_DLR,         LALT(LSFT(KC_8)),                                KC_F6,          KC_F7,          KC_COMMA,       KC_DOT,         KC_F10,         TO(3),          
    KC_QUOTE,       KC_GRAVE,       KC_DQUO,        KC_LABK,        KC_RABK,        KC_AMPR,                                        KC_UNDS,        KC_LCBR,        KC_RCBR,        KC_SCLN,        KC_PERC,        KC_F12,         
    KC_BSLS,        KC_AT,          KC_PLUS,        KC_MINUS,       KC_EQUAL,       KC_EXLM,                                        KC_SCLN,        KC_LPRN,        KC_RPRN,        KC_COLN,        KC_QUES,        KC_DLR,         
    LCTL(UK_GRV),   KC_CIRC,        KC_DLR,         LALT(KC_3),     KC_ASTR,        KC_PIPE,                                        KC_TILD,        KC_LBRC,        KC_RBRC,        KC_SLASH,       LCTL(RGUI(KC_SPACE)),ST_MACRO_1,     
                                                    KC_SPACE,       KC_BSPC,                                        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    TO(0),          TOGGLE_LAYER_COLOR,RGB_TOG,        RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_MEDIA_PREV_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, QK_LLCK,        
    RGB_HUI,        RGB_SAI,        RGB_SPI,        LGUI(LSFT(KC_S)),LALT(LGUI(LCTL(LSFT(KC_QUOTE)))),KC_TRANSPARENT,                                 LALT(KC_LEFT),  KC_LEFT,        KC_RIGHT,       RALT(KC_RIGHT), KC_BRIGHTNESS_UP,KC_AUDIO_VOL_UP,
    RGB_HUD,        RGB_SAD,        RGB_SPD,        KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,                                KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_AUDIO_VOL_DOWN,
    LED_LEVEL,      KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_TRANSPARENT,                                 LALT(LGUI(LCTL(LSFT(KC_F10)))),LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_2),    
                                                    KC_LEFT_GUI,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(KC_LEFT),  KC_PGDN,        KC_PAGE_UP,     LGUI(KC_RIGHT), KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,                                        LALT(KC_LEFT),  KC_TRANSPARENT, KC_BSPC,        LALT(KC_RIGHT), KC_TRANSPARENT, DUAL_FUNC_1,    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AT,          KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_GRAVE),                                 LGUI(LSFT(KC_ENTER)),LCTL(KC_SPACE), KC_TRANSPARENT, LGUI(KC_DOT),   KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TAB,                                         KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DELETE,      KC_KP_7,        KC_KP_8,        KC_KP_9,        UK_PLUS,        TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_BSPC,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_MINUS,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          QK_LLCK,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ASTERISK, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         LGUI(KC_GRAVE), KC_KP_EQUAL,    KC_KP_0,        KC_KP_DOT,      KC_KP_SLASH,    KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL2,   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,                                    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_ACCEL1,   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_BTN1,     KC_TRANSPARENT,                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_MS_ACCEL0,   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_MS_BTN1,     KC_MS_BTN2,                                     KC_MS_BTN2,     KC_MS_BTN1
  ),
};


const uint16_t PROGMEM combo0[] = { MT(MOD_LGUI, KC_ENTER), MT(MOD_RGUI, KC_SPACE), COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo2[] = { ALL_T(KC_F), LT(3, KC_D), COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo4[] = { MT(MOD_LCTL, KC_S), LT(3, KC_D), COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_LSFT, KC_A), KC_RIGHT_SHIFT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
    COMBO(combo1, RALT(KC_BSPC)),
    COMBO(combo2, LALT(KC_BSPC)),
    COMBO(combo3, KC_RIGHT_SHIFT),
    COMBO(combo4, KC_LEFT_SHIFT),
    COMBO(combo5, LCTL(KC_F)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4, KC_E):
            return TAPPING_TERM + 10;
        case MT(MOD_LSFT, KC_A):
            return TAPPING_TERM -7;
        case MT(MOD_LCTL, KC_S):
            return TAPPING_TERM -10;
        case LT(3, KC_D):
            return TAPPING_TERM -10;
        case MEH_T(KC_G):
            return TAPPING_TERM -10;
        case TD(DANCE_0):
            return TAPPING_TERM -10;
        case MT(MOD_LALT, KC_V):
            return TAPPING_TERM -20;
        case LT(2, KC_B):
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_ENTER):
            return TAPPING_TERM -52;
        case ALL_T(KC_U):
            return TAPPING_TERM + 20;
        case MT(MOD_RCTL, KC_O):
            return TAPPING_TERM + 30;
        case KC_P:
            return TAPPING_TERM + 50;
        case KC_BSPC:
            return TAPPING_TERM + 200;
        case KC_RIGHT_SHIFT:
            return TAPPING_TERM -30;
        case LT(2, KC_N):
            return TAPPING_TERM + 60;
        case LT(1, KC_BSPC):
            return TAPPING_TERM -25;
        case MT(MOD_RGUI, KC_SPACE):
            return TAPPING_TERM -15;
        default:
            return TAPPING_TERM;
    }
}


extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {248,255,255}, {0,0,0}, {117,153,255}, {47,255,255}, {99,255,255}, {0,0,0}, {0,0,0}, {47,255,255}, {198,200,255}, {237,166,255}, {237,166,255}, {99,255,255}, {88,255,255}, {47,255,255}, {99,255,255}, {99,255,255}, {146,255,255}, {117,153,255}, {0,0,0}, {200,218,204}, {199,255,255}, {181,48,255}, {99,255,255}, {47,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {99,255,255}, {99,255,255}, {0,0,0}, {0,0,0}, {99,255,255}, {237,166,255}, {237,166,255}, {0,0,0}, {99,255,255}, {0,0,0}, {0,0,255}, {237,166,255}, {237,166,255}, {0,0,255}, {117,153,255}, {248,255,255}, {99,255,255}, {237,166,255}, {237,166,255}, {99,255,255}, {0,0,0}, {25,230,255}, {248,255,255}, {99,255,255} },

    [2] = { {0,255,255}, {95,255,255}, {0,0,255}, {0,255,255}, {0,0,81}, {0,0,255}, {28,255,255}, {0,255,255}, {0,0,0}, {123,218,204}, {131,218,204}, {0,0,0}, {163,178,233}, {0,76,255}, {0,0,0}, {0,0,0}, {0,0,0}, {211,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,218,204}, {1,218,204}, {198,200,255}, {152,218,204}, {226,199,255}, {90,218,204}, {111,218,204}, {161,218,204}, {161,218,204}, {111,218,204}, {90,218,204}, {182,218,204}, {0,0,0}, {48,218,204}, {48,218,204}, {0,0,0}, {90,218,204}, {182,218,204}, {1,218,204}, {0,0,0}, {0,0,0}, {255,255,255}, {0,0,0}, {1,218,204}, {0,0,0}, {0,0,0} },

    [3] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {25,230,255}, {126,255,255}, {126,255,255}, {25,230,255}, {0,0,0}, {248,255,255}, {200,255,84}, {0,0,0}, {0,218,204}, {200,255,84}, {0,0,0}, {237,166,255}, {162,218,204}, {162,218,204}, {162,218,204}, {162,218,204}, {0,0,0}, {0,0,0}, {237,166,255}, {99,255,255}, {0,0,0}, {99,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {226,255,255}, {226,255,255}, {226,255,255}, {226,255,255}, {226,255,255}, {0,0,0}, {226,255,255}, {226,255,255}, {226,255,255}, {226,255,255}, {226,255,255}, {0,0,0}, {0,0,0}, {0,218,204}, {188,255,255}, {188,255,255}, {188,255,255}, {126,255,255}, {0,0,0}, {0,218,204}, {188,255,255}, {188,255,255}, {188,255,255}, {126,255,255}, {0,0,0}, {52,180,255}, {188,255,255}, {188,255,255}, {188,255,255}, {126,255,255}, {0,0,0}, {88,255,255}, {199,255,255}, {188,255,255}, {157,255,255}, {126,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,255,255}, {96,218,204}, {96,218,204}, {96,218,204}, {96,218,204}, {96,218,204}, {96,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {96,218,204}, {96,218,204}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {96,218,204}, {96,218,204}, {96,218,204}, {96,218,204}, {96,218,204}, {96,218,204}, {96,218,204}, {189,138,255}, {189,255,255}, {0,0,0}, {0,0,0}, {139,255,255}, {0,0,0}, {0,0,0}, {6,150,255}, {0,0,0}, {189,138,255}, {189,255,255}, {0,0,0}, {211,90,255}, {23,188,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {211,90,255}, {61,199,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {189,255,255}, {189,138,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
        break;
      case 5:
        set_layer_color(5);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,      
    SINGLE_HOLD,         
    DOUBLE_TAP,          
    DOUBLE_HOLD,         
    DOUBLE_SINGLE_TAP,   
    MORE_TAPS            
};

static tap dance_state[3];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if(state->count > 3) {
        tap_code16(KC_Z);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_Z); break;
        case SINGLE_HOLD: register_code16(LALT(LCTL(LGUI(LSFT(KC_2))))); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LGUI(LSFT(KC_2))))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Z); register_code16(KC_Z);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_Z); break;
        case SINGLE_HOLD: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_2))))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_2))))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Z); break;
    }
    dance_state[0].step = 0;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_HOLD: layer_on(4); break;
        case DOUBLE_TAP: layer_move(2); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_HOLD:
          if(!is_layer_locked(4)) {
            layer_off(4);
          }
        break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_AUDIO_MUTE);
        tap_code16(KC_AUDIO_MUTE);
        tap_code16(KC_AUDIO_MUTE);
    }
    if(state->count > 3) {
        tap_code16(KC_AUDIO_MUTE);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_TAP: layer_move(0); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_AUDIO_MUTE); register_code16(KC_AUDIO_MUTE);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
    }
    dance_state[2].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_GRAVE));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_BSLS)SS_DELAY(100)  SS_LSFT(SS_TAP(X_ENTER)));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DOT);
        } else {
          unregister_code16(KC_DOT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_UNDS);
        } else {
          unregister_code16(KC_UNDS);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_TAB));
        } else {
          unregister_code16(LCTL(KC_TAB));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(LSFT(KC_TAB)));
        } else {
          unregister_code16(LCTL(LSFT(KC_TAB)));
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
