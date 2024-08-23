// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "defs/tap_dance.c" // this also loads combos and custom keycodes
// #include "defs/handswap.c"
#include "defs/custom_keycodes.c"


// declare all tap dance codes
enum {
    // tap dances for left hand dvorak layout
    DVL_QUL = 0
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
    , CT_BESC
    , CT_MTAB

    // complex tap dances
    , TD_CXPZS
    , TD_MUND
    , TD_SENTER
    , TD_SSPACE
    , TD_SPCDOT
    , TD_SSPACEC
    , TD_SENTERC


};


// DEFINE LAYERS
enum custom_layers {
      _DVORAK
   //  , _DVORAK_SHIFTED
    , _DV_LEFT
    , _QWERTY
    , _LAYERS
    , _MEDIA
    , _NUMPAD
    , _ARROWS
    , _SYMBOLS
    , _BRACKETS
    , _FN
    , _SHORTCUTS
    //, _KEYBOARD
};



#define CXPZS TD(TD_CXPZS)
#define SPACEDANCE TD(TD_SSPACEC)
#define ENTDANCE TD(TD_SENTERC)
#define SPCDOT TD(TD_SPCDOT)
#define KTAB TD(CT_KTAB)
#define XESC TD(CT_XESC)
#define BESC TD(CT_BESC)
#define MTAB TD(CT_MTAB)


// Define the keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
  //┌──────────────┬──────────────┬───────────┬────────────┬───────────────┬────────────┐                                   ┌───────────┬──────────┬───────────┬─────────┬──────────┬────────────┐
     QK_GESC,       KC_QUOTE,      KC_COMMA,   KC_DOT,      KC_P,           KC_Y,                                            KC_F,       KC_G,      KC_C,       KC_R,     KC_L,      BSP_DEL,    
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┤                                   ├───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     BSP_DEL,       HOME_A,        HOME_O,     HOME_E,      HOME_U,         HOME_I,                                          HOME_D,     HOME_H,    HOME_T,     HOME_N,    HOME_S,    TD(TD_MUND),    
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┤                                   ├───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     TG_NUM,        KC_SCLN,       KC_Q,       KC_J,        KTAB,           XESC,                                            BESC,       MTAB,       KC_W,       KC_V,     KC_Z,      MO_BRK,
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┼────────────┐        ┌─────────────┼───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     TG_LYRS,       MO_ARR,        TMP_BRK,      CXPZS,      XXXXXXX,       XXXXXXX,    TMP_SYM,               TG_NUM,      CXPZS,       XXXXXXX,   XXXXXXX,   XXXXXXX,   TMP_SYM,   TG_LYRS,    
  //└──────────────┴──────────────┴───────────┴───┬────────┴───┬───────────┴───┬────────┴───┬────────┘        └───┬─────────┴───┬───────┴───────┬──┴──────────┬──────────┴──────────┴────────────┘
                                                    TG_LYRS,    SPACEDANCE,       ENTDANCE,                        MO_ARR,       ENTDANCE,       XXXXXXX
                                               // └────────────┴───────────────┴────────────┘                     └─────────────┴───────────────┴─────────────┘
   )

