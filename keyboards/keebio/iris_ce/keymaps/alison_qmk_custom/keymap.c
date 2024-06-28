// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "defs/tap_dance.c" // this also loads combos and custom keycodes
// #include "defs/handswap.c"
#include "defs/custom_keycodes.c"


// declare all tap dance codes
enum {
    // tap dances for left hand dvorak layout
    DVL_QUL
    , DVL_COMR
    , DVL_DOTC
    , DVL_PG
    , DVL_YF
    , DVL_ID
    , DVL_UH
    , DVL_ET
    , DVL_ON
    , DVL_AS
    , DVL_XB
    , DVL_KM
    , DVL_JW
    , DVL_QV
    , DVL_SCNZ

    // tap-hold tap dances
    , CT_KTAB
    , CT_XESC
    , CT_MTAB
    , CT_BESC

    // complex tap dances
    , TD_CXPZS
    , TD_MUND
    , TD_SENTER
    , TD_SSPACE

};


// DEFINE LAYERS
enum custom_layers {
    _DVORAK
    , _DVORAK_SHIFTED
    , _DV_LEFT
    , _QWERTY
    , _LAYERS
    , _MEDIA
    , _NUMPAD
    , _ARROWS
    , _SYMBOLS
    , _BRACKETS
    , _FN
    //, _KEYBOARD
};





