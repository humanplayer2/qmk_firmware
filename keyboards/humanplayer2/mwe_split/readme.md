I'm building my first split keyboard using a TRS connection. I have a minimal working example firmware, with which the two halves communicate. It uses `GP0` for `soft_serial_pin` in `keyboard.json`.

I would to use `GP1` for `soft_serial_pin`. When I change it, re-flash both sides, and move my jump wire from `GP0` to `GP1` on both sides, I no longer get output from the non-USB connected side.

I didn't fry `GP1`: it works as a column pin.

Am I missing something in the firmware to be able to use `GP1` instead?

My full MWE firmware is below:


```
rules.mk:

SERIAL_DRIVER = vendor
```



```
config.h:

#pragma once
#define EE_HANDS
```


```
keyboard.json:

{
    "keyboard_name": "mwe_split",
    "manufacturer": "humanplayer2",
    "processor": "RP2040",
    "bootloader": "rp2040",
    "diode_direction": "COL2ROW",
    "usb": {
        "vid": "0x1984",
        "pid": "0x0000",
        "device_version": "1.0.0"
    },
    "split": {
        "enabled": true,
        "soft_serial_pin": "GP0",
        "matrix_pins": {
            "right": {
                "cols": ["GP21"],
                "rows": ["GP9"]
            }
        }
    },
    "matrix_pins": {
        "cols": [ "GP21"],
        "rows": [ "GP9"]
    },
    "layouts": {
        "LAYOUT_1x2": {
            "layout": [
                {"matrix": [0, 0], "x": 0, "y": 0, "label": "left" },
                {"matrix": [1, 0], "x": 0, "y": 1, "label": "right" }
            ]
        }
    }
}
```


```
keymaps/default/keymap.c:

#include QMK_KEYBOARD_H

// Layers
enum {
    _BASE  = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_1x2(
                      KC_L, KC_R
    )
};
```