//   , [_DVORAK_SHIFTED] = LAYOUT(
//   //┌─────────────────┬────────────────┬───────────────┬─────────────────┬────────────────┬─────────────────┐                                     ┌────────────────┬─────────────────┬───────────────┬─────────────────┬─────────────────┬──────────────┐
//      LSFT(KC_TAB),     KC_DQUO,         KC_LABK,        KC_RABK,          LSFT(KC_P),      LSFT(KC_Y),                                              LSFT(KC_F),     LSFT(KC_G),       LSFT(KC_C),      LSFT(KC_R),        LSFT(KC_L),        _______,  
//   //├─────────────────┼────────────────┼───────────────┼─────────────────┼────────────────┼─────────────────┤                                     ├────────────────┼─────────────────┼───────────────┼─────────────────┼─────────────────┼──────────────┤
//      KC_DELETE,        LSFT(KC_A),      LSFT(KC_O),     LSFT(KC_E),       LSFT(KC_U),      LSFT(KC_I),                                              LSFT(KC_D),     LSFT(KC_H),       LSFT(KC_T),     LSFT(KC_N),        LSFT(KC_S),      KC_UNDERSCORE,   
//   //├─────────────────┼────────────────┼───────────────┼─────────────────┼────────────────┼─────────────────┤                                     ├────────────────┼─────────────────┼───────────────┼─────────────────┼─────────────────┼──────────────┤
//      TMP_FUNC,          KC_COLN,         LSFT(KC_Q),     LSFT(KC_J),       LSFT(KC_K),      LSFT(KC_X),                                              LSFT(KC_B),     LSFT(KC_M),       LSFT(KC_W),      LSFT(KC_V),        LSFT(KC_Z),        _______,  
//   //├─────────────────┼────────────────┼───────────────┼─────────────────┼────────────────┼─────────────────┼──────────────┐        ┌─────────────┼────────────────┼─────────────────┼───────────────┼─────────────────┼─────────────────┼──────────────┤
//      GO_HOME,          TM_BRK,          _______,        _______,          _______,         _______,          _______,                _______,      _______,         _______,          _______,         _______,           _______,           _______,  
//   //└─────────────────┴────────────────┴───────────────┴────────┬────────┴──────┬──────┴───┬────────────────┴┬─────────────┘        └───┬─────────┴─┬─────────────┬─┴─────────────┬──┴───────────────┴─────────────────┴─────────────────┴──────────────┘
//                                                                  _______,         _______,       _______,                                 _______,     _______,       _______       
//                                                              // └───────────────┴──────────┴─────────────────┘                          └───────────┴─────────────┴───────────────┘
//    )

  , [_DV_LEFT] = LAYOUT(
  //┌──────────────┬──────────────┬───────────┬────────────┬───────────────┬────────────┐                                   ┌───────────┬──────────┬───────────┬─────────┬──────────┬────────────┐
     QK_GESC,       TD(DVL_QUL),  TD(DVL_COMR),TD(DVL_DOTC), TD(DVL_PG),    TD(DVL_YF),                                       XXXXXXX,    XXXXXXX,   KC_UP,      XXXXXXX,  XXXXXXX,   XXXXXXX,  
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┤                                   ├───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     KC_BSPC,       TD(DVL_ID),   TD(DVL_UH),  TD(DVL_ET),   TD(DVL_ON),    TD(DVL_AS),                                       XXXXXXX,    KC_LEFT,   KC_DOWN,    KC_RIGHT, KC_LSFT,   KC_LALT,  
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┤                                   ├───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     _______,       TD(DVL_XB),   TD(DVL_KM),  TD(DVL_JW),   TD(DVL_QV),    TD(DVL_SCNZ),                                     XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,  LSA(KC_TAB), XXXXXXX,   
  //├──────────────┼──────────────┼───────────┼────────────┼───────────────┼────────────┼────────────┐        ┌─────────────┼───────────┼──────────┼───────────┼─────────┼──────────┼────────────┤
     _______,       _______,       _______,    _______,     _______,        _______,     _______,              XXXXXXX,      XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,   _______, 
  //└──────────────┴──────────────┴───────────┴───┬────────┴───┬───────────┴───┬────────┴───┬────────┘        └───┬─────────┴───┬───────┴───────┬──┴──────────┬──────────┴──────────┴────────────┘
                                                    _______,     _______,        _______,                          XXXXXXX,      XXXXXXX,        XXXXXXX
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
     TG_LYRS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    GO_HOME,          TG_NUM,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_LSFT, KC_SPC,                    KC_ENT,  KC_LSFT, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  , [_LAYERS] = LAYOUT(
  //┌──────────────┬──────────────┬──────────────┬──────────────┬───────────────┬────────────┐                                   ┌─────────────┬──────────────┬────────────┬────────────┬─────────────┬────────────┐
     XXXXXXX,       XXXXXXX,       TO(_DV_LEFT),  TO(_SYMBOLS),  TO(_BRACKETS),  XXXXXXX,                                         XXXXXXX,      KC_VOLD,       KC_MUTE,     KC_VOLU,      XXXXXXX,      XXXXXXX,    
  //├──────────────┼──────────────┼──────────────┼──────────────┼───────────────┼────────────┤                                   ├─────────────┼──────────────┼────────────┼────────────┼─────────────┼────────────┤
     XXXXXXX,       XXXXXXX,       TO(_QWERTY),   TO(_ARROWS),   TO(_NUMPAD),    TO(_FN),                                         XXXXXXX,      KC_MPRV,       KC_MNXT,     KC_MPLY,      XXXXXXX,      XXXXXXX,    
  //├──────────────┼──────────────┼──────────────┼──────────────┼───────────────┼────────────┤                                   ├─────────────┼──────────────┼────────────┼────────────┼─────────────┼────────────┤
     XXXXXXX,       XXXXXXX,       KC_VOLD,       KC_MUTE,       KC_VOLU,        XXXXXXX,                                         XXXXXXX,      KC_BRID,       XXXXXXX,     KC_BRIU,      XXXXXXX,      XXXXXXX,    
  //├──────────────┼──────────────┼──────────────┼──────────────┼───────────────┼────────────┼────────────┐        ┌─────────────┼─────────────┼──────────────┼────────────┼────────────┼─────────────┼────────────┤
     XXXXXXX,       XXXXXXX,       KC_MPRV,       KC_MNXT,       KC_MPLY,        XXXXXXX,     XXXXXXX,              XXXXXXX,      XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,      XXXXXXX,      XXXXXXX,
  //└──────────────┴──────────────┴──────────────┴───┬──────────┴───┬───────────┴───┬────────┴───┬────────┘        └───┬─────────┴─────┬───────┴────────┬─────┴───────────┬─────────────┴─────────────┴────────────┘
                                                      _______,       XXXXXXX,        XXXXXXX,                           XXXXXXX,        XXXXXXX,        XXXXXXX
                                                  // └──────────────┴───────────────┴────────────┘                     └───────────────┴───────────────┴─────────────────┘
  )

  , [_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______,                             BL_TOGG, BL_BRTG, BL_DOWN,  BL_UP,  XXXXXXX,  XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,                             RGB_TOG, RGB_M_B, RGB_M_P, RGB_MOD, RGB_HUI, RGB_VAI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_BRID, _______, KC_BRIU, _______,                              XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPI, RGB_SAI, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    XXXXXXX, KC_LSFT, XXXXXXX 
                                // └────────┴────────┴────────┘                  └────────┴────────┴────────┘
  )

  , [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, XXXXXXX,   KC_7,   KC_8,   KC_9,   XXXXXXX,                          XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC,  KC_0,    KC_4,    KC_5,    KC_6,   KC_EQL,                          XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, SC_LSPO, SC_RAPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, SPCDOT,   KC_1,    KC_2,    KC_3,   XXXXXXX,                          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, LSA(KC_TAB), XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GO_HOME, XXXXXXX, XXXXXXX, KC_DOT,  KC_0,    RSA(KC_TAB), XXXXXXX,       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘     └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, SPACEDANCE,ENTDANCE,             RSA(KC_TAB),  ENTDANCE, XXXXXXX 
                                // └────────┴────────┴────────┘              └────────┴────────┴────────┘
  )

  , [_ARROWS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐   
     KC_BSPC, XXXXXXX, KC_END,  KC_UP,  KC_HOME, XXXXXXX,                             XXXXXXX,   KC_7,    KC_8,    KC_9,  XXXXXXX,  XXXXXXX,   
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤   
     SC_LAPO, SC_RSPC, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX,                            XXXXXXX,   KC_4,    KC_5,    KC_6,    KC_0,   KC_BSPC,   
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤   
     _______, LSA(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                       XXXXXXX,   KC_1,    KC_2,    KC_3,  SPCDOT, XXXXXXX,    
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤   
     GO_HOME, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, RSA(KC_TAB), KC_DOT, KC_0,  XXXXXXX, XXXXXXX,    
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘   
                                    XXXXXXX, SPACEDANCE,ENTDANCE,                _______,  ENTDANCE, XXXXXXX                                     
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘                                   
  )

//   , [_NUMPAD] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      QK_GESC, XXXXXXX,   KC_7,    KC_8,   KC_9,   XXXXXXX,                            XXXXXXX,   KC_7,    KC_8,    KC_9,  XXXXXXX,  XXXXXXX, 
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      KC_BSPC,  KC_0,    KC_4,    KC_5,    KC_6,   KC_EQL,                             XXXXXXX,   KC_4,    KC_5,    KC_6,    KC_0,   KC_BSPC,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX, KC_DOT,   KC_1,    KC_2,    KC_3,   XXXXXXX,                            XXXXXXX,   KC_1,    KC_2,    KC_3,  XXXXXXX, XXXXXXX, 
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     XXXXXXX, XXXXXXX, XXXXXXX,                   _______, XXXXXXX, XXXXXXX 
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   )

//   , [_ARROWS] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      KC_BSPC, XXXXXXX, XXXXXXX,  KC_UP,  XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX,  KC_UP,  XXXXXXX, XXXXXXX, XXXXXXX, 
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      KC_LALT, KC_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX,                            XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LSFT, KC_LALT,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX, LSA(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, LSA(KC_TAB), XXXXXXX, 
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     XXXXXXX, _______, _______,                  RSA(KC_TAB), _______, XXXXXXX 
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   )

  , [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, KC_CIRC, KC_HASH, KC_ASTR, KC_DLR,                             KC_DLR,KC_GRV, KC_ASTR, KC_HASH, KC_MINUS,  KC_BSLS, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_PIPE, KC_AMPR, KC_PLUS, KC_EXLM, KC_EQL,  KC_PERC,                            XXXXXXX, KC_QUES, KC_EQL, KC_EXLM, KC_PLUS, KC_UNDS, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_AT,   KC_MINUS, KC_GRV, KC_QUES, XXXXXXX,                            XXXXXXX ,KC_PERC, KC_AMPR, KC_PIPE, KC_AT, KC_SLSH, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  , [_BRACKETS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, KC_RCBR, KC_RBRC, KC_RPRN, XXXXXXX,                            XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX,                            XXXXXXX, KC_LPRN, KC_LBRC, KC_LCBR, KC_LABK, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_RABK, XXXXXXX, XXXXXXX, X_ESC,   XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RABK, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

//   , [_BRACKETS] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      XXXXXXX, XXXXXXX, KC_RCBR, KC_RBRC, KC_RPRN, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      KC_BSPC, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX, KC_RABK, XXXXXXX, XXXXXXX, X_ESC,   XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   )

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

  , [_SHORTCUTS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GO_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

//   , [_KEYBOARD] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      QK_GESC, XXXXXXX,   KC_F7,  KC_F8,   KC_F9,   KC_F10,                            BL_TOGG, BL_BRTG, BL_DOWN,  BL_UP,  XXXXXXX,  QK_BOOT, 
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      KC_BSPC,  XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,                            RGB_TOG, RGB_M_B, RGB_M_P, RGB_MOD, RGB_HUI, RGB_VAI,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX, XXXXXXX,   KC_F1,    KC_F2,  KC_F3,   KC_F12,                            XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPI, RGB_SAI, XXXXXXX, 
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
         case TD(CT_XESC):  
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }
         case TD(CT_MTAB):  
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }
         case TD(CT_BESC):  
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }
      
         // https://github.com/walkerstop/qmk_firmware/blob/fanoe/keyboards/wheatfield/blocked65/keymaps/walker/keymap.c
         case KC_TRNS:
         case KC_NO:
            /* Always cancel one-shot layer when another key gets pressed */
            if (record->event.pressed && is_oneshot_layer_active())
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            return true;
         case RESET:
            /* Don't allow reset from oneshot layer state */
            if (record->event.pressed && is_oneshot_layer_active()){
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            return false;
            }	
            return true;

         case BSP_DEL:
            if (record->event.pressed) {
                saved_mods = get_mods();

                if (saved_mods) {  // One shift pressed
                    del_mods(saved_mods); // Remove any Shifts present
                    register_code(KC_DEL);
                    add_mods(saved_mods); // Add shifts again
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
            }
            return false;

         default:
            return true;
  }

    return true;
}


