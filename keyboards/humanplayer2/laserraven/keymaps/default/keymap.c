// Copyright 2025 Rasmus K. Rendsvig (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"

// Layers
enum {
    _BASE  = 0,
    _NAV   = 1,
    _SYM   = 2,
    _NUM   = 3,
    _MOUSE = 4,
};

enum custom_keycodes {
    SCROLL = SAFE_RANGE,
};

// Keycode names:
enum my_keycodes {
  // DK keycodes
  //
DK_AE = KC_SEMICOLON,     // æ
DK_OE = KC_QUOTE,         // ø
DK_AA = KC_LEFT_BRACKET,  // å
  //
DK_AT   = ALGR(KC_2),     // @
DK_DOL  = ALGR(KC_4),     // $
DK_AMPR = S(KC_6),        // &
DK_PIPE = ALGR(KC_EQUAL), // |
DK_SLSH = S(KC_7),        // /
DK_BSLS = ALGR(KC_NUBS),  // \            //
DK_LPRN = S(KC_8),        // (
DK_RPRN = S(KC_9),        // )
DK_LBRC = ALGR(KC_8),     // [
DK_RBRC = ALGR(KC_9),     // ]
DK_LCBR = ALGR(KC_7),     // {
DK_RCBR = ALGR(KC_0),     // }
DK_LABK = KC_NUBS,        // <
DK_RABK = S(KC_NUBS),     // >
DK_QUES = S(KC_MINUS),    // ?
DK_DQUO = S(KC_2),        // "
DK_GRV  = S(KC_EQUAL),    // `
DK_AIGU = KC_EQUAL,       // ´
DK_STAR = S(KC_BSLS),     // *
DK_HAT  = S(KC_RBRC),     // ^
DK_EQUL = S(KC_0),        // =
DK_TILD = ALGR(KC_RBRC),  // ~
DK_PLUS = KC_MINUS,       // +
DK_MNUS = KC_SLSH,        // -
DK_UNSC = S(DK_MNUS),     // _
  //
  // OS Navigation etc.
TAB_LFT = C(KC_PGUP),     // Tab left
TAB_RGT = C(KC_PGDN),     // Tab right
TAB_CLS = C(KC_W),        // Tab close
BACK = A(KC_LEFT),        // Back in browser, file manager
ALT_F4 = G(KC_ESC),       // Close application
WS_UP = KC_P1,            // Workspace up
WS_DN = KC_P5,            // Workspace down
FCS_LFT = KC_P3,          // Focus tile left
FCS_RGT = KC_P7,          // Focus tile right
C_FCS_R = (MT(MOD_RCTL,FCS_RGT)), // Focus tile right, Ctrl for easy text selection with shift
TILE_SM = G(DK_MNUS),     // Decrease tile width
TILE_LG = G(DK_PLUS),     // Increase tile width
TILE_CN = G(KC_C),        // Center on tile
LAUNCHR = G(KC_SPC),      // Open launcher
TERMINL = G(KC_ENT),      // Open terminal
LOCKSCR = G(KC_L),        // Lock screen
  //
  // Shorthands
VOL_UP  = KC_KB_VOLUME_UP,
VOL_DN  = KC_KB_VOLUME_DOWN,
VOL_MU  = KC_KB_MUTE,
COPY    = C(KC_INS),
CUT     = C(KC_X),
PASTE   = S(KC_INS),
UNDO    = C(KC_Z),
__xxx__ = KC_NO,
  //
  // Thumb keys
RM_SPC  = (LT(_NAV,KC_SPACE)),     // Space,  navigation layer
CTL_ESC = (MT(MOD_RCTL,KC_ESC)),   // Escape, control
SH_SPC  = (MT(MOD_RSFT,KC_SPACE)), // Space,  shift
SYM_ENT = (LT(_SYM, KC_ENTER)),    // Enter,  symbols layer
NUM_BT1 = (LT(_NUM, KC_BTN1)),     // Mouse button 1 click also when automouselayer is off, numbers layer if held and no mouse
  //
  // Homerow mods
AL_O = (MT(MOD_LALT,KC_O)),
AL_A = (MT(MOD_LALT,KC_A))
};


