// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define TAPPING_TERM 175
#define PERMISSIVE_HOLD

// Trackpoint
#define PS2_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the PS2 implementation uses the PIO0 peripheral
#define PS2_MOUSE_USE_REMOTE_MODE
#define PS2_MOUSE_INIT_DELAY 500

#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y

#define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_MIDDLE)
#define PS2_MOUSE_SCROLL_BTN_SEND 300

#define PS2_MOUSE_X_MULTIPLIER 2
#define PS2_MOUSE_Y_MULTIPLIER 2
#define PS2_MOUSE_V_MULTIPLIER 1