void matrix_scan_user(void) {
   #ifdef ACHORDION_ENABLE
    achordion_task();
   #endif
    select_word_task();
    layer_lock_task();

}




/*
Define tap dances
*/


// TD_CXPZS: Copy, Cut, Paste, Save, Undo, Redo
static td_tap_t cxpzs_state = {
    .is_press_action = true,
    .state = TD_NONE
};
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
void cxpzs_finished(tap_dance_state_t *state, void *user_data) {
    cxpzs_state.state = cur_dance(state);
    switch (cxpzs_state.state) {
        case TD_SINGLE_TAP: register_code16(s_copy); break;  // copy 
        case TD_SINGLE_HOLD: register_code16(s_cut); break;  // paste
        case TD_DOUBLE_TAP: register_code16(s_paste); break;  // cut
        case TD_DOUBLE_HOLD: register_code16(s_undo); break;  // save
        case TD_DOUBLE_SINGLE_TAP: tap_code16(s_copy); register_code16(s_paste); break;
        case TD_TRIPLE_TAP: register_code16(s_save); break;  // undo 
        case TD_TRIPLE_HOLD: register_code16(s_redo); break;  // redo
        default: break;
    }
}
void cxpzs_reset(tap_dance_state_t *state, void *user_data) {
    switch (cxpzs_state.state) {
        case TD_SINGLE_TAP: unregister_code16(s_copy); break;
        case TD_SINGLE_HOLD: unregister_code16(s_cut); break;
        case TD_DOUBLE_TAP: unregister_code16(s_paste); break;
        case TD_DOUBLE_HOLD: unregister_code16(s_undo); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(s_paste); break;
        case TD_TRIPLE_TAP: unregister_code16(s_save); break;
        case TD_TRIPLE_HOLD: unregister_code16(s_redo); break;
        default: break;
    }
    cxpzs_state.state = TD_NONE;
}

