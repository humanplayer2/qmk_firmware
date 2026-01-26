# Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
# SPDX-License-Identifier: GPL-2.0-or-later

# Custom shift keys
# https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
SRC += features/custom_shift_keys.c

# 
# https://getreuer.info/posts/keyboards/non-english/index.html
UNICODEMAP_ENABLE = yes

SERIAL_DRIVER = vendor
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = ps2_mouse