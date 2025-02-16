// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"

// Layers
enum {
    _BASE = 0,
    _RMOD = 1,
    _SYM = 2,
    _NUM = 3,
};

enum custom_keycodes {
    SCROLL = SAFE_RANGE,
};

// Keycode names:
enum my_keycodes {
  // DK keycodes
DK_AE = KC_SEMICOLON,
DK_OE = KC_QUOTE,
DK_AA = KC_LEFT_BRACKET,
  //
DK_DQUO = S(KC_2),
DK_AT = ALGR(KC_2),
DK_DOL = ALGR(KC_4),
DK_AMPR = S(KC_6),
DK_SLSH = S(KC_7),
DK_BSLS = ALGR(KC_NUBS),
DK_LPRN = S(KC_8),
DK_RPRN = S(KC_9),
DK_LBRC = ALGR(KC_8),
DK_RBRC = ALGR(KC_9),
DK_LCBR = ALGR(KC_7),
DK_RCBR = ALGR(KC_0),
DK_PLUS = KC_MINUS,
DK_QUES = S(KC_MINUS),
DK_LABK = KC_NUBS,
DK_RABK = S(KC_NUBS),
DK_GRV = S(KC_EQUAL),
DK_AIGU = KC_EQUAL,
DK_HAT = S(KC_RBRC),
DK_EQUAL = S(KC_0),
DK_TILDE = ALGR(KC_RBRC),
DK_PIPE = ALGR(KC_EQUAL),
DK_MINUS = KC_SLSH,
DK_STAR = S(KC_BSLS),
  // Browser navigation
FF_LEFT = C(KC_PGDN),
FF_RGHT = C(KC_PGUP),
FF_BACK = A(KC_LEFT),
FF_CLSE = C(KC_W),
  // Shorthands
VOL_UP = KC_KB_VOLUME_UP,
VOL_DN = KC_KB_VOLUME_DOWN,
VOL_MU = KC_KB_MUTE,
____ = _______,
  //
  // Thumb keys
RCTL_ESC = (MT(MOD_RCTL,KC_ESC)),
SH_SPC = (MT(MOD_RSFT,KC_SPACE)),
RM_SPC = (LT(_RMOD,KC_SPACE)),
SYM_ENT = (LT(_SYM, KC_ENTER)),
NM_F = (LT(_NUM, KC_F)),
NM_U = (LT(_NUM, KC_U)),
  //
  // Other layers
RCTL_P7 = (MT(MOD_RCTL,KC_P7)), // right index ctrl
AL_O = (MT(MOD_LALT,KC_O)),
AL_A = (MT(MOD_LALT,KC_A))
};


// Custom shift keys
const custom_shift_key_t custom_shift_keys[] = {
  {KC_BSLS, DK_DQUO}, // Shift ' is "
  {DK_GRV, DK_AIGU},  // Shift ` is ´
  {KC_HASH, KC_PERC}, // Shift # is %
  {DK_STAR, DK_DOL},  // Shift * is $
  {DK_SLSH, DK_BSLS}, // Shift / is \ .
  {DK_LPRN, DK_RPRN}, // Shift ( is )
  {DK_LBRC, DK_RBRC}, // Shift [ is ]
  {DK_LCBR, DK_RCBR}, // Shift { is }
  {DK_LABK, DK_RABK}, // Shift < is >
  {KC_BTN3, KC_BTN2}, // Mouse button
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


bool set_scrolling = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) { // See also https://www.reddit.com/r/qmk/comments/17x74wt/comment/k9ulzqy/
    if (set_scrolling) {
        mouse_report.h = mouse_report.x / PS2_MOUSE_X_MULTIPLIER;
        mouse_report.v = mouse_report.y / PS2_MOUSE_Y_MULTIPLIER;
        mouse_report.x = 0;
        mouse_report.y = 0;
		    mouse_report.v = -mouse_report.v;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    if (keycode == SCROLL && record->event.pressed) {
    set_scrolling = true;} else {
    set_scrolling = false;
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_4x5(
                    KC_Q, KC_W, NM_F, KC_P, KC_B,    KC_J, KC_L, NM_U, KC_Y, KC_Z,
     KC_TAB, DK_OE, AL_A, KC_R, KC_S, KC_T, KC_G,    KC_M, KC_N, KC_E, KC_I, AL_O, DK_AE, DK_AA,
                          KC_X, KC_C, KC_D, KC_V,    KC_K, KC_H, KC_COMMA, KC_DOT,
                        RCTL_ESC, SH_SPC, KC_BTN1,   SCROLL, RM_SPC, SYM_ENT
        ),

    [_RMOD] = LAYOUT_4x5(
                       G(KC_ESC), C(KC_PGUP), KC_P1,  C(KC_PGDN), C(KC_W),     KC_DEL,  KC_HOME,   KC_UP,     KC_END,   G(KC_L),
     ____, A(KC_LEFT), ____,      KC_P3,      KC_P5,  RCTL_P7,    C(KC_T),     KC_BSPC, KC_LEFT,   KC_DOWN,   KC_RIGHT, ____, C(KC_Z), ____,
                                 G(DK_MINUS),G(KC_C), G(DK_PLUS), ____,        KC_APP,  C(KC_INS), S(KC_INS), C(KC_X),
                                             ____,    ____,      G(KC_SPC),    ____,    ____,      G(KC_ENT)
        ),

    [_SYM] = LAYOUT_4x5(
                   KC_BRID, KC_BRIU, VOL_DN,  VOL_UP,   VOL_MU,         DK_STAR, KC_HASH,  KC_BSLS,     DK_GRV,  ____,
     ____, DK_HAT, DK_AMPR, DK_AT,   DK_QUES,  KC_EXLM, DK_PIPE,        DK_SLSH, DK_LPRN,  DK_LBRC,     DK_LCBR, DK_LABK, DK_TILDE, ____,
                            ____,    ____,     ____,    ____,           DK_PLUS, DK_MINUS, S(DK_MINUS), DK_EQUAL,
                                               ____, ____, ____,        ____, ____, ____
        ),

    [_NUM] = LAYOUT_4x5(
                     ____,   KC_F3,  KC_F2,  KC_F1,  ____,    ____, KC_1, KC_2, KC_3, ____,
     KC_F12, KC_F11, KC_F10, KC_F6,  KC_F5,  KC_F4,  ____,    ____, KC_4, KC_5, KC_6, KC_0, ____, QK_BOOT,
                             KC_F9,  KC_F8,  KC_F7,  ____,    ____, KC_7, KC_8, KC_9,
                                         ____, ____, ____,    ____, ____, ____
        )
};