// TD_MUND: Minus, underscore, momentary switch to symbols
static td_tap_t mund_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void mund_finished(tap_dance_state_t *state, void *user_data) {
    mund_state.state = cur_dance(state);
    switch (mund_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_MINUS); break;  // copy 
        case TD_SINGLE_HOLD: register_code16(KC_UNDERSCORE); break;  // paste
        case TD_DOUBLE_TAP: register_code16(KC_UNDERSCORE); break;  // cut
        case TD_DOUBLE_HOLD: register_code16(MO(_SYMBOLS)); break;  // save
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS); break;
        default: break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
    }
}
void mund_reset(tap_dance_state_t *state, void *user_data) {
    switch (mund_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_UNDERSCORE); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_UNDERSCORE); break;
        case TD_DOUBLE_HOLD: unregister_code16(_SYMBOLS); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
        default: break;
    }
    mund_state.state = TD_NONE;
}

// TD_SENTER: Shift on hold, enter on tap. shift-enter on double tap. 
static td_tap_t  dvsenter_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void dvsenter_finished(tap_dance_state_t *state, void *user_data) {
    dvsenter_state.state = cur_dance(state);
    switch (dvsenter_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_ENTER); break;  
        case TD_SINGLE_HOLD: register_code16(KC_LSFT); break;  
        case TD_DOUBLE_TAP: register_code16(KC_SPACE); break;  
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_ENTER)); break;  
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case TD_TRIPLE_TAP: register_code16(s_undo); break;  
        case TD_TRIPLE_HOLD: register_code16(MO(_ARROWS)); break;  
        default: break;
    }
}
void dvsenter_reset(tap_dance_state_t *state, void *user_data) {
    switch (dvsenter_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_SPACE); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case TD_TRIPLE_TAP: unregister_code16(s_undo); break;
        case TD_TRIPLE_HOLD: unregister_code16(MO(_ARROWS)); break;
        default: break;
    }
    dvsenter_state.state = TD_NONE;
}

