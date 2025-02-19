// Copyright 2023 @frobiac
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef POINTING_DEVICE_DRIVER_PS2_MOUSE
#    define PS2_DATA_PIN D4
#    define PS2_CLOCK_PIN B3

#    define PS2_MOUSE_USE_REMOTE_MODE
#    define PS2_MOUSE_INIT_DELAY 1000
#endif
