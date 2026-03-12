// Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Trackpoint: PS/2 in Pointing Devices
// Config also in keyboard.json
// Scrolling with KC_BTN3 works on Linux because board name ends with "Trackpoint"

// Use PIO1 instead of PIO0 as it is used by serial TRRS
#define PS2_PIO_USE_PIO1

// With 100kΩ resitor, 2.2 μF capicitor reset circuit,
// the trackpoint works without additional init delay.
// #define PS2_MOUSE_INIT_DELAY 500