// Define the keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
  //┌──────────────┬──────────────┬───────────┬────────────┬───────────────┬────────────┐                                   ┌───────────┬──────────┬───────────┬─────────┬──────────┬────────────┐
     SH_TOGG,       KC_QUOTE,      KC_COMMA,   KC_DOT,      KC_P,           KC_Y,                                            KC_F,       KC_G,      KC_C,       KC_R,     KC_L,      _______,    
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┤                                   ├───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     KC_BSPC,       HOME_A,        HOME_O,     HOME_E,      HOME_U,         HOME_I,                                          HOME_D,     HOME_H,    HOME_T,     HOME_N,    HOME_S,    KC_MINUS,    
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┤                                   ├───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     TG_LYRS,        KC_SCLN,       KC_Q,       KC_J,       CT_KTAB,        CT_XESC,                                         CT_BESC,    CT_MTAB,   KC_W,       KC_V,     KC_Z,      _______,    
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┼────────────┐        ┌─────────────┼───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     TG_LYRS,       TG_NUM,        TM_BRK,     TD_CXPZS,    _______,       _______,       _______,              TG_NUM,     TD_CXPZS,   _______,   _______,    _______,  _______,   _______,    
  //└──────────────┴──────────────┴───────────┴───┬────────┴───┬───────────┴───┬────────┴───┬────────┘        └───┬─────────┴───┬───────┴───────┬──┴──────────┬──────────┴──────────┴────────────┘
                                                    TG_LYRS,    TMP_SYMB,       TD_SSPACE,                           TD_SENTER,       TG_NUM,        _______
                                               // └────────────┴───────────────┴────────────┘                     └─────────────┴───────────────┴─────────────┘
   )

  , [_DVORAK_SHIFTED] = LAYOUT(
  //┌─────────────────┬────────────────┬───────────────┬─────────────────┬────────────────┬─────────────────┐                                     ┌────────────────┬─────────────────┬───────────────┬─────────────────┬─────────────────┬──────────────┐
     LSFT(KC_TAB),     KC_DQUO,         KC_LABK,        KC_RABK,          LSFT(KC_P),      LSFT(KC_Y),                                              LSFT(KC_F),     LSFT(KC_G),       LSFT(KC_C),      LSFT(KC_R),        LSFT(KC_L),        _______,  
  //├─────────────────┼────────────────┼───────────────┼─────────────────┼────────────────┼─────────────────┤                                     ├────────────────┼─────────────────┼───────────────┼─────────────────┼─────────────────┼──────────────┤
     KC_DELETE,        LSFT(KC_A),      LSFT(KC_O),     LSFT(KC_E),       LSFT(KC_U),      LSFT(KC_I),                                              LSFT(KC_D),     LSFT(KC_H),       LSFT(KC_T),     LSFT(KC_N),        LSFT(KC_S),        KC_UNDS,   
  //├─────────────────┼────────────────┼───────────────┼─────────────────┼────────────────┼─────────────────┤                                     ├────────────────┼─────────────────┼───────────────┼─────────────────┼─────────────────┼──────────────┤
     TMP_FUNC,          KC_COLN,         LSFT(KC_Q),     LSFT(KC_J),       LSFT(KC_K),      LSFT(KC_X),                                              LSFT(KC_B),     LSFT(KC_M),       LSFT(KC_W),      LSFT(KC_V),        LSFT(KC_Z),        _______,  
  //├─────────────────┼────────────────┼───────────────┼─────────────────┼────────────────┼─────────────────┼──────────────┐        ┌─────────────┼────────────────┼─────────────────┼───────────────┼─────────────────┼─────────────────┼──────────────┤
     GO_HOME,          TM_BRK,          _______,        _______,          _______,         _______,          _______,                _______,      _______,         _______,          _______,         _______,           _______,           _______,  
  //└─────────────────┴────────────────┴───────────────┴────────┬────────┴──────┬──────┴───┬────────────────┴┬─────────────┘        └───┬─────────┴─┬─────────────┬─┴─────────────┬──┴───────────────┴─────────────────┴─────────────────┴──────────────┘
                                                                 _______,         _______,       _______,                                 _______,     _______,       _______       
                                                             // └───────────────┴──────────┴─────────────────┘                          └───────────┴─────────────┴───────────────┘
   )

  , [_DV_LEFT] = LAYOUT(
  //┌──────────────┬──────────────┬───────────┬────────────┬───────────────┬────────────┐                                   ┌───────────┬──────────┬───────────┬─────────┬──────────┬────────────┐
     SH_TOGG,       DVL_QUL,       DVL_COMR,   DVL_DOTC,    DVL_PG,         DVL_YF,                                          XXXXXXX,    XXXXXXX,   KC_UP,      XXXXXXX,  XXXXXXX,   XXXXXXX,  
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┤                                   ├───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     KC_BSPC,       DVL_ID,        DVL_UH,     DVL_ET,      DVL_ON,         DVL_AS,                                          XXXXXXX,    KC_LEFT,   KC_DOWN,    KC_RIGHT, KC_LSFT,   KC_LALT,  
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┤                                   ├───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     TG_NUM,        DVL_XB,        DVL_KM,     DVL_JW,      DVL_QV,         DVL_SCNZ,                                        XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,  LSA(KC_TAB), XXXXXXX,   
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┼────────────┐        ┌─────────────┼───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     TG_LYRS,       _______,       _______,    _______,     _______,        _______,     TMP_SYMB,             XXXXXXX,      XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX, 
  //└──────────────┴──────────────┴───────────┴───┬────────┴───┬───────────┴───┬────────┴───┬────────┘        └───┬─────────┴───┬───────┴───────┬──┴──────────┬──────────┴──────────┴────────────┘
                                                    TG_LYRS,     XXXXXXX,       SHFT_SPC,                          XXXXXXX,      XXXXXXX,        XXXXXXX
                                               // └────────────┴───────────────┴────────────┘                     └─────────────┴───────────────┴─────────────┘
   )

  , [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TG_LYRS,          TG_NUM,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, GO_HOME, KC_SPC,                    KC_ENT,  KC_LSFT, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  , [_LAYERS] = LAYOUT(
  //┌──────────────┬──────────────┬──────────────┬──────────────┬───────────────┬────────────┐                                   ┌─────────────┬──────────────┬────────────┬────────────┬─────────────┬────────────┐
     XXXXXXX,       XXXXXXX,       TO(_DV_LEFT),  TO(_SYMBOLS),  TO(_BRACKETS),  XXXXXXX,                                         XXXXXXX,      KC_VOLD,       KC_MUTE,     KC_VOLU,      XXXXXXX,      XXXXXXX,    
  //├──────────────┼──────────────┼──────────────┼──────────────┼───────────────┼────────────┤                                   ├─────────────┼──────────────┼────────────┼────────────┼─────────────┼────────────┤
     XXXXXXX,       TO(_FN),       TO(_QWERTY),   TO(_ARROWS),   TO(_NUMPAD),    XXXXXXX,                                         XXXXXXX,      KC_MPRV,       KC_MNXT,     KC_MPLY,      XXXXXXX,      XXXXXXX,    
  //├──────────────┼──────────────┼──────────────┼──────────────┼───────────────┼────────────┤                                   ├─────────────┼──────────────┼────────────┼────────────┼─────────────┼────────────┤
     XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,                                         XXXXXXX,       KC_BRID,      XXXXXXX,     KC_BRIU,      XXXXXXX,      XXXXXXX,    
  //├──────────────┼──────────────┼──────────────┼──────────────┼───────────────┼────────────┼────────────┐        ┌─────────────┼─────────────┼──────────────┼────────────┼────────────┼─────────────┼────────────┤
     XXXXXXX,       XXXXXXX,       KC_VOLD,       KC_MUTE,       KC_VOLU,        XXXXXXX,     XXXXXXX,              XXXXXXX,      XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,      XXXXXXX,      XXXXXXX,
  //└──────────────┴──────────────┴──────────────┴───┬──────────┴───┬───────────┴───┬────────┴───┬────────┘        └───┬─────────┴─────┬───────┴────────┬─────┴───────────┬─────────────┴─────────────┴────────────┘
                                                      KC_MPRV,       KC_MNXT,        KC_MPLY,                           XXXXXXX,        XXXXXXX,        XXXXXXX
                                                  // └──────────────┴───────────────┴────────────┘                     └───────────────┴───────────────┴─────────────────┘
  )

  , [_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______,                            _______, _______, _______, _______, _______, _______, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,                            _______, _______, _______, _______, _______, _______, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_BRID, _______, KC_BRIU, _______,                            _______, _______, _______, _______, _______, _______, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______ 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  , [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, XXXXXXX,   KC_7,    KC_8,   KC_9,   XXXXXXX,                            XXXXXXX,   KC_7,    KC_8,    KC_9,  XXXXXXX,  XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC,  KC_0,    KC_4,    KC_5,    KC_6,   KC_EQL,                             XXXXXXX,   KC_4,    KC_5,    KC_6,    KC_0,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_DOT,   KC_1,    KC_2,    KC_3,   XXXXXXX,                            XXXXXXX,   KC_1,    KC_2,    KC_3,  XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  , [_ARROWS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_BSPC, XXXXXXX, XXXXXXX,  KC_UP,  XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX,  KC_UP,  XXXXXXX, XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, KC_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX,                            XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LSFT, KC_LALT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, LSA(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, LSA(KC_TAB), XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, LSA(KC_TAB),              RSA(KC_TAB), XXXXXXX, XXXXXXX 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  , [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, KC_CIRC, KC_HASH, KC_ASTR, KC_DLR,                             XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_PIPE, KC_AMPR, KC_PLUS, KC_EXLM, KC_EQL,  KC_PERC,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_AT,   KC_MINUS, KC_GRV, KC_QUES, XXXXXXX,                            XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  , [_BRACKETS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, KC_RCBR, KC_RBRC, KC_RPRN, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_RABK, XXXXXXX, XXXXXXX, X_ESC,   XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  , [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_SLEP, KC_WAKE,  KC_F7,  KC_F8,   KC_F9,   KC_F10,                            BL_TOGG, BL_BRTG, BL_DOWN, BL_UP,   XXXXXXX,  QK_BOOT,  
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC,  XXXXXXX, KC_F4,  KC_F5,   KC_F6,   KC_F11,                            RGB_TOG, RGB_M_B, RGB_M_P, RGB_MOD, RGB_HUI, RGB_VAI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX,  KC_F1,  KC_F2,   KC_F3,   KC_F12,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, GO_HOME,                   XXXXXXX, XXXXXXX, XXXXXXX 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
//   , [_KEYBOARD] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      QK_GESC, XXXXXXX,   KC_F7,  KC_F8,   KC_F9,   KC_F10,                            BL_TOGG, BL_BRTG, BL_DOWN,  BL_UP,  XXXXXXX,  QK_BOOT, 
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      KC_BSPC,  XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,                            RGB_TOG, RGB_M_B, RGB_M_P, RGB_MOD, RGB_HUI, RGB_VAI,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX, XXXXXXX   KC_F1,    KC_F2,  KC_F3,   KC_F12,                            XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPI, RGB_SAI, XXXXXXX, 
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     XXXXXXX, XXXXXXX, GO_HOME,                   XXXXXXX, KC_LSFT, XXXXXXX 
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   )

};



bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    if (!process_select_word(keycode, record, SELECT_WORD)) { return false; }

    tap_dance_action_t *action;
    switch (keycode) {
        case TD(CT_KTAB):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(CT_XESC):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }


    return true;
}


void matrix_scan_user(void) {
    achordion_task();
    select_word_task();
  // Other tasks...
}




/*
Define tap dances
*/


// TD_CXPZS: Copy, Cut, Paste, Save, Undo, Redo
// Create an instance of 'td_tap_t' for the 'cxpzs' tap dance.
static td_tap_t cxpzs_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void cxpzs_finished(tap_dance_state_t *state, void *user_data) {
    cxpzs_state.state = cur_dance(state);
    switch (cxpzs_state.state) {
        case TD_SINGLE_TAP: register_code16(s_copy); break;  // copy 
        case TD_SINGLE_HOLD: register_code16(s_paste); break;  // paste
        case TD_DOUBLE_TAP: register_code16(s_cut); break;  // cut
        case TD_DOUBLE_HOLD: register_code16(s_save); break;  // save
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(s_copy); register_code16(s_paste); break;
        case TD_TRIPLE_TAP: register_code16(s_undo); break;  // undo 
        case TD_TRIPLE_HOLD: register_code16(s_redo); break;  // redo
        default: break;
    }
}
void cxpzs_reset(tap_dance_state_t *state, void *user_data) {
    switch (cxpzs_state.state) {
        case TD_SINGLE_TAP: unregister_code16(s_copy); break;
        case TD_SINGLE_HOLD: unregister_code16(s_paste); break;
        case TD_DOUBLE_TAP: unregister_code16(s_cut); break;
        case TD_DOUBLE_HOLD: unregister_code16(s_save); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(s_paste); break;
        case TD_TRIPLE_TAP: unregister_code16(s_undo); break;
        case TD_TRIPLE_HOLD: unregister_code16(s_redo); break;
        default: break;
    }
    cxpzs_state.state = TD_NONE;
}



// TD_MUND: Minus, underscore, momentary switch to symbols
// Create an instance of 'td_tap_t' for this tap dance.
static td_tap_t mund_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void mund_finished(tap_dance_state_t *state, void *user_data) {
    mund_state.state = cur_dance(state);
    switch (mund_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_MINUS); break;  // copy 
        case TD_SINGLE_HOLD: register_code16(KC_UNDS); break;  // paste
        case TD_DOUBLE_TAP: register_code16(KC_MINUS); break;  // cut
        case TD_DOUBLE_HOLD: register_code16(MO(_SYMBOLS)); break;  // save
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS); break;
        default: break;
    }
}
void mund_reset(tap_dance_state_t *state, void *user_data) {
    switch (mund_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_UNDS); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_MINUS); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_MINUS); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
        default: break;
    }
    mund_state.state = TD_NONE;
}


