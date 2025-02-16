// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define TAPPING_TERM 175
#define PERMISSIVE_HOLD

// Trackpoint: PS/2 in Pointing Devices
// Config also in keyboard.json
// Scrolling with KC_BTN3 works on Linux because board name ends with "Trackpoint"
#define PS2_PIO_USE_PIO1
#define PS2_MOUSE_USE_REMOTE_MODE
#define PS2_MOUSE_INIT_DELAY 500

#define POINTING_DEVICE_ROTATION_180

#define PS2_MOUSE_X_MULTIPLIER 2
#define PS2_MOUSE_Y_MULTIPLIER 2
#define PS2_MOUSE_V_MULTIPLIER 1

// Automatic Mouse Layer:
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_TIME 500
#define AUTO_MOUSE_DEBOUNCE 10 // Amount of mouse movement required to switch layers: minimum 10, default 25