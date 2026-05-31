# Copyright 2026 Rasmus K. Rendsvig (@humanplayer2)
# SPDX-License-Identifier: GPL-2.0-or-later

SERIAL_DRIVER = vendor

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = ps2_mouse

UNICODEMAP_ENABLE = yes
 
SRC += features/custom_shift_keys.c
