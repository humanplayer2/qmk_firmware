# Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
# SPDX-License-Identifier: GPL-2.0-or-later

MOUSEKEY_ENABLE = yes

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = ps2_mouse
PS2_DRIVER = usart

# Custom shift keys:
SRC += features/custom_shift_keys.c # https://getreuer.info/posts/keyboards/custom-shift-keys/index.html

# Caps Words:
CAPS_WORD_ENABLE = yes