// TD_SSPACE: Shift on hold, enter on tap. shift-enter on double tap. 
static td_tap_t dvsspace_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void dvsspace_finished(tap_dance_state_t *state, void *user_data) {
    dvsspace_state.state = cur_dance(state);
    switch (dvsspace_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_SPACE); break;  
        case TD_SINGLE_HOLD: register_code16(KC_LSFT); break;  
        case TD_DOUBLE_TAP: register_code16(KC_ENTER); break;  
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_ENTER)); break;  
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE); break;
        case TD_TRIPLE_TAP: register_code16(KC_LPRN); break;  
        case TD_TRIPLE_HOLD: register_code16(MO(_ARROWS)); break;  
        default: break;
    }
}
void dvsspace_reset(tap_dance_state_t *state, void *user_data) {
    switch (dvsspace_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case TD_TRIPLE_TAP: unregister_code16(KC_LPRN); break;
        case TD_TRIPLE_HOLD: unregister_code16(MO(_ARROWS)); break;
        default: break;
    }
    dvsspace_state.state = TD_NONE;
}

// TD_SDOTCOM: Shifted dvorak on hold, enter on tap. shift-enter on double tap. 
static td_tap_t sdotcom_state = {  // Create an instance of 'td_tap_t' for this tap dance.
    .is_press_action = true,
    .state = TD_NONE
};
void sdotcom_finished(tap_dance_state_t *state, void *user_data) {
    sdotcom_state.state = cur_dance(state);
    switch (sdotcom_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_DOT); break;  
        case TD_SINGLE_HOLD: register_code16(KC_COMMA); break;  
        case TD_DOUBLE_TAP: register_code16(KC_SPACE); break;  
        case TD_DOUBLE_HOLD: set_oneshot_layer(_SYMBOLS, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break; 
      //   case TD_DOUBLE_HOLD: register_code16(TO(_SYMBOLS)); break;  
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT); break;

        default: break;
    }
}
void sdotcom_reset(tap_dance_state_t *state, void *user_data) {
    switch (sdotcom_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_DOT); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_COMMA); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_SPACE); break;
        case TD_DOUBLE_HOLD: break;
      //   case TD_DOUBLE_HOLD: unregister_code16(LSFT(TO(_SYMBOLS))); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
        default: break;
    }
    sdotcom_state.state = TD_NONE;
}

