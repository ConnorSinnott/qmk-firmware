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
#include "print.h"

// Layer definitions
enum layers {
    _DEFAULT = 0,
    _LOWER,
    _RAISE,
    _MOUSE,
    _NUMBER,
    _ADJUST
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
#define ADJ_PIP  LT(_ADJUST, KC_BSLS)
#define NUM_SPC  LT(_NUMBER, KC_SPC)

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
#define CMD_Z    G(KC_Z)
#define CMD_X    G(KC_X)
#define CMD_C    G(KC_C)
#define CMD_V    G(KC_V)

// Toggle Keys
#define SC_TOGG SENTENCE_CASE_TOGGLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, ADJ_PIP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   HRM_A,   HRM_R,   HRM_S,   HRM_T,    KC_G,                         KC_M,   HRM_N,   HRM_E,   HRM_I,   HRM_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG,   HRM_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, SFT_SFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, NUM_SPC,  KC_TAB,     KC_DEL, LWR_ENT, MSE_KEY
                                      //`--------------------------'  `--------------------------'
  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      JW_LEFT, _______, _______, JW_RGHT, KC_PGUP, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,JS_ARROW,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_PGDN,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),                      _______, _______, _______,APP_BACK,APP_FORW, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         DEL_WORD, KC_BSPC,DEL_WORD,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______,  KC_AT, KC_LCBR, KC_RCBR, _______,                       _______, KC_TILD, KC_ASTR, KC_PLUS, _______,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN, KC_MINS,                      KC_UNDS, KC_COLN, KC_AMPR, KC_EXLM,  KC_EQL,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, _______,                      _______, KC_SCLN,  KC_GRV, KC_PIPE, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, MS_WHLU, _______, _______,                      _______, _______,   MS_UP, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, MS_BTN2, MS_BTN3, MS_WHLD, MS_BTN1, _______,                      _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______,    KC_7,    KC_8,    KC_9, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, SELLINE, SELWBAK, SELWORD, _______,                      _______,    KC_4,    KC_5,    KC_6, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   CMD_Z,   CMD_X,   CMD_C, _______,   CMD_V,                      _______,    KC_1,    KC_2,    KC_3,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RM_TOGG, UG_SPDU, UG_VALU, UG_NEXT, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, UG_SPDD, UG_VALD, UG_PREV, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, SC_TOGG, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
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
    switch(layer) {
        case _DEFAULT: {
            uint8_t mods = get_mods();

            if(is_caps_word_on()) {
                rgb_matrix_set_color(g_led_config.matrix_co[2][0], RGB_RED);
                rgb_matrix_set_color(g_led_config.matrix_co[1][4], RGB_RED);
            } else if (is_sentence_case_primed()) {
                rgb_matrix_set_color(g_led_config.matrix_co[2][0], RGB_WHITE);
                rgb_matrix_set_color(g_led_config.matrix_co[1][4], RGB_WHITE);
            } else if (mods & MOD_BIT(KC_LSFT) || mods & MOD_BIT(KC_RSFT)) {
                rgb_matrix_set_color(g_led_config.matrix_co[2][0], RGB_ORANGE);
                rgb_matrix_set_color(g_led_config.matrix_co[1][4], RGB_ORANGE);
            }

            if(mods & MOD_BIT(KC_LGUI)) {
                rgb_matrix_set_color(g_led_config.matrix_co[1][3], RGB_PURPLE);
                if(is_keyboard_master()) {
                    rgb_matrix_set_color(7, RGB_PURPLE);
                }
            }

            if(mods & MOD_BIT(KC_LCTL) || mods & MOD_BIT(KC_RCTL)) {
                rgb_matrix_set_color(g_led_config.matrix_co[1][2], RGB_BLUE);
            }

            break;
        }
        case _LOWER: {
            break;
        }
        case _RAISE: {
            break;
        }
        case _MOUSE: {
            break;
        }
        case _NUMBER: {
            break;
        }
        case _ADJUST: {
            rgb_matrix_set_color_all(0, 0, 0);
            if(is_keyboard_master() && is_sentence_case_on()) {
                rgb_matrix_set_color(g_led_config.matrix_co[2][4], RGB_GREEN);
            } else {
                rgb_matrix_set_color(g_led_config.matrix_co[2][4], RGB_RED);
            }
            break;
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
