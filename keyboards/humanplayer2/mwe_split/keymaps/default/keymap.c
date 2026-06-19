// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum {
    _BASE  = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_1x2(
                      KC_L, KC_R
    )
};