/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _DEFAULT = 0,
    _LOWER,
    _RAISE,
    _MOUSE,
    _NUMBER
};

// Custom keycodes
enum custom_keycodes {
    JS_ARROW = SAFE_RANGE,
    SFT_SFT,
};

// Home row mods - Left hand
//[max] ########
#define HRM_A    LT(_RAISE, KC_A)
#define HRM_R    MT(MOD_LCTL, KC_R)
#define HRM_S    MT(MOD_LGUI, KC_S)
#define HRM_T    MT(MOD_LSFT, KC_T)
#define HRM_Z    LT(_NUMBER, KC_Z)

// Home row mods - Right hand
//[max] ########
#define HRM_N    MT(MOD_RSFT, KC_N)
#define HRM_E    MT(MOD_LGUI, KC_E)
#define HRM_I    MT(MOD_RCTL, KC_I)
#define HRM_O    LT(_RAISE, KC_O)

// Layer taps
//[max] ########
#define LWR_ENT  LT(_LOWER, KC_ENT) // Unused
#define MO_LWR   MO(_LOWER)
#define MSE_KEY  LT(_MOUSE, KC_SCLN) // LALT and LSFT are added on process_record_user

// Mod taps
//[max] ########
#define CMD_SPC  MT(MOD_LGUI, KC_SPC)

// Mod keys
//[max] ########
#define JW_LEFT  A(KC_LEFT)
#define JW_RGHT  A(KC_RIGHT)
#define APP_BACK G(KC_LBRC)
#define APP_FORW G(KC_RBRC)
#define DEL_WORD A(KC_BSPC)
#define SC_TOGG SENTENCE_CASE_TOGGLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   HRM_A,   HRM_R,   HRM_S,   HRM_T,    KC_G,                         KC_M,   HRM_N,   HRM_E,   HRM_I,   HRM_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG,   HRM_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, SFT_SFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, CMD_SPC,  KC_TAB,     KC_ENT,  MO_LWR, MSE_KEY
                                      //`--------------------------'  `--------------------------'
  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RM_TOGG, UG_SPDU, UG_VALU, UG_NEXT, KC_TRNS, KC_TRNS,                      JW_LEFT, KC_TRNS, KC_TRNS, JW_RGHT, KC_PGUP, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, UG_SPDD, UG_VALD, UG_PREV, KC_TRNS,JS_ARROW,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_PGDN,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG, C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),                      KC_TRNS, KC_TRNS, KC_TRNS,APP_BACK,APP_FORW, SFT_SFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         DEL_WORD, KC_BSPC,DEL_WORD,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS,  KC_AT, KC_LCBR, KC_RCBR, KC_TRNS,                       KC_TRNS, KC_TILD, KC_ASTR, KC_PLUS, KC_TRNS,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN, KC_MINS,                      KC_UNDS, KC_COLN, KC_AMPR, KC_EXLM,  KC_EQL,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TRNS,                      KC_TRNS, KC_SCLN,  KC_GRV, KC_PIPE, KC_BSLS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_TRNS, MS_WHLU, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS,   MS_UP, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, MS_BTN2, MS_BTN3, MS_WHLD, MS_BTN1, KC_TRNS,                      KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,    KC_7,    KC_8,    KC_9, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, SELLINE, SELWBAK, SELWORD, KC_MINS,                      KC_UNDS,    KC_4,    KC_5,    KC_6, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SC_TOGG, KC_TRNS,                      KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_0, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )
};

// Caps word configuration - allow underscore, backspace, delete, minus
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// Per-key tapping term (matching ZMK's 200ms for home row mods)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_A:
        case HRM_R:
        case HRM_S:
        case HRM_T:
        case HRM_Z:
        case HRM_N:
        case HRM_E:
        case HRM_I:
        case HRM_O:
        case LWR_ENT:
        case MSE_KEY:
        case CMD_SPC:
            return 200;
        default:
            return TAPPING_TERM;
    }
}

// Hold on other key press per key (implements ZMK's hold-trigger-on-release behavior)
//bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case HRM_A:
//        case HRM_R:
//        case HRM_S:
//        case HRM_T:
//        case HRM_Z:
//        case HRM_N:
//        case HRM_E:
//        case HRM_I:
//        case HRM_O:
//            return true;
//        default:
//            return false;
//    }
//}

// Macro implementation
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JS_ARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;
        case SFT_SFT:
            if (record->event.pressed) {
                tap_code(KC_RSFT);
                tap_code(KC_RSFT);
            }
            return false;
        case MSE_KEY:
            if(record->tap.count != 0) { // When tapped and not held
                if(record->event.pressed) { // On press
                    add_mods(MOD_BIT(KC_LSFT));
                    add_mods(MOD_BIT(KC_LALT));
                } else { // On release
                    del_mods(MOD_BIT(KC_LSFT));
                    del_mods(MOD_BIT(KC_LALT));
                }
            }
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer > 0) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED) {
                    uint8_t keycode_at_index = keymap_key_to_keycode(layer, (keypos_t){col,row});

                    if(keycode_at_index > KC_TRNS) {
//                        switch(layer) {
//                            case _RAISE: {
//                                switch(row) {
//                                    case 0: {
//                                        rgb_matrix_set_color(index, RGB_RED);
//                                        break;
//                                    }
//                                    case 1: {
//                                        rgb_matrix_set_color(index, RGB_ORANGE);
//                                        break;
//                                    }
//                                    case 2: {
//                                        rgb_matrix_set_color(index, RGB_YELLOW);
//                                        break;
//                                    }
//                                    case 3: {
//                                        rgb_matrix_set_color(index, RGB_WHITE);
//                                        break;
//                                    }
//                                }
//                            }
//                        }
                    } else {
                        rgb_matrix_set_color(index, RGB_OFF);
                    }
                }
            }
        }
    }
    return false;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DEFAULT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_LOWER]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_RAISE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_MOUSE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NUMBER]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
