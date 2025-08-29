// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum {
    _BASE  = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
            KC_A, KC_B, KC_C, KC_D, 
            KC_E, KC_F, KC_G, KC_H, 
            KC_I, KC_J, KC_K, KC_L, 
            KC_M, KC_N, KC_O, KC_P 
    )
};