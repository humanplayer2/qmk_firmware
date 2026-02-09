// Copyright 2025-2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Side controlled by eeprom:
#define EE_HANDS

// Unicode for accent aigu e:
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

// Trackpoint: Uses PS/2 in Pointing Devices PR: github.com/qmk/qmk_firmware/pull/22532
// Some configuration is also in keyboard.json
// Scrolling with KC_BTN3 works on Linux because board name ends with "Trackpoint"
#define PS2_PIO_USE_PIO1
#define PS2_MOUSE_INIT_DELAY 500

#define POINTING_DEVICE_ROTATION_180

// #define PS2_MOUSE_X_MULTIPLIER 2
// #define PS2_MOUSE_Y_MULTIPLIER 2
// #define PS2_MOUSE_V_MULTIPLIER 1

// Do not use: causes that non-mouse side keys must be held to send
// #define PS2_MOUSE_USE_REMOTE_MODE

// Automatic Mouse Layer:
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_TIME 800
#define AUTO_MOUSE_DEBOUNCE 10 // Amount of mouse movement required to switch layers: minimum 10, default 25