// TD_SENTER: Shifted dvorak on hold, enter on tap. shift-enter on double tap. 
// Create an instance of 'td_tap_t' for this tap dance.
static td_tap_t  dvsenter_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void dvsenter_finished(tap_dance_state_t *state, void *user_data) {
    dvsenter_state.state = cur_dance(state);
    switch (dvsenter_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_ENT); break;  // copy 
        case TD_SINGLE_HOLD: register_code16(MO(_DVORAK_SHIFTED)); break;  // paste
        case TD_DOUBLE_TAP: register_code16(KC_SPC); break;  // cut
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_ENT)); break;  // save
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_ENT); register_code16(KC_ENT); break;
        case TD_TRIPLE_TAP: register_code16(s_undo); break;  // undo 
        case TD_TRIPLE_HOLD: register_code16(MO(_ARROWS)); break;  // redo
        default: break;
    }
}
void dvsenter_reset(tap_dance_state_t *state, void *user_data) {
    switch (dvsenter_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_ENT); break;
        case TD_SINGLE_HOLD: unregister_code16(MO(_DVORAK_SHIFTED)); break;
        case TD_DOUBLE_TAP: unregister_code16(LSFT(KC_ENT)); break;
        case TD_DOUBLE_HOLD: unregister_code16(s_save); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(s_paste); break;
        case TD_TRIPLE_TAP: unregister_code16(s_undo); break;
        case TD_TRIPLE_HOLD: unregister_code16(MO(_ARROWS)); break;
        default: break;
    }
    dvsenter_state.state = TD_NONE;
}