// TD_ENTLYR: Shifted dvorak on hold, enter on tap. shift-enter on double tap. 
static td_tap_t  entlyr_state = {  // Create an instance of 'td_tap_t' for this tap dance.
    .is_press_action = true,
    .state = TD_NONE
};
void entlyr_finished(tap_dance_state_t *state, void *user_data) {
    entlyr_state.state = cur_dance(state);
    switch (entlyr_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_ENTER); break;  
        case TD_SINGLE_HOLD: register_code16(MO(_ARROWS)); break;  
        case TD_DOUBLE_TAP: register_code16(KC_SPACE); break;  
        case TD_DOUBLE_HOLD: register_code16(MO(_LAYERS)); break;  
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case TD_TRIPLE_TAP: register_code16(OSL(_BRACKETS)); break;  
        case TD_TRIPLE_HOLD: register_code16(MO(_ARROWS)); break;  
        default: break;
    }
}
void entlyr_reset(tap_dance_state_t *state, void *user_data) {
    switch (entlyr_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case TD_SINGLE_HOLD: unregister_code16(MO(_ARROWS)); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_SPACE); break;
        case TD_DOUBLE_HOLD: unregister_code16(MO(_LAYERS)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case TD_TRIPLE_TAP: unregister_code16(OSL(_BRACKETS)); break;
        case TD_TRIPLE_HOLD: unregister_code16(MO(_ARROWS)); break;
        default: break;
    }
    entlyr_state.state = TD_NONE;
}

// TD_SSPACEC: Shifted dvorak layer on hold, enter on tap. shift-enter on double tap.
static td_tap_t sspacec_state = {   
// Create an instance of 'td_tap_t' for this tap dance.
    .is_press_action = true,
    .state = TD_NONE
};
void sspacec_finished(tap_dance_state_t *state, void *user_data) {
    sspacec_state.state = cur_dance(state);
    switch (sspacec_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_SPC); break;  
        case TD_SINGLE_HOLD: register_code16(MO(_DVORAK_SHIFTED)); break;  
        case TD_DOUBLE_TAP: register_code16(KC_ENTER); break;  
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_ENTER)); break;  
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_SPC); register_code16(KC_SPC); break;
        case TD_TRIPLE_TAP: register_code16(KC_LPRN); break;  
        case TD_TRIPLE_HOLD: register_code16(KC_RIGHT); break;  
        default: break;
    }
}
void sspacec_reset(tap_dance_state_t *state, void *user_data) {
    switch (sspacec_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_SPC); break;
        case TD_SINGLE_HOLD: unregister_code16(MO(_DVORAK_SHIFTED)); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_SPC); break;
        case TD_TRIPLE_TAP: unregister_code16(KC_LPRN); break;
        case TD_TRIPLE_HOLD: unregister_code16(KC_RIGHT); break;
        default: break;
    }
    sspacec_state.state = TD_NONE;
}

