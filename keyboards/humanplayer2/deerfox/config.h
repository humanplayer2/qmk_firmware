// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EE_HANDS

// Unicode for accent aigu e:
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

// // //
// Trackpoint configuration
// - Uses "PS/2 in Pointing Devices"
// - Pins defined also in keyboard.json
// - Scrolling with KC_BTN3 works on because board name ends with "Trackpoint"
// - Use PIO1 instead of PIO0 as it is used by serial TRRS
#define PS2_PIO_USE_PIO1 // I use this
// - Reset timing
//    With 100kΩ resitor, 2.2 μF capicitor reset circuit,
//    the trackpoint works without additional init delay.
//    But sometimes, it doesn't initiate. Why?
#define PS2_MOUSE_INIT_DELAY 500 // I use this
// - Automatic Mouse Layer:
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE // I use this
#define AUTO_MOUSE_TIME 800 // I use this
#define AUTO_MOUSE_DEBOUNCE 10  // Movement for layer switch: min. 10, def. 25
// - Movement
//    Can turn chunky. I use OS sensitivity instead.
//#define PS2_MOUSE_X_MULTIPLIER 2
//#define PS2_MOUSE_Y_MULTIPLIER 2
//#define PS2_MOUSE_V_MULTIPLIER 2