// TD_SSPACE: Shifted dvorak on hold, enter on tap. shift-enter on double tap. 
// Create an instance of 'td_tap_t' for this tap dance.
static td_tap_t dvsspace_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void dvsspace_finished(tap_dance_state_t *state, void *user_data) {
    dvsspace_state.state = cur_dance(state);
    switch (dvsspace_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_SPC); break;  // copy 
        case TD_SINGLE_HOLD: register_code16(MO(_DVORAK_SHIFTED)); break;  // paste
        case TD_DOUBLE_TAP: register_code16(LSFT(KC_ENT)); break;  // cut
        case TD_DOUBLE_HOLD: register_code16(s_save); break;  // save
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_SPC); register_code16(KC_SPC); break;
        case TD_TRIPLE_TAP: register_code16(s_undo); break;  // undo 
        case TD_TRIPLE_HOLD: register_code16(s_redo); break;  // redo
        default: break;
    }
}
void dvsspace_reset(tap_dance_state_t *state, void *user_data) {
    switch (dvsspace_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_ENT); break;
        case TD_SINGLE_HOLD: unregister_code16(MO(_DVORAK_SHIFTED)); break;
        case TD_DOUBLE_TAP: unregister_code16(LSFT(KC_ENT)); break;
        case TD_DOUBLE_HOLD: unregister_code16(s_save); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(s_paste); break;
        case TD_TRIPLE_TAP: unregister_code16(s_undo); break;
        case TD_TRIPLE_HOLD: unregister_code16(s_redo); break;
        default: break;
    }
    dvsspace_state.state = TD_NONE;
}