// Custom shift keys
const custom_shift_key_t custom_shift_keys[] = {
  {KC_BSLS, DK_DQUO}, // Shift ' is "
  {DK_GRV, DK_AIGU},  // Shift ` is ´
  {KC_HASH, KC_PERC}, // Shift # is %
  {DK_STAR, DK_HAT},  // Shift * is ^
  {DK_SLSH, DK_BSLS}, // Shift / is \                        ---
  {DK_LPRN, DK_RPRN}, // Shift ( is )
  {DK_LBRC, DK_RBRC}, // Shift [ is ]
  {DK_LCBR, DK_RCBR}, // Shift { is }
  {DK_LABK, DK_RABK}, // Shift < is >
  {KC_BTN3, KC_BTN2}, // Mouse button
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


// // Trackpoint scrolling
//    Not need on Linux when keyboard name ends with "Trackpoint"
//
// bool set_scrolling = false;

// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) { // See also https://www.reddit.com/r/qmk/comments/17x74wt/comment/k9ulzqy/
//     if (set_scrolling) {
//         mouse_report.h = mouse_report.x / PS2_MOUSE_X_MULTIPLIER;
//         mouse_report.v = mouse_report.y / PS2_MOUSE_Y_MULTIPLIER;
//         mouse_report.x = 0;
//         mouse_report.y = 0;
//  		   mouse_report.v = -mouse_report.v;
//     }
//     return mouse_report;
// }

// Automatic Mouse Layer
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}


//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    // if (keycode == SCROLL && record->event.pressed) {  //
    // set_scrolling = true;} else {
    // set_scrolling = false;
    // }
    switch (keycode) {
      case RM_SPC | CTL_ESC:
        layer_off(_MOUSE);
        return true;
      }
    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_4x5(
                      KC_TAB , KC_W   , KC_F   , KC_P   , KC_B   ,         KC_J   , KC_L   , KC_U   , KC_Y   , DK_AE  ,
    KC_Z   , KC_Q  ,  AL_A   , KC_R   , KC_S   , KC_T   , KC_G   ,         KC_M   , KC_N   , KC_E   , KC_I   , AL_O   , DK_OE  , DK_AA  ,
                               KC_X   , KC_C   , KC_D   , KC_V   ,         KC_K   , KC_H   , KC_COMM, KC_DOT ,
                                        CTL_ESC, SH_SPC , NUM_BT1,         KC_BTN3, RM_SPC , SYM_ENT
    ),

    [_NAV] = LAYOUT_4x5(
                      ALT_F4 , TAB_LFT, WS_UP   , TAB_RGT, __xxx__,        KC_DEL , KC_HOME, KC_UP  , KC_END , LOCKSCR,
    _______, BACK   , _______, FCS_LFT, WS_DN   , C_FCS_R, __xxx__,        KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______, UNDO   , __xxx__,
                               TILE_SM, TILE_CN , TILE_LG, __xxx__,        KC_APP , COPY   , PASTE  , CUT    ,
                                        _______,  _______, LAUNCHR,        _______, _______, TERMINL
    ),

    [_SYM] = LAYOUT_4x5(
                      KC_BRID, KC_BRIU, VOL_DN , VOL_UP , VOL_MU ,         DK_STAR, KC_HASH,  KC_BSLS, DK_GRV,  __xxx__,
    __xxx__, DK_DOL , DK_AMPR, DK_AT  , DK_QUES, KC_EXLM, DK_PIPE,         DK_SLSH, DK_LPRN,  DK_LBRC, DK_LCBR, DK_LABK, DK_TILD, __xxx__,
                               __xxx__, __xxx__, __xxx__, __xxx__,         DK_PLUS, DK_MNUS,  DK_UNSC, DK_EQUL,
                                        _______, _______, _______,         _______, _______, _______
    ),

    [_NUM] = LAYOUT_4x5(
                      __xxx__, KC_F3  , KC_F2  , KC_F1  , __xxx__,         __xxx__, KC_1   , KC_2   , KC_3   , __xxx__,
    KC_F12 , KC_F11 , KC_F10 , KC_F6  , KC_F5  , KC_F4  , __xxx__,         __xxx__, KC_4   , KC_5   , KC_6   , KC_0   , __xxx__, QK_BOOT,
                               KC_F9  , KC_F8  , KC_F7  , __xxx__,         __xxx__, KC_7   , KC_8   , KC_9   ,
                                        _______, _______, _______,         _______, _______, _______
    ),

    [_MOUSE] = LAYOUT_4x5(
                       _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,        KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______,        _______, _______, _______, _______,
                                         _______, _______, KC_BTN1,        _______, _______, _______
    )
};