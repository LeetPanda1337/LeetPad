// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "dynamic_keymap.h"

enum layers{
    LAYER0,
    LAYER1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER0] = LAYOUT_keymap(
        TT(1),           KC_MPRV,   KC_F13,   KC_NO,    KC_NO,   KC_NO,    KC_F19,
        KC_CALC,         KC_MNXT,   KC_F14,   KC_F16,   KC_NO,   KC_NO,    KC_F20,
        KC_AUDIO_MUTE,   KC_MPLY,   KC_F15,   KC_F17,   KC_NO,   KC_F18,   KC_F21),
    [LAYER1] = LAYOUT_keymap(
        TT(1),           KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,
        KC_NO,           KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,
        BL_TOGG,         KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO)
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

#ifdef VIA_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LAYER0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER1] = { ENCODER_CCW_CW(BL_DOWN, BL_UP) },
};

#endif
