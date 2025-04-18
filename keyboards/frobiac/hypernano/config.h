// Copyright 2023 @frobiac
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef POINTING_DEVICE_DRIVER_PS2_MOUSE
#    define PS2_RESET_PIN B0
#    define PS2_DATA_PIN B1
#    define PS2_CLOCK_PIN B2

#    define POINTING_DEVICE_INVERT_X
#    define POINTING_DEVICE_INVERT_Y

#    define PS2_MOUSE_USE_REMOTE_MODE
#    define PS2_MOUSE_INIT_DELAY 1000
#endif