// TD_SENTERC: Shifted dvorak on hold, enter on tap. shift-enter on double tap.  
static td_tap_t  senterc_state = {  
// Create an instance of 'td_tap_t' for this tap dance.
    .is_press_action = true,
    .state = TD_NONE
};
void senterc_finished(tap_dance_state_t *state, void *user_data) {
    senterc_state.state = cur_dance(state);
    switch (senterc_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_ENTER); break;  
        case TD_SINGLE_HOLD: register_code16(MO(_DVORAK_SHIFTED)); break;  
        case TD_DOUBLE_TAP: register_code16(KC_SPACE); break;  
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_ENTER)); break;  
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case TD_TRIPLE_TAP: register_code16(s_undo); break;  
        case TD_TRIPLE_HOLD: register_code16(MO(_ARROWS)); break;  
        default: break;
    }
}
void senterc_reset(tap_dance_state_t *state, void *user_data) {
    switch (senterc_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case TD_SINGLE_HOLD: unregister_code16(MO(_DVORAK_SHIFTED)); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_SPACE); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case TD_TRIPLE_TAP: unregister_code16(s_undo); break;
        case TD_TRIPLE_HOLD: unregister_code16(MO(_ARROWS)); break;
        default: break;
    }
    senterc_state.state = TD_NONE;
}

// static tap osltapdance_state = {
//   .is_press_action = true,
//   .state = 0
// };

// void osl_tapdance_finished (qk_tap_dance_state_t *state, void *user_data) {
//   osltapdance_state.state = cur_dance(state);
//   switch (osltapdance_state.state) {
//     case SINGLE_TAP: set_oneshot_layer(1, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
//     case SINGLE_HOLD: register_code(KC_LALT); break;
//     case DOUBLE_TAP: set_oneshot_layer(1, ONESHOT_START); set_oneshot_layer(1, ONESHOT_PRESSED); break;
//     case DOUBLE_HOLD: register_code(KC_LALT); layer_on(1); break;
//     //Last case is for fast typing. Assuming your key is `f`:
//     //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
//     //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
//   }
// }

// void osl_tapdance_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (osltapdance_state.state) {
//     case SINGLE_TAP: break;
//     case SINGLE_HOLD: unregister_code(KC_LALT); break;
//     case DOUBLE_TAP: break;
//     case DOUBLE_HOLD: layer_off(1); unregister_code(KC_LALT); break;
//   }
//   osltapdance_state.state = 0;
// }


// #define SHFT_SPC KC_SPC
// #define SHFT_ENT KC_SPC
// #define DV_SPC KC_SPC
// #define DV_ENT KC_SPC


/*
Define tap dance actions 
*/


// declare tap dance actions
tap_dance_action_t tap_dance_actions[] = {

   //  tap-holds for left handed only dvorak layout
      [DVL_QUL] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUOTE, KC_L)      
    , [DVL_COMR] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, KC_R)   
    , [DVL_DOTC] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_C)      
    , [DVL_PG] = ACTION_TAP_DANCE_TAP_HOLD(KC_P, KC_G)          
    , [DVL_YF] = ACTION_TAP_DANCE_TAP_HOLD(KC_Y, KC_F)
    , [DVL_ID] = ACTION_TAP_DANCE_TAP_HOLD(KC_I, KC_D)
    , [DVL_UH] = ACTION_TAP_DANCE_TAP_HOLD(KC_U, KC_H)
    , [DVL_ET] = ACTION_TAP_DANCE_TAP_HOLD(KC_E, KC_T)
    , [DVL_ON] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, KC_N)
    , [DVL_AS] = ACTION_TAP_DANCE_TAP_HOLD(KC_A, KC_S)
    , [DVL_XB] = ACTION_TAP_DANCE_TAP_HOLD(KC_X, KC_B)
    , [DVL_KM] = ACTION_TAP_DANCE_TAP_HOLD(KC_K, KC_M)
    , [DVL_JW] = ACTION_TAP_DANCE_TAP_HOLD(KC_J, KC_W)
    , [DVL_QV] = ACTION_TAP_DANCE_TAP_HOLD(KC_Q, KC_V)
    , [DVL_SCNZ] = ACTION_TAP_DANCE_TAP_HOLD(KC_SCLN, KC_Z)

    // other tap-hold actions
    , [CT_KTAB] = ACTION_TAP_DANCE_TAP_HOLD(KC_K, KC_TAB)
    , [CT_XESC] = ACTION_TAP_DANCE_TAP_HOLD(KC_X, KC_ESC)
    , [CT_BESC] = ACTION_TAP_DANCE_TAP_HOLD(KC_B, KC_ESC)
    , [CT_MTAB] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, KC_TAB)
    
    // complex tap dances
    , [TD_CXPZS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cxpzs_finished, cxpzs_reset)
    , [TD_MUND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mund_finished, mund_reset)

    , [TD_SENTER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dvsenter_finished, dvsenter_reset)
    , [TD_SSPACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dvsspace_finished, dvsspace_reset)
    , [TD_SPCDOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sdotcom_finished, sdotcom_reset)

    , [TD_SSPACEC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sspacec_finished, sspacec_reset)
    , [TD_SENTERC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, senterc_finished, senterc_reset)


   //  , [ALT_OSL1]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, osl_tapdance_finished, osl_tapdance_reset)


};