// #define SHFT_SPC KC_SPC
// #define SHFT_ENT KC_SPC
// #define DV_SPC KC_SPC
// #define DV_ENT KC_SPC


/*
Define tap dance actions 
*/


// declare tap dance actions
tap_dance_action_t tap_dance_actions[] = {

    // tap-holds for left handed only dvorak layout
    [DVL_QUL] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_L)      
    , [DVL_COMR] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_R)   
    , [DVL_DOTC] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_C)      
    , [DVL_PG] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_G)          
    , [DVL_YF] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_F)
    , [DVL_ID] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_D)
    , [DVL_UH] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_H)
    , [DVL_ET] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_T)
    , [DVL_ON] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_N)
    , [DVL_AS] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_S)
    , [DVL_XB] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_B)
    , [DVL_KM] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_M)
    , [DVL_JW] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_W)
    , [DVL_QV] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_V)
    , [DVL_SCNZ] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_Z)

    // other tap-hold actions
    , [CT_KTAB] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_TAB)
    , [CT_XESC] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_ESC)
    , [CT_MTAB] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_TAB)
    , [CT_BESC] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_ESC)

    // complex tap dances
    , [TD_CXPZS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cxpzs_finished, cxpzs_reset)
    , [TD_MUND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mund_finished, mund_reset)
    , [TD_SENTER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dvsenter_finished, dvsenter_reset)
    , [TD_SSPACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dvsspace_finished, dvsspace_reset)

};





// Combo Definitions
const uint16_t PROGMEM combo_comment[] = { KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM combo_enter_right[] = { KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo_arrows_right[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM combo_brackets_right[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_numpad_right[] = {KC_G, KC_R, COMBO_END};

const uint16_t PROGMEM combo_enter_left[] = {KC_SCLN, KC_J, COMBO_END};
const uint16_t PROGMEM combo_arrows_left[] = {KC_COMM, KC_DOT,  COMBO_END};
const uint16_t PROGMEM combo_numpad_left[] = {KC_COMM, KC_P, COMBO_END};
const uint16_t PROGMEM combo_brackets_left[] = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM combo_lyrs_left[] = {KC_COMM, KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM combo_media_left[] = {KC_DOT, KC_Q, COMBO_END};

const uint16_t PROGMEM combo_layerlock[] = { KC_SCLN, KC_Q, KC_DOT, KC_P, COMBO_END};



combo_t key_combos[] = {
    COMBO(combo_comment, LGUI(KC_SLASH))
    , COMBO(combo_enter_right, KC_ENTER)
    , COMBO(combo_enter_left, KC_ENTER)
    , COMBO(combo_layerlock, LLOCK)
    , COMBO(combo_arrows_right, TO(_ARROWS))
    , COMBO(combo_brackets_right, TO(_BRACKETS))
    , COMBO(combo_numpad_right, TO(_NUMPAD))
    , COMBO(combo_arrows_left, TO(_ARROWS))
    , COMBO(combo_numpad_left, TO(_NUMPAD))
    , COMBO(combo_brackets_left, TO(_BRACKETS))
    , COMBO(combo_lyrs_left, OSL(_LAYERS))
    , COMBO(combo_media_left, OSL(_MEDIA))

};