// Combo Definitions
const uint16_t PROGMEM combo_comment[] = { KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM combo_layerlock_left[] = { KC_SCLN, KC_Q, KC_DOT, KC_P, COMBO_END};

const uint16_t PROGMEM combo_lyrs_left[] = {KC_COMM, KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM combo_media_left[] = {KC_DOT, KC_Q, COMBO_END};

const uint16_t PROGMEM combo_brackets_right[] = {KC_W, KC_Z, COMBO_END};

// const uint16_t PROGMEM combo_enter_right[] = { KC_W, KC_V, COMBO_END};
// const uint16_t PROGMEM combo_arrows_right[] = {KC_G, KC_C, COMBO_END};
// const uint16_t PROGMEM combo_numpad_right[] = {KC_G, KC_R, COMBO_END};

// const uint16_t PROGMEM combo_enter_left[] = {KC_SCLN, KC_J, COMBO_END};
// const uint16_t PROGMEM combo_arrows_left[] = {KC_COMM, KC_DOT,  COMBO_END};
// const uint16_t PROGMEM combo_numpad_left[] = {KC_COMM, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_brackets_left[] = {KC_DOT, KC_P, COMBO_END};



combo_t key_combos[] = {
    COMBO(combo_comment, LGUI(KC_SLASH))
    , COMBO(combo_layerlock_left, LLOCK)
    , COMBO(combo_lyrs_left, OSL(_LAYERS))
    , COMBO(combo_media_left, OSL(_MEDIA))   

    , COMBO(combo_brackets_right, OSL(_BRACKETS))
    
   //  , COMBO(combo_enter_right, KC_ENTER)
   //  , COMBO(combo_enter_left, KC_ENTER)
   //  , COMBO(combo_arrows_right, TO(_ARROWS))
   //  , COMBO(combo_numpad_right, TO(_NUMPAD))
   //  , COMBO(combo_arrows_left, TO(_ARROWS))
   //  , COMBO(combo_numpad_left, TO(_NUMPAD))
   //  , COMBO(combo_brackets_left, TO(_BRACKETS))


};




///////////////////////////////////////////////////////////////////////////////
// Achordion (https://getreuer.info/posts/keyboards/achordion)
///////////////////////////////////////////////////////////////////////////////
#ifdef ACHORDION_ENABLE
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in the rows outside the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboards are split.
  uint8_t row = other_record->event.key.row % (MATRIX_ROWS / 2);
  if (!(1 <= row && row <= 3)) { return true; }

  switch (tap_hold_keycode) {
    // Exceptionally allow symbol layer LTs + row 0 in same-hand chords.
    case HOME_S:
    case HOME_I:
      if (row <= 1) { return true; }
      break;
   // allow command-C, command-V, command-Z, command-N
   case HOME_H:
      if (other_keycode == KC_C || other_keycode == KC_V || other_keycode == KC_Z || other_keycode == HOME_N) { return true; }
      break;
   // allow command-A, command-O
   case HOME_U: 
      if (other_keycode == KC_A || other_keycode == KC_O) { return true; }
      break;
   // allow hyper-semicolon (lock screen)
    case HOME_I:
      if (other_keycode == KC_SCLN) { return true; }
      break;
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    default:
      return 800;  // Use a timeout of 800 ms.
  }
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  // Disable streak detection on LT keys.
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;
  }

  // Exceptions so that certain hotkeys don't get blocked as streaks.
  switch (tap_hold_keycode) {
    case HOME_N:
      if (next_keycode == KC_C || next_keycode == KC_V) {
        return 0;
      }
      break;
    case HOME_H:
      if (next_keycode == HOME_N) {
        return 0;
      }
      break;
  }

//   // Otherwise, tap_hold_keycode is a mod-tap key.
//   const uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
//   if ((mod & MOD_LSFT) != 0) {
//     return 100;  // A short streak timeout for Shift mod-tap keys.
//   } else {
//     return 220;  // A longer timeout otherwise.
//   }
}
#endif  // ACHORDION_ENABLE
