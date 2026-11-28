// Copyright 2026 Alison Spencer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum layers {
  _DVORAK,
  _SHIFT,
  _LEFT_HAND,
  _QWERTY,
  _GAMING_QWERTY,
  _MEDIA,
  _NUMPAD,
  _ARROWS,
  _SHIFTED_ARROWS,
  _SYMBOLS,
  _BRACKETS,
  _FUNCTION_KEYS,
  _SHORTCUTS,
};

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};



enum tap_dance_codes {
  DANCE_NUM_FN,          // hold numpad layer, double-hold F-keys layer
  DANCE_SLSH_ARROWS,     // tap SLASH, hold arrows layer, double-tap SLASH, double-hold shifted arrows layer
  DANCE_CLIPBOARD,       // tap Gui+C, hold Gui+X, double-tap Gui+V, double-hold Gui+Z
  DANCE_SAVE_UNDO,       // tap Gui+S, hold Gui+H, double-tap Gui+Z, double-hold Gui+Shift+Z
  DANCE_SPC_SHIFT,       // tap Space, hold Shift layer, double-tap Space, double-hold media layer
  DANCE_ENT_SHORTCUTS,   // tap Enter, hold Shift+Enter, double-tap go to media, double-hold shortcuts layer
  DANCE_ARROWS,          // hold arrows layer, double-hold shifted arrows layer
  DANCE_NUM_ARROWS,      // hold numpad layer, double-tap go to arrows, double-hold F-keys layer
  DANCE_ENT_SHIFT,       // tap Enter, hold Shift layer, double-tap Gui+Enter, double-hold Space
  DANCE_A_S,             // tap A, hold S, double-tap A, double-hold LShift
  DANCE_O_N,             // tap O, hold N, double-tap O, double-hold RCtrl
  DANCE_E_T,             // tap E, hold T, double-tap E, double-hold RAlt
  DANCE_U_H,             // tap U, hold H, double-tap U, double-hold LGui
  DANCE_SCLN_Z,          // tap SCLN, hold Z, double-tap COLN
  DANCE_K_M,             // tap K, hold M, double-tap K, double-hold TAB
  DANCE_X_B,             // tap X, hold B, double-tap X, double-hold Esc
  DANCE_QW_A,            // tap A, double-tap A, double-hold LShift
  DANCE_QW_S,            // tap S, double-tap S, double-hold LCtrl
  DANCE_QW_D,            // tap D, double-tap D, double-hold LAlt
  DANCE_QW_F,            // tap F, double-tap F, double-hold LGui
  DANCE_QW_ARROWS,       // hold arrows layer, double-hold shifted arrows layer
  DANCE_ENT_NUM,         // tap Enter, double-tap Enter, double-hold numpad layer
  DANCE_7_LPRN,          // tap 7, hold LPRN, double-tap 7, double-hold LBRC
  DANCE_9_RPRN,          // tap 9, hold RPRN, double-tap 9, double-hold RBRC
  DANCE_0_DOT_L,         // tap 0, hold DOT, double-tap UNDS, double-hold LShift
  DANCE_4_SLSH,          // tap 4, hold SLASH, double-tap 4, double-hold LCtrl
  DANCE_5_MINS_L,        // tap 5, hold MINUS, double-tap 5, double-hold LAlt
  DANCE_6_ASTR,          // tap 6, hold ASTR, double-tap 6, double-hold LGui
  DANCE_HASH_ESC_L,      // tap HASH, hold Esc, double-tap HASH, double-hold go to Dvorak
  DANCE_4_ASTR,          // tap 4, hold ASTR, double-tap 4, double-hold RGui
  DANCE_5_MINS_R,        // tap 5, hold MINUS, double-tap 5, double-hold RAlt
  DANCE_6_SLSH,          // tap 6, hold SLASH, double-tap 6, double-hold RCtrl
  DANCE_0_DOT_R,         // tap 0, hold DOT, double-tap UNDS, double-hold RShift
  DANCE_HASH_ESC_R,      // tap HASH, hold Esc, double-tap HASH, double-hold go to Dvorak
  DANCE_BASE_LGUI,       // tap go to Dvorak, hold LGui, double-tap go to Dvorak, double-hold LShift
  DANCE_BASE_RGUI,       // tap go to Dvorak, hold RGui, double-tap go to Dvorak, double-hold RShift
  DANCE_SLSH_ESC,        // tap SLASH, hold Esc, double-tap BSLS
  DANCE_ENT_L,           // tap Enter, hold Shift+Enter, double-tap Gui+Enter
  DANCE_ENT_R,           // tap Enter, hold Shift+Enter, double-tap Gui+Enter
  DANCE_SFT_ALT,         // hold LShift, double-hold LAlt
  DANCE_F6_GUI,          // tap F6, hold LGui, double-tap F6, double-hold Gui+F6
  DANCE_SFT_CTL,         // hold LShift, double-hold LCtrl
};

#define TD_NUM_FN         TD(DANCE_NUM_FN)
#define TD_SLSH_ARROWS    TD(DANCE_SLSH_ARROWS)
#define TD_CLIPBOARD      TD(DANCE_CLIPBOARD)
#define TD_SAVE_UNDO      TD(DANCE_SAVE_UNDO)
#define TD_SPC_SHIFT      TD(DANCE_SPC_SHIFT)
#define TD_ENT_SHORTCUTS  TD(DANCE_ENT_SHORTCUTS)
#define TD_ARROWS         TD(DANCE_ARROWS)
#define TD_NUM_ARROWS     TD(DANCE_NUM_ARROWS)
#define TD_ENT_SHIFT      TD(DANCE_ENT_SHIFT)
#define TD_A_S            TD(DANCE_A_S)
#define TD_O_N            TD(DANCE_O_N)
#define TD_E_T            TD(DANCE_E_T)
#define TD_U_H            TD(DANCE_U_H)
#define TD_SCLN_Z         TD(DANCE_SCLN_Z)
#define TD_K_M            TD(DANCE_K_M)
#define TD_X_B            TD(DANCE_X_B)
#define TD_QW_A           TD(DANCE_QW_A)
#define TD_QW_S           TD(DANCE_QW_S)
#define TD_QW_D           TD(DANCE_QW_D)
#define TD_QW_F           TD(DANCE_QW_F)
#define TD_QW_ARROWS      TD(DANCE_QW_ARROWS)
#define TD_ENT_NUM        TD(DANCE_ENT_NUM)
#define TD_7_LPRN         TD(DANCE_7_LPRN)
#define TD_9_RPRN         TD(DANCE_9_RPRN)
#define TD_0_DOT_L        TD(DANCE_0_DOT_L)
#define TD_4_SLSH         TD(DANCE_4_SLSH)
#define TD_5_MINS_L       TD(DANCE_5_MINS_L)
#define TD_6_ASTR         TD(DANCE_6_ASTR)
#define TD_HASH_ESC_L     TD(DANCE_HASH_ESC_L)
#define TD_4_ASTR         TD(DANCE_4_ASTR)
#define TD_5_MINS_R       TD(DANCE_5_MINS_R)
#define TD_6_SLSH         TD(DANCE_6_SLSH)
#define TD_0_DOT_R        TD(DANCE_0_DOT_R)
#define TD_HASH_ESC_R     TD(DANCE_HASH_ESC_R)
#define TD_BASE_LGUI      TD(DANCE_BASE_LGUI)
#define TD_BASE_RGUI      TD(DANCE_BASE_RGUI)
#define TD_SLSH_ESC       TD(DANCE_SLSH_ESC)
#define TD_ENT_L          TD(DANCE_ENT_L)
#define TD_ENT_R          TD(DANCE_ENT_R)
#define TD_SFT_ALT        TD(DANCE_SFT_ALT)
#define TD_F6_GUI         TD(DANCE_F6_GUI)
#define TD_SFT_CTL        TD(DANCE_SFT_CTL)


// Tap/hold keys: TH_<tap>_<hold>. The LT() layer number is only a unique tag,
// it is not a layer -- the real tap/hold behaviour lives in process_record_user().
#define TH_Q_ESC          LT(2, KC_V)    // tap Q, hold Esc
#define TH_K_TAB          LT(5, KC_F10)  // tap K, hold TAB
#define TH_X_ESC          LT(5, KC_F16)  // tap X, hold Esc
#define TH_ESC_TAB        LT(5, KC_T)    // tap Esc, hold TAB
#define TH_SLSH_BSLS      LT(11, KC_7)   // tap SLASH, hold BSLS
#define TH_MINS_UNDS      LT(3, KC_T)    // tap MINUS, hold UNDS
#define TH_B_ESC          LT(11, KC_9)   // tap B, hold Esc
#define TH_M_TAB          LT(10, KC_F2)  // tap M, hold TAB
#define TH_V_ESC          LT(6, KC_V)    // tap V, hold Esc
#define TH_CAP_A_LSFT     LT(3, KC_7)    // tap Shift+A, hold LShift
#define TH_CAP_O_LCTL     LT(6, KC_4)    // tap Shift+O, hold LCtrl
#define TH_CAP_E_LALT     LT(15, KC_S)   // tap Shift+E, hold LAlt
#define TH_CAP_U_LGUI     LT(6, KC_F17)  // tap Shift+U, hold LGui
#define TH_CAP_H_RGUI     LT(10, KC_6)   // tap Shift+H, hold RGui
#define TH_CAP_T_LALT     LT(14, KC_F11) // tap Shift+T, hold LAlt
#define TH_CAP_N_RCTL     LT(7, KC_D)    // tap Shift+N, hold RCtrl
#define TH_CAP_S_RSFT     LT(15, KC_F7)  // tap Shift+S, hold RShift
#define TH_QUOT_L         LT(14, KC_F16) // tap QUOTE, hold L
#define TH_COMM_R         LT(14, KC_F24) // tap COMMA, hold R
#define TH_DOT_C          LT(10, KC_F)   // tap DOT, hold C
#define TH_P_G            LT(8, KC_F3)   // tap P, hold G
#define TH_Y_F            LT(13, KC_F16) // tap Y, hold F
#define TH_I_D            LT(11, KC_E)   // tap I, hold D
#define TH_Q_V            LT(5, KC_F2)   // tap Q, hold V
#define TH_J_W            LT(15, KC_F11) // tap J, hold W
#define TH_BASE_MEDIA     LT(15, KC_N)   // tap go to Dvorak, hold go to media
#define TH_ENT_TAB        LT(8, KC_O)    // tap Enter, hold TAB
#define TH_8_DOT          LT(5, KC_6)    // tap 8, hold DOT
#define TH_COMM_COLN      LT(3, KC_A)    // tap COMMA, hold COLN
#define TH_1_DOT          LT(12, KC_7)   // tap 1, hold DOT
#define TH_2_PLUS         LT(5, KC_2)    // tap 2, hold PLUS
#define TH_3_TAB          LT(8, KC_2)    // tap 3, hold TAB
#define TH_COMM_SPC       LT(7, KC_F16)  // tap COMMA, hold Space
#define TH_0_DOT          LT(1, KC_F9)   // tap 0, hold DOT
#define TH_7_LBRC         LT(11, KC_M)   // tap 7, hold LBRC
#define TH_9_RBRC         LT(7, KC_F19)  // tap 9, hold RBRC
#define TH_1_TAB          LT(10, KC_F7)  // tap 1, hold TAB
#define TH_SHARROWS_ESC   LT(5, KC_Q)    // tap go to shifted arrows, hold Esc
#define TH_ARROWS_ESC     LT(9, KC_F3)   // tap go to arrows, hold Esc
#define TH_BASE_LGUI      LT(8, KC_F17)  // tap go to Dvorak, hold LGui
#define TH_BASE_RGUI      LT(8, KC_F13)  // tap go to Dvorak, hold RGui
#define TH_QUES_TAB       LT(6, KC_F22)  // tap QUES, hold TAB
#define TH_BSLS_ESC       LT(8, KC_Q)    // tap BSLS, hold Esc
#define TH_HASH_TAB       LT(7, KC_C)    // tap HASH, hold TAB
#define TH_GRV_BASE       LT(7, KC_F5)   // tap GRAVE, hold go to Dvorak
#define TH_SPC_TAB        LT(4, KC_Q)    // tap Space, hold TAB
#define TH_LCBR_LABK      LT(6, KC_F15)  // tap LCBR, hold LABK
#define TH_RCBR_RABK      LT(10, KC_R)   // tap RCBR, hold RABK
#define TH_HASH_ESC       LT(5, KC_V)    // tap HASH, hold Esc
#define TH_LPRN_LCBR      LT(15, KC_U)   // tap LPRN, hold LCBR
#define TH_RPRN_RCBR      LT(1, KC_F19)  // tap RPRN, hold RCBR
#define TH_RABK_LABK      LT(9, KC_H)    // tap RABK, hold LABK
#define TH_F12_ESC        LT(8, KC_K)    // tap F12, hold Esc
#define TH_NEWTAB_REOPEN  LT(2, KC_F17)  // tap Gui+T, hold Gui+Shift+T
#define TH_UNDO_REDO      LT(8, KC_F23)  // tap Gui+Z, hold Gui+Shift+Z

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT(
  //┌───────────────┬───────────────┬───────────────┬─────────────┬──────────────┬─────────────────┐                              ┌──────────────┬─────────────┬─────────────┬─────────────┬───────────────┬──────────────┐
     TO(_LEFT_HAND), KC_QUOTE,       KC_COMMA,       KC_DOT,       KC_P,          KC_Y,                                            KC_F,          KC_G,         KC_C,         KC_R,         KC_L,           TH_SLSH_BSLS,
  //├───────────────┼───────────────┼───────────────┼─────────────┼──────────────┼─────────────────┤                              ├──────────────┼─────────────┼─────────────┼─────────────┼───────────────┼──────────────┤
     KC_BSPC,        LSFT_T(KC_A),   LCTL_T(KC_O),   LALT_T(KC_E), LGUI_T(KC_U),  ALL_T(KC_I),                                     MEH_T(KC_D),   RGUI_T(KC_H), RALT_T(KC_T), RCTL_T(KC_N), RSFT_T(KC_S),   TH_MINS_UNDS,
  //├───────────────┼───────────────┼───────────────┼─────────────┼──────────────┼─────────────────┤                              ├──────────────┼─────────────┼─────────────┼─────────────┼───────────────┼──────────────┤
     TD_NUM_FN,      KC_SCLN,        TH_Q_ESC,       KC_J,         TH_K_TAB,      TH_X_ESC,                                        TH_B_ESC,      TH_M_TAB,     KC_W,         TH_V_ESC,     KC_Z,           TD_ARROWS,
  //├───────────────┼───────────────┼───────────────┼─────────────┼──────────────┼─────────────────┼─────────────┤       ├────────┼──────────────┼─────────────┼─────────────┼─────────────┼───────────────┼──────────────┤
     TT(_MEDIA),     TD_SLSH_ARROWS, OSL(_BRACKETS), LGUI(KC_H),   OSL(_SYMBOLS), TD_CLIPBOARD,     TD_SAVE_UNDO,         _______, OSL(_SHIFT),   XXXXXXX,      KC_ESCAPE,    _______,      OSL(_BRACKETS), OSL(_SYMBOLS),
  //└───────────────┴───────────────┴───────────────┴─────────────┴──────────────┴─────────────────┴─────────────┘       └────────┴──────────────┴─────────────┴─────────────┴─────────────┴───────────────┴──────────────┘
  //                                                ┌─────────────┬──────────────┬─────────────────┐                              ┌──────────────┬─────────────┬─────────────┐
                                                     TH_ESC_TAB,   TD_SPC_SHIFT,  TD_ENT_SHORTCUTS,                                TD_NUM_ARROWS, TD_ENT_SHIFT, _______
  //                                                └─────────────┴──────────────┴─────────────────┘                              └──────────────┴─────────────┴─────────────┘
  ),

  [_SHIFT] = LAYOUT(
  //┌────────────────────┬────────────────────┬──────────────┬──────────────┬──────────────┬───────────┐                         ┌───────────┬──────────────┬──────────────┬──────────────┬──────────────┬────────┐
     LSFT(KC_TAB),        KC_DQUO,             KC_LABK,       KC_RABK,       LSFT(KC_P),    LSFT(KC_Y),                           LSFT(KC_F), LSFT(KC_G),    LSFT(KC_C),    LSFT(KC_R),    LSFT(KC_L),    KC_BSLS,
  //├────────────────────┼────────────────────┼──────────────┼──────────────┼──────────────┼───────────┤                         ├───────────┼──────────────┼──────────────┼──────────────┼──────────────┼────────┤
     KC_DELETE,           TH_CAP_A_LSFT,       TH_CAP_O_LCTL, TH_CAP_E_LALT, TH_CAP_U_LGUI, LSFT(KC_I),                           LSFT(KC_D), TH_CAP_H_RGUI, TH_CAP_T_LALT, TH_CAP_N_RCTL, TH_CAP_S_RSFT, _______,
  //├────────────────────┼────────────────────┼──────────────┼──────────────┼──────────────┼───────────┤                         ├───────────┼──────────────┼──────────────┼──────────────┼──────────────┼────────┤
     OSL(_FUNCTION_KEYS), KC_COLN,             LSFT(KC_Q),    LSFT(KC_J),    LSFT(KC_K),    LSFT(KC_X),                           LSFT(KC_B), LSFT(KC_M),    LSFT(KC_W),    RSFT(KC_V),    RSFT(KC_Z),    _______,
  //├────────────────────┼────────────────────┼──────────────┼──────────────┼──────────────┼───────────┼────────┤       ├────────┼───────────┼──────────────┼──────────────┼──────────────┼──────────────┼────────┤
     TO(_DVORAK),         MO(_SHIFTED_ARROWS), _______,       _______,       _______,       _______,    _______,         _______, _______,    _______,       _______,       _______,       _______,       _______,
  //└────────────────────┴────────────────────┴──────────────┴──────────────┴──────────────┴───────────┴────────┘       └────────┴───────────┴──────────────┴──────────────┴──────────────┴──────────────┴────────┘
  //                                                         ┌──────────────┬──────────────┬───────────┐                         ┌───────────┬──────────────┬──────────────┐
                                                              _______,       _______,       _______,                              _______,    _______,       _______
  //                                                         └──────────────┴──────────────┴───────────┘                         └───────────┴──────────────┴──────────────┘
  ),

  [_LEFT_HAND] = LAYOUT(
  //┌──────────────┬──────────┬──────────┬─────────┬─────────────────┬────────┐                         ┌────────────┬──────────────┬──────────────┬──────────────┬──────────────────┬────────┐
     _______,       TH_QUOT_L, TH_COMM_R, TH_DOT_C, TH_P_G,           TH_Y_F,                            XXXXXXX,     KC_HOME,       KC_UP,         KC_END,        KC_LEFT_ALT,       XXXXXXX,
  //├──────────────┼──────────┼──────────┼─────────┼─────────────────┼────────┤                         ├────────────┼──────────────┼──────────────┼──────────────┼──────────────────┼────────┤
     KC_BSPC,       TD_A_S,    TD_O_N,    TD_E_T,   TD_U_H,           TH_I_D,                            XXXXXXX,     KC_LEFT,       KC_DOWN,       KC_RIGHT,      LSFT(KC_LEFT_ALT), KC_BSPC,
  //├──────────────┼──────────┼──────────┼─────────┼─────────────────┼────────┤                         ├────────────┼──────────────┼──────────────┼──────────────┼──────────────────┼────────┤
     _______,       TD_SCLN_Z, TH_Q_V,    TH_J_W,   TD_K_M,           TD_X_B,                            XXXXXXX,     OSM(MOD_RGUI), OSM(MOD_RALT), OSM(MOD_RCTL), OSM(MOD_RSFT),     XXXXXXX,
  //├──────────────┼──────────┼──────────┼─────────┼─────────────────┼────────┼────────┤       ├────────┼────────────┼──────────────┼──────────────┼──────────────┼──────────────────┼────────┤
     TH_BASE_MEDIA, _______,   _______,   _______,  _______,          _______, _______,         _______, XXXXXXX,     XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,           XXXXXXX,
  //└──────────────┴──────────┴──────────┴─────────┴─────────────────┴────────┴────────┘       └────────┴────────────┴──────────────┴──────────────┴──────────────┴──────────────────┴────────┘
  //                                     ┌─────────┬─────────────────┬────────┐                         ┌────────────┬──────────────┬──────────────┐
                                          _______,  LSFT_T(KC_SPACE), _______,                           KC_LEFT_GUI, _______,       _______
  //                                     └─────────┴─────────────────┴────────┘                         └────────────┴──────────────┴──────────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌──────────────┬─────────────┬────────┬────────┬─────────────────┬───────────┐                         ┌────────┬─────────────────┬─────────────┬─────────────┬────────────────┬───────────────┐
     KC_DELETE,     KC_Q,         KC_W,    KC_E,    KC_R,             KC_T,                                 KC_Y,    KC_U,             KC_I,         KC_O,         KC_P,            KC_BSLS,
  //├──────────────┼─────────────┼────────┼────────┼─────────────────┼───────────┤                         ├────────┼─────────────────┼─────────────┼─────────────┼────────────────┼───────────────┤
     KC_BSPC,       TD_QW_A,      TD_QW_S, TD_QW_D, TD_QW_F,          KC_G,                                 KC_H,    RGUI_T(KC_J),     RALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_QUOTE,
  //├──────────────┼─────────────┼────────┼────────┼─────────────────┼───────────┤                         ├────────┼─────────────────┼─────────────┼─────────────┼────────────────┼───────────────┤
     KC_LEFT_SHIFT, KC_Z,         KC_X,    KC_C,    KC_V,             KC_B,                                 KC_N,    KC_M,             KC_COMMA,     KC_DOT,       KC_SLASH,        KC_RIGHT_SHIFT,
  //├──────────────┼─────────────┼────────┼────────┼─────────────────┼───────────┼────────┤       ├────────┼────────┼─────────────────┼─────────────┼─────────────┼────────────────┼───────────────┤
     TH_BASE_MEDIA, TD_QW_ARROWS, _______, _______, _______,          _______,    _______,         _______, _______, _______,          _______,      _______,      _______,         _______,
  //└──────────────┴─────────────┴────────┴────────┴─────────────────┴───────────┴────────┘       └────────┴────────┴─────────────────┴─────────────┴─────────────┴────────────────┴───────────────┘
  //                                      ┌────────┬─────────────────┬───────────┐                         ┌────────┬─────────────────┬─────────────┐
                                           _______, LSFT_T(KC_SPACE), TH_ENT_TAB,                           _______, RSFT_T(KC_ENTER), _______
  //                                      └────────┴─────────────────┴───────────┘                         └────────┴─────────────────┴─────────────┘
  ),

  [_GAMING_QWERTY] = LAYOUT(
  //┌──────────────┬────────┬────────┬──────────────┬─────────────────┬───────────┐                         ┌────────┬───────────────┬─────────┬────────┬─────────┬─────────┐
     KC_DELETE,     KC_Q,    KC_W,    KC_E,          KC_R,             KC_T,                                 KC_Y,    KC_U,           KC_I,     KC_O,    KC_P,     KC_BSLS,
  //├──────────────┼────────┼────────┼──────────────┼─────────────────┼───────────┤                         ├────────┼───────────────┼─────────┼────────┼─────────┼─────────┤
     KC_BSPC,       KC_A,    KC_S,    KC_D,          KC_F,             KC_G,                                 KC_H,    KC_J,           KC_K,     KC_L,    KC_SCLN,  KC_QUOTE,
  //├──────────────┼────────┼────────┼──────────────┼─────────────────┼───────────┤                         ├────────┼───────────────┼─────────┼────────┼─────────┼─────────┤
     KC_LEFT_SHIFT, KC_Z,    KC_X,    KC_C,          KC_V,             KC_B,                                 KC_N,    KC_M,           KC_COMMA, KC_DOT,  KC_SLASH, _______,
  //├──────────────┼────────┼────────┼──────────────┼─────────────────┼───────────┼────────┤       ├────────┼────────┼───────────────┼─────────┼────────┼─────────┼─────────┤
     _______,       _______, _______, OSM(MOD_LALT), OSM(MOD_LGUI),    _______,    _______,         _______, _______, KC_RIGHT_SHIFT, _______,  _______, _______,  _______,
  //└──────────────┴────────┴────────┴──────────────┴─────────────────┴───────────┴────────┘       └────────┴────────┴───────────────┴─────────┴────────┴─────────┴─────────┘
  //                                 ┌──────────────┬─────────────────┬───────────┐                         ┌────────┬───────────────┬─────────┐
                                      _______,       LSFT_T(KC_SPACE), TD_ENT_NUM,                           _______, _______,        KC_ENTER
  //                                 └──────────────┴─────────────────┴───────────┘                         └────────┴───────────────┴─────────┘
  ),

  [_MEDIA] = LAYOUT(
  //┌───────────────────┬────────────┬────────────────────┬────────────────────┬─────────────────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TO(_LEFT_HAND),     XXXXXXX,     KC_AUDIO_VOL_DOWN,   KC_AUDIO_MUTE,       KC_AUDIO_VOL_UP,      RM_VALU,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //├───────────────────┼────────────┼────────────────────┼────────────────────┼─────────────────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     TO(_QWERTY),        XXXXXXX,     KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,  XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├───────────────────┼────────────┼────────────────────┼────────────────────┼─────────────────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     TO(_GAMING_QWERTY), XXXXXXX,     LGUI(KC_MINUS),      XXXXXXX,             LGUI(LSFT(KC_EQUAL)), RM_VALD,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├───────────────────┼────────────┼────────────────────┼────────────────────┼─────────────────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,            TO(_DVORAK), XXXXXXX,             XXXXXXX,             XXXXXXX,              XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└───────────────────┴────────────┴────────────────────┴────────────────────┴─────────────────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  //                                                      ┌────────────────────┬─────────────────────┬────────┐                         ┌────────┬────────┬────────┐
                                                           _______,             _______,              XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX
  //                                                      └────────────────────┴─────────────────────┴────────┘                         └────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌──────────────┬─────────────┬───────────────┬────────────┬──────────┬──────────────┐                         ┌──────────────┬──────────┬────────────┬───────────────┬─────────────┬──────────┐
     KC_DELETE,     QK_LLCK,      TD_7_LPRN,      TH_8_DOT,    TD_9_RPRN, XXXXXXX,                                 XXXXXXX,       TH_7_LBRC, TH_8_DOT,    TH_9_RBRC,      QK_LLCK,      KC_DELETE,
  //├──────────────┼─────────────┼───────────────┼────────────┼──────────┼──────────────┤                         ├──────────────┼──────────┼────────────┼───────────────┼─────────────┼──────────┤
     XXXXXXX,       TD_0_DOT_L,   TD_4_SLSH,      TD_5_MINS_L, TD_6_ASTR, OSL(_SYMBOLS),                           OSL(_SYMBOLS), TD_4_ASTR, TD_5_MINS_R, TD_6_SLSH,      TD_0_DOT_R,   KC_BSPC,
  //├──────────────┼─────────────┼───────────────┼────────────┼──────────┼──────────────┤                         ├──────────────┼──────────┼────────────┼───────────────┼─────────────┼──────────┤
     _______,       TH_COMM_COLN, TH_1_DOT,       TH_2_PLUS,   TH_3_TAB,  TD_HASH_ESC_L,                           TD_HASH_ESC_R, TH_1_TAB,  TH_2_PLUS,   KC_3,           TH_COMM_COLN, XXXXXXX,
  //├──────────────┼─────────────┼───────────────┼────────────┼──────────┼──────────────┼────────┤       ├────────┼──────────────┼──────────┼────────────┼───────────────┼─────────────┼──────────┤
     TH_BASE_MEDIA, XXXXXXX,      OSL(_BRACKETS), TH_COMM_SPC, TH_0_DOT,  _______,       _______,         _______, _______,       TH_0_DOT,  TH_COMM_SPC, OSL(_BRACKETS), XXXXXXX,      XXXXXXX,
  //└──────────────┴─────────────┴───────────────┴────────────┴──────────┴──────────────┴────────┘       └────────┴──────────────┴──────────┴────────────┴───────────────┴─────────────┴──────────┘
  //                                             ┌────────────┬──────────┬──────────────┐                         ┌──────────────┬──────────┬────────────┐
                                                  _______,     _______,   _______,                                 _______,       _______,   _______
  //                                             └────────────┴──────────┴──────────────┘                         └──────────────┴──────────┴────────────┘
  ),

  [_ARROWS] = LAYOUT(
  //┌──────────────┬────────────┬─────────────┬────────┬──────────────────┬────────────────────┐                         ┌───────────────────┬──────────────────────────────────┬────────┬─────────┬───────────────┬──────────────────┐
     KC_DELETE,     QK_LLCK,     KC_HOME,      KC_UP,   KC_END,            KC_PAGE_UP,                                    KC_PAGE_UP,         KC_HOME,                           KC_UP,   KC_END,   QK_LLCK,        KC_BSPC,
  //├──────────────┼────────────┼─────────────┼────────┼──────────────────┼────────────────────┤                         ├───────────────────┼──────────────────────────────────┼────────┼─────────┼───────────────┼──────────────────┤
     KC_BSPC,       KC_LEFT_GUI, KC_LEFT,      KC_DOWN, KC_RIGHT,          KC_PGDN,                                       KC_PGDN,            KC_LEFT,                           KC_DOWN, KC_RIGHT, KC_RIGHT_ALT,   LSFT(KC_LEFT_ALT),
  //├──────────────┼────────────┼─────────────┼────────┼──────────────────┼────────────────────┤                         ├───────────────────┼──────────────────────────────────┼────────┼─────────┼───────────────┼──────────────────┤
     KC_LEFT_ALT,   _______,     KC_LEFT_CTRL, XXXXXXX, LSFT(KC_LEFT_GUI), TH_SHARROWS_ESC,                               TH_SHARROWS_ESC,    XXXXXXX,                           XXXXXXX, XXXXXXX,  KC_RIGHT_SHIFT, _______,
  //├──────────────┼────────────┼─────────────┼────────┼──────────────────┼────────────────────┼────────┤       ├────────┼───────────────────┼──────────────────────────────────┼────────┼─────────┼───────────────┼──────────────────┤
     TH_BASE_MEDIA, _______,     XXXXXXX,      _______, XXXXXXX,           TD_BASE_LGUI,        _______,         _______, TD_BASE_RGUI,       XXXXXXX,                           XXXXXXX, _______,  XXXXXXX,        _______,
  //└──────────────┴────────────┴─────────────┴────────┴──────────────────┴────────────────────┴────────┘       └────────┴───────────────────┴──────────────────────────────────┴────────┴─────────┴───────────────┴──────────────────┘
  //                                          ┌────────┬──────────────────┬────────────────────┐                         ┌───────────────────┬──────────────────────────────────┬────────┐
                                               _______, LSFT_T(KC_SPACE),  LALT(KC_LEFT_SHIFT),                           RSFT(KC_RIGHT_GUI), MT(MOD_RSFT | MOD_RALT, KC_ENTER), _______
  //                                          └────────┴──────────────────┴────────────────────┘                         └───────────────────┴──────────────────────────────────┴────────┘
  ),

  [_SHIFTED_ARROWS] = LAYOUT(
  //┌──────────────┬────────────┬──────────────┬──────────────┬─────────────────┬──────────────┐                         ┌──────────────┬──────────────┬──────────────┬───────────────┬─────────────┬──────────┐
     KC_DELETE,     QK_LLCK,     KC_HOME,       LSFT(KC_UP),   KC_END,           KC_PAGE_UP,                              KC_PAGE_UP,    KC_HOME,       LSFT(KC_UP),   KC_END,         QK_LLCK,      KC_DELETE,
  //├──────────────┼────────────┼──────────────┼──────────────┼─────────────────┼──────────────┤                         ├──────────────┼──────────────┼──────────────┼───────────────┼─────────────┼──────────┤
     KC_BSPC,       KC_LEFT_GUI, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT),   KC_PGDN,                                 KC_PGDN,       LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT), KC_RIGHT_GUI, KC_BSPC,
  //├──────────────┼────────────┼──────────────┼──────────────┼─────────────────┼──────────────┤                         ├──────────────┼──────────────┼──────────────┼───────────────┼─────────────┼──────────┤
     KC_LEFT_ALT,   XXXXXXX,     XXXXXXX,       XXXXXXX,       XXXXXXX,          TH_ARROWS_ESC,                           TH_ARROWS_ESC, XXXXXXX,       XXXXXXX,       XXXXXXX,        KC_RIGHT_ALT, _______,
  //├──────────────┼────────────┼──────────────┼──────────────┼─────────────────┼──────────────┼────────┤       ├────────┼──────────────┼──────────────┼──────────────┼───────────────┼─────────────┼──────────┤
     TH_BASE_MEDIA, _______,     XXXXXXX,       XXXXXXX,       XXXXXXX,          TH_BASE_LGUI,  _______,         _______, TH_BASE_RGUI,  XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,      _______,
  //└──────────────┴────────────┴──────────────┴──────────────┴─────────────────┴──────────────┴────────┘       └────────┴──────────────┴──────────────┴──────────────┴───────────────┴─────────────┴──────────┘
  //                                           ┌──────────────┬─────────────────┬──────────────┐                         ┌──────────────┬──────────────┬──────────────┐
                                                _______,       LALT_T(KC_SPACE), _______,                                 XXXXXXX,       _______,       _______
  //                                           └──────────────┴─────────────────┴──────────────┘                         └──────────────┴──────────────┴──────────────┘
  ),

  [_SYMBOLS] = LAYOUT(
  //┌──────────────┬────────┬─────────┬─────────┬────────────┬────────────┐                         ┌────────────┬────────────┬─────────┬─────────┬─────────┬────────┐
     KC_SLASH,      KC_CIRC, KC_TILD,  KC_HASH,  KC_ASTR,     KC_PERC,                               KC_PERC,     KC_AMPR,     KC_PIPE,  KC_ASTR,  KC_CIRC,  _______,
  //├──────────────┼────────┼─────────┼─────────┼────────────┼────────────┤                         ├────────────┼────────────┼─────────┼─────────┼─────────┼────────┤
     KC_PIPE,       KC_AMPR, KC_AT,    KC_EXLM,  KC_EQUAL,    KC_DLR,                                KC_DLR,      KC_QUES,     KC_EXLM,  KC_EQUAL, KC_TILD,  _______,
  //├──────────────┼────────┼─────────┼─────────┼────────────┼────────────┤                         ├────────────┼────────────┼─────────┼─────────┼─────────┼────────┤
     KC_UNDS,       KC_PLUS, KC_MINUS, KC_GRAVE, TH_QUES_TAB, TD_SLSH_ESC,                           TH_BSLS_ESC, TH_HASH_TAB, KC_GRAVE, KC_AT,    KC_SLASH, KC_QUES,
  //├──────────────┼────────┼─────────┼─────────┼────────────┼────────────┼────────┤       ├────────┼────────────┼────────────┼─────────┼─────────┼─────────┼────────┤
     TH_BASE_MEDIA, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,     _______,         _______, TH_GRV_BASE, XXXXXXX,     KC_PLUS,  KC_MINUS, XXXXXXX,  XXXXXXX,
  //└──────────────┴────────┴─────────┴─────────┴────────────┴────────────┴────────┘       └────────┴────────────┴────────────┴─────────┴─────────┴─────────┴────────┘
  //                                  ┌─────────┬────────────┬────────────┐                         ┌────────────┬────────────┬─────────┐
                                       _______,  _______,     TD_ENT_L,                              TH_SPC_TAB,  TD_ENT_R,    _______
  //                                  └─────────┴────────────┴────────────┘                         └────────────┴────────────┴─────────┘
  ),

  [_BRACKETS] = LAYOUT(
  //┌────────────┬────────┬────────┬─────────────┬─────────────────┬────────────┐                         ┌────────────┬─────────────┬─────────────┬────────┬────────┬──────────┐
     KC_DELETE,   QK_LLCK, XXXXXXX, TH_LCBR_LABK, TH_RCBR_RABK,     KC_PLUS,                               KC_PLUS,     TH_LCBR_LABK, TH_RCBR_RABK, XXXXXXX, QK_LLCK, KC_DELETE,
  //├────────────┼────────┼────────┼─────────────┼─────────────────┼────────────┤                         ├────────────┼─────────────┼─────────────┼────────┼────────┼──────────┤
     KC_BSPC,     KC_LABK, KC_RABK, KC_LPRN,      KC_RPRN,          KC_MINUS,                              KC_MINUS,    TH_LPRN_LCBR, TH_RPRN_RCBR, KC_LABK, KC_RABK, KC_BSPC,
  //├────────────┼────────┼────────┼─────────────┼─────────────────┼────────────┤                         ├────────────┼─────────────┼─────────────┼────────┼────────┼──────────┤
     XXXXXXX,     KC_LCBR, KC_RCBR, KC_LBRC,      KC_RBRC,          TH_HASH_ESC,                           TH_HASH_ESC, KC_LBRC,      KC_RBRC,      KC_LCBR, KC_RCBR, XXXXXXX,
  //├────────────┼────────┼────────┼─────────────┼─────────────────┼────────────┼────────┤       ├────────┼────────────┼─────────────┼─────────────┼────────┼────────┼──────────┤
     TO(_DVORAK), XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,          XXXXXXX,     XXXXXXX,         _______, TO(_DVORAK), XXXXXXX,      TH_RABK_LABK, _______, XXXXXXX, XXXXXXX,
  //└────────────┴────────┴────────┴─────────────┴─────────────────┴────────────┴────────┘       └────────┴────────────┴─────────────┴─────────────┴────────┴────────┴──────────┘
  //                               ┌─────────────┬─────────────────┬────────────┐                         ┌────────────┬─────────────┬─────────────┐
                                    _______,      LGUI_T(KC_SPACE), _______,                               _______,     _______,      _______
  //                               └─────────────┴─────────────────┴────────────┘                         └────────────┴─────────────┴─────────────┘
  ),

  [_FUNCTION_KEYS] = LAYOUT(
  //┌──────────────┬──────────────┬──────────────┬──────────────┬───────────┬─────────────┐                         ┌─────────────┬───────────────┬───────────────┬───────────────┬───────────────┬────────┐
     XXXXXXX,       LSFT(KC_F6),   KC_F8,         KC_F7,         KC_F9,      KC_F10,                                 _______,      KC_F20,         KC_F21,         KC_F22,         KC_F23,         _______,
  //├──────────────┼──────────────┼──────────────┼──────────────┼───────────┼─────────────┤                         ├─────────────┼───────────────┼───────────────┼───────────────┼───────────────┼────────┤
     XXXXXXX,       TD_SFT_ALT,    LCTL_T(KC_F4), LALT_T(KC_F5), TD_F6_GUI,  KC_F11,                                 _______,      RGUI_T(KC_F17), RALT_T(KC_F18), RCTL_T(KC_F19), RSFT_T(KC_F24), _______,
  //├──────────────┼──────────────┼──────────────┼──────────────┼───────────┼─────────────┤                         ├─────────────┼───────────────┼───────────────┼───────────────┼───────────────┼────────┤
     _______,       KC_F12,        KC_F1,         KC_F2,         KC_F3,      TH_F12_ESC,                             KC_ESCAPE,    KC_F13,         KC_F14,         KC_F15,         KC_F16,         _______,
  //├──────────────┼──────────────┼──────────────┼──────────────┼───────────┼─────────────┼────────┤       ├────────┼─────────────┼───────────────┼───────────────┼───────────────┼───────────────┼────────┤
     TH_BASE_MEDIA, KC_LEFT_SHIFT, XXXXXXX,       XXXXXXX,       XXXXXXX,    TH_BASE_LGUI, _______,         _______, TH_BASE_RGUI, _______,        _______,        _______,        _______,        _______,
  //└──────────────┴──────────────┴──────────────┴──────────────┴───────────┴─────────────┴────────┘       └────────┴─────────────┴───────────────┴───────────────┴───────────────┴───────────────┴────────┘
  //                                             ┌──────────────┬───────────┬─────────────┐                         ┌─────────────┬───────────────┬───────────────┐
                                                  KC_LEFT_ALT,   TD_SFT_CTL, _______,                                _______,      _______,        _______
  //                                             └──────────────┴───────────┴─────────────┘                         └─────────────┴───────────────┴───────────────┘
  ),

  [_SHORTCUTS] = LAYOUT(
  //┌──────────────┬─────────────┬─────────────────┬───────────┬───────────┬─────────────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX,       XXXXXXX,      TH_NEWTAB_REOPEN, LGUI(KC_P), LGUI(KC_R), LGUI(KC_H),                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├──────────────┼─────────────┼─────────────────┼───────────┼───────────┼─────────────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     LGUI(KC_W),    LGUI(KC_A),   LCTL(KC_L),       LCTL(KC_C), LGUI(KC_D), LGUI(LSFT(KC_D)),                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├──────────────┼─────────────┼─────────────────┼───────────┼───────────┼─────────────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX,       TH_UNDO_REDO, LGUI(KC_B),       LGUI(KC_U), LGUI(KC_I), SELWORD,                                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├──────────────┼─────────────┼─────────────────┼───────────┼───────────┼─────────────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TH_BASE_MEDIA, XXXXXXX,      XXXXXXX,          SELLUP,     SELLINE,    SELWBAK,          XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└──────────────┴─────────────┴─────────────────┴───────────┴───────────┴─────────────────┴────────┘       └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  //                                               ┌───────────┬───────────┬─────────────────┐                         ┌────────┬────────┬────────┐
                                                    XXXXXXX,    _______,    _______,                                    XXXXXXX, XXXXXXX, XXXXXXX
  //                                               └───────────┴───────────┴─────────────────┘                         └────────┴────────┴────────┘
  ),
};


enum combos {
  COMBO_GUI_SLASH,      // Q+J          -> Gui+/
  COMBO_CAPS_WORD,      // K+M          -> Caps Word
  COMBO_BRACKETS,       // C+R          -> one-shot brackets layer
  COMBO_SYMBOLS,        // G+R          -> one-shot symbols layer
  COMBO_FUNCTION_KEYS,  // ;+P          -> one-shot F-keys layer
  COMBO_ARROWS,         // G+C          -> toggle arrows layer on
  COMBO_ARROWS_OFF,     // same keys on the arrows layer (Home+Up) -> toggle arrows layer off
  COMBO_NUMPAD,         // W+Z          -> one-shot numpad layer
  COMBO_NUM_BRACKETS,   // numpad 8+9   -> one-shot brackets layer
};

const uint16_t PROGMEM gui_slash_combo[]     = { TH_Q_ESC, KC_J, COMBO_END };
const uint16_t PROGMEM caps_word_combo[]     = { TH_K_TAB, TH_M_TAB, COMBO_END };
const uint16_t PROGMEM brackets_combo[]      = { KC_C, KC_R, COMBO_END };
const uint16_t PROGMEM symbols_combo[]       = { KC_G, KC_R, COMBO_END };
const uint16_t PROGMEM function_keys_combo[] = { KC_SCLN, KC_P, COMBO_END };
const uint16_t PROGMEM arrows_combo[]        = { KC_G, KC_C, COMBO_END };
const uint16_t PROGMEM arrows_off_combo[]    = { KC_HOME, KC_UP, COMBO_END };
const uint16_t PROGMEM numpad_combo[]        = { KC_W, KC_Z, COMBO_END };
const uint16_t PROGMEM num_brackets_combo[]  = { TH_8_DOT, TH_9_RBRC, COMBO_END };

combo_t key_combos[] = {
    [COMBO_GUI_SLASH]     = COMBO(gui_slash_combo, LGUI(KC_SLASH)),
    [COMBO_CAPS_WORD]     = COMBO(caps_word_combo, CW_TOGG),
    [COMBO_BRACKETS]      = COMBO(brackets_combo, OSL(_BRACKETS)),
    [COMBO_SYMBOLS]       = COMBO(symbols_combo, OSL(_SYMBOLS)),
    [COMBO_FUNCTION_KEYS] = COMBO(function_keys_combo, OSL(_FUNCTION_KEYS)),
    [COMBO_ARROWS]        = COMBO(arrows_combo, TG(_ARROWS)),
    [COMBO_ARROWS_OFF]    = COMBO(arrows_off_combo, TG(_ARROWS)),
    [COMBO_NUMPAD]        = COMBO(numpad_combo, OSL(_NUMPAD)),
    [COMBO_NUM_BRACKETS]  = COMBO(num_brackets_combo, OSL(_BRACKETS)),
};

// Combos only fire on the layer they were designed for, so fast key-mashing on
// the QWERTY/gaming layers (or anywhere else) can't trigger them by accident.
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  switch (combo_index) {
    case COMBO_ARROWS_OFF:
      return get_highest_layer(layer_state) == _ARROWS;
    case COMBO_NUM_BRACKETS:
      return get_highest_layer(layer_state) == _NUMPAD;
    default:
      return get_highest_layer(layer_state) == _DVORAK;
  }
}



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// Per-layer LED colors. Each layer is 68 {hue, sat, val} entries (0-255 each),
// indexed in the Iris CE LED order from keebio/iris_ce/rev1/keyboard.json -- NOT
// the order keys appear in LAYOUT(). {0,0,0} means off. val is scaled by the
// current brightness (RM_VALU/RM_VALD), see hsv_to_rgb_with_value().
//
// LED index of each key, as seen from above:
//
//   left half                            right half
//    0   2   3   5   6   8               42  40  39  37  36  34
//   14  13  12  11  10   9               43  44  45  46  47  48
//   15  16  17  18  19  20               54  53  52  51  50  49
//   26  25  24  23  22  21  33       67  55  56  57  58  59  60
//               29  30  32               66  64  63
//
// Underglow (keep {0,0,0} unless you want it lit):
//   left 1 4 7 27 28 31, right 35 38 41 61 62 65
//
// To recolor a key: find its index above and edit that entry in the layer's row.
// To color a new layer: add a [_LAYER] = { ...68 entries... } row here AND a case
// for it in rgb_matrix_indicators_user() below. Layers not listed there keep the
// normal RGB animation.
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_LEFT_HAND] = { {0,0,0}, {0,0,0}, {0,0,0}, {139,219,250}, {0,0,0}, {139,219,250}, {139,219,250}, {0,0,0}, {139,219,250}, {139,219,250}, {139,219,250}, {139,219,250}, {139,219,250}, {139,219,250}, {0,0,0}, {0,0,0}, {139,219,250}, {139,219,250}, {139,219,250}, {139,219,250}, {139,219,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,219,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,219,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,219,250}, {139,219,250}, {139,219,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_MEDIA] = { {152,255,255}, {0,0,0}, {0,0,0}, {182,255,255}, {0,0,0}, {179,255,141}, {157,255,255}, {0,0,0}, {39,255,255}, {0,0,0}, {234,255,255}, {234,255,255}, {234,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {21,150,255}, {0,0,0}, {21,150,255}, {39,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_NUMPAD] = { {0,0,0}, {0,0,0}, {245,226,242}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {125,244,194}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {221,125,229}, {188,255,255}, {188,255,255}, {188,255,255}, {221,125,229}, {0,0,0}, {188,255,255}, {0,0,0}, {134,244,194}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,226,242}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {125,244,194}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {221,125,229}, {188,255,255}, {188,255,255}, {188,255,255}, {221,125,229}, {0,0,0}, {188,255,255}, {0,0,0}, {134,244,194}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_ARROWS] = { {0,0,0}, {0,0,0}, {233,255,255}, {53,102,252}, {0,0,0}, {74,255,255}, {53,102,252}, {0,0,0}, {53,102,252}, {53,102,252}, {74,255,255}, {74,255,255}, {74,255,255}, {112,89,128}, {0,0,0}, {112,89,128}, {0,0,0}, {112,89,128}, {0,0,0}, {112,89,128}, {113,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {233,255,255}, {53,102,252}, {0,0,0}, {74,255,255}, {53,102,252}, {0,0,0}, {53,102,252}, {53,102,252}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {112,89,128}, {0,0,0}, {0,0,0}, {0,0,0}, {113,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {112,89,128}, {0,0,0} },

    [_SHIFTED_ARROWS] = { {0,0,0}, {0,0,0}, {234,255,255}, {53,102,252}, {0,0,0}, {113,255,255}, {53,102,252}, {0,0,0}, {53,102,252}, {53,102,252}, {113,255,255}, {113,255,255}, {113,255,255}, {112,59,252}, {0,0,0}, {112,59,252}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {234,255,255}, {53,102,252}, {0,0,0}, {113,255,255}, {53,102,252}, {0,0,0}, {53,102,252}, {53,102,252}, {113,255,255}, {113,255,255}, {113,255,255}, {112,59,252}, {0,0,0}, {0,0,0}, {112,59,252}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_SYMBOLS] = { {125,244,194}, {0,0,0}, {125,244,194}, {125,244,194}, {0,0,0}, {125,244,194}, {125,244,194}, {0,0,0}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {0,0,0}, {125,244,194}, {125,244,194}, {125,244,194}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {125,244,194}, {125,244,194}, {0,0,0}, {125,244,194}, {125,244,194}, {0,0,0}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {0,0,0}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {125,244,194}, {0,0,0}, {125,244,194}, {125,244,194}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_BRACKETS] = { {0,0,0}, {0,0,0}, {134,244,194}, {0,0,0}, {0,0,0}, {134,244,194}, {134,244,194}, {0,0,0}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {0,0,0}, {0,0,0}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,244,194}, {0,0,0}, {0,0,0}, {134,244,194}, {134,244,194}, {0,0,0}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {0,0,0}, {0,0,0}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {134,244,194}, {0,0,0}, {0,0,0}, {134,244,194}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_FUNCTION_KEYS] = { {0,0,0}, {0,0,0}, {38,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {112,59,252}, {0,0,0}, {0,0,0}, {38,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {112,59,252}, {0,0,0}, {0,0,0}, {0,0,0}, {112,59,252}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {131,255,255}, {46,255,255}, {46,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_SHORTCUTS] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {228,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {228,218,204}, {228,218,204}, {228,218,204}, {0,0,0}, {0,0,0}, {228,218,204}, {228,218,204}, {228,218,204}, {228,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

// Runs on both halves. The right half only knows the active layer because
// SPLIT_LAYER_STATE_ENABLE is set in config.h -- without it the right half stays
// on the default animation. Only the highest active layer is checked.
bool rgb_matrix_indicators_user(void) {
  switch (biton32(layer_state)) {
    case _LEFT_HAND:
      set_layer_color(_LEFT_HAND);
      break;
    case _MEDIA:
      set_layer_color(_MEDIA);
      break;
    case _NUMPAD:
      set_layer_color(_NUMPAD);
      break;
    case _ARROWS:
      set_layer_color(_ARROWS);
      break;
    case _SHIFTED_ARROWS:
      set_layer_color(_SHIFTED_ARROWS);
      break;
    case _SYMBOLS:
      set_layer_color(_SYMBOLS);
      break;
    case _BRACKETS:
      set_layer_color(_BRACKETS);
      break;
    case _FUNCTION_KEYS:
      set_layer_color(_FUNCTION_KEYS);
      break;
    case _SHORTCUTS:
      set_layer_color(_SHORTCUTS);
      break;
   default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
      }
  }

  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,      
    SINGLE_HOLD,         
    DOUBLE_TAP,          
    DOUBLE_HOLD,         
    DOUBLE_SINGLE_TAP,   
    MORE_TAPS            
};

static tap dance_state[42];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void dance_num_fn_finished(tap_dance_state_t *state, void *user_data);
void dance_num_fn_reset(tap_dance_state_t *state, void *user_data);

void dance_num_fn_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_NUM_FN].step = dance_step(state);
    switch (dance_state[DANCE_NUM_FN].step) {
        case SINGLE_HOLD: layer_on(_NUMPAD); break;
        case DOUBLE_HOLD: layer_on(_FUNCTION_KEYS); break;
    }
}

void dance_num_fn_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_NUM_FN].step) {
        case SINGLE_HOLD:
          if(!is_layer_locked(_NUMPAD)) {
            layer_off(_NUMPAD);
          }
        break;
              case DOUBLE_HOLD:
                if(!is_layer_locked(_FUNCTION_KEYS)) {
                  layer_off(_FUNCTION_KEYS);
                }
                break;
    }
    dance_state[DANCE_NUM_FN].step = 0;
}
void on_dance_slsh_arrows(tap_dance_state_t *state, void *user_data);
void dance_slsh_arrows_finished(tap_dance_state_t *state, void *user_data);
void dance_slsh_arrows_reset(tap_dance_state_t *state, void *user_data);

void on_dance_slsh_arrows(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_slsh_arrows_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_SLSH_ARROWS].step = dance_step(state);
    switch (dance_state[DANCE_SLSH_ARROWS].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: layer_on(_ARROWS); break;
        case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
        case DOUBLE_HOLD: layer_on(_SHIFTED_ARROWS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_slsh_arrows_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_SLSH_ARROWS].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(_ARROWS)) {
            layer_off(_ARROWS);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
              case DOUBLE_HOLD:
                if(!is_layer_locked(_SHIFTED_ARROWS)) {
                  layer_off(_SHIFTED_ARROWS);
                }
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[DANCE_SLSH_ARROWS].step = 0;
}
void on_dance_clipboard(tap_dance_state_t *state, void *user_data);
void dance_clipboard_finished(tap_dance_state_t *state, void *user_data);
void dance_clipboard_reset(tap_dance_state_t *state, void *user_data);

void on_dance_clipboard(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_C));
    }
}

void dance_clipboard_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_CLIPBOARD].step = dance_step(state);
    switch (dance_state[DANCE_CLIPBOARD].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_C)); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_X)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_V)); break;
        case DOUBLE_HOLD: register_code16(LGUI(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_C)); register_code16(LGUI(KC_C));
    }
}

void dance_clipboard_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_CLIPBOARD].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_X)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_V)); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
    }
    dance_state[DANCE_CLIPBOARD].step = 0;
}
void on_dance_save_undo(tap_dance_state_t *state, void *user_data);
void dance_save_undo_finished(tap_dance_state_t *state, void *user_data);
void dance_save_undo_reset(tap_dance_state_t *state, void *user_data);

void on_dance_save_undo(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_S));
        tap_code16(LGUI(KC_S));
        tap_code16(LGUI(KC_S));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_S));
    }
}

void dance_save_undo_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_SAVE_UNDO].step = dance_step(state);
    switch (dance_state[DANCE_SAVE_UNDO].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_S)); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_H)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_Z)); break;
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_Z))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_S)); register_code16(LGUI(KC_S));
    }
}

void dance_save_undo_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_SAVE_UNDO].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_S)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_H)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_Z)); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_Z))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_S)); break;
    }
    dance_state[DANCE_SAVE_UNDO].step = 0;
}
void on_dance_spc_shift(tap_dance_state_t *state, void *user_data);
void dance_spc_shift_finished(tap_dance_state_t *state, void *user_data);
void dance_spc_shift_reset(tap_dance_state_t *state, void *user_data);

void on_dance_spc_shift(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

void dance_spc_shift_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_SPC_SHIFT].step = dance_step(state);
    switch (dance_state[DANCE_SPC_SHIFT].step) {
        case SINGLE_TAP: register_code16(KC_SPACE); break;
        case SINGLE_HOLD: layer_on(_SHIFT); break;
        case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
        case DOUBLE_HOLD: layer_on(_MEDIA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
    }
}

void dance_spc_shift_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_SPC_SHIFT].step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(_SHIFT)) {
            layer_off(_SHIFT);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
              case DOUBLE_HOLD:
                if(!is_layer_locked(_MEDIA)) {
                  layer_off(_MEDIA);
                }
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
    }
    dance_state[DANCE_SPC_SHIFT].step = 0;
}
void on_dance_ent_shortcuts(tap_dance_state_t *state, void *user_data);
void dance_ent_shortcuts_finished(tap_dance_state_t *state, void *user_data);
void dance_ent_shortcuts_reset(tap_dance_state_t *state, void *user_data);

void on_dance_ent_shortcuts(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_ent_shortcuts_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_ENT_SHORTCUTS].step = dance_step(state);
    switch (dance_state[DANCE_ENT_SHORTCUTS].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: layer_move(_MEDIA); break;
        case DOUBLE_HOLD: layer_on(_SHORTCUTS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_ent_shortcuts_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_ENT_SHORTCUTS].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
              case DOUBLE_HOLD:
                if(!is_layer_locked(_SHORTCUTS)) {
                  layer_off(_SHORTCUTS);
                }
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[DANCE_ENT_SHORTCUTS].step = 0;
}
void dance_arrows_finished(tap_dance_state_t *state, void *user_data);
void dance_arrows_reset(tap_dance_state_t *state, void *user_data);

void dance_arrows_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_ARROWS].step = dance_step(state);
    switch (dance_state[DANCE_ARROWS].step) {
        case SINGLE_HOLD: layer_on(_ARROWS); break;
        case DOUBLE_HOLD: layer_on(_SHIFTED_ARROWS); break;
    }
}

void dance_arrows_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_ARROWS].step) {
        case SINGLE_HOLD:
          if(!is_layer_locked(_ARROWS)) {
            layer_off(_ARROWS);
          }
        break;
              case DOUBLE_HOLD:
                if(!is_layer_locked(_SHIFTED_ARROWS)) {
                  layer_off(_SHIFTED_ARROWS);
                }
                break;
    }
    dance_state[DANCE_ARROWS].step = 0;
}
void dance_num_arrows_finished(tap_dance_state_t *state, void *user_data);
void dance_num_arrows_reset(tap_dance_state_t *state, void *user_data);

void dance_num_arrows_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_NUM_ARROWS].step = dance_step(state);
    switch (dance_state[DANCE_NUM_ARROWS].step) {
        case SINGLE_HOLD: layer_on(_NUMPAD); break;
        case DOUBLE_TAP: layer_move(_ARROWS); break;
        case DOUBLE_HOLD: layer_on(_FUNCTION_KEYS); break;
    }
}

void dance_num_arrows_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_NUM_ARROWS].step) {
        case SINGLE_HOLD:
          if(!is_layer_locked(_NUMPAD)) {
            layer_off(_NUMPAD);
          }
        break;
              case DOUBLE_HOLD:
                if(!is_layer_locked(_FUNCTION_KEYS)) {
                  layer_off(_FUNCTION_KEYS);
                }
                break;
    }
    dance_state[DANCE_NUM_ARROWS].step = 0;
}
void on_dance_ent_shift(tap_dance_state_t *state, void *user_data);
void dance_ent_shift_finished(tap_dance_state_t *state, void *user_data);
void dance_ent_shift_reset(tap_dance_state_t *state, void *user_data);

void on_dance_ent_shift(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_ent_shift_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_ENT_SHIFT].step = dance_step(state);
    switch (dance_state[DANCE_ENT_SHIFT].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: layer_on(_SHIFT); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_ENTER)); break;
        case DOUBLE_HOLD: register_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_ent_shift_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_ENT_SHIFT].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(_SHIFT)) {
            layer_off(_SHIFT);
          }
        break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_ENTER)); break;
        case DOUBLE_HOLD: unregister_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[DANCE_ENT_SHIFT].step = 0;
}
void on_dance_a_s(tap_dance_state_t *state, void *user_data);
void dance_a_s_finished(tap_dance_state_t *state, void *user_data);
void dance_a_s_reset(tap_dance_state_t *state, void *user_data);

void on_dance_a_s(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_A);
        tap_code16(KC_A);
        tap_code16(KC_A);
    }
    if(state->count > 3) {
        tap_code16(KC_A);
    }
}

void dance_a_s_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_A_S].step = dance_step(state);
    switch (dance_state[DANCE_A_S].step) {
        case SINGLE_TAP: register_code16(KC_A); break;
        case SINGLE_HOLD: register_code16(KC_S); break;
        case DOUBLE_TAP: register_code16(KC_A); register_code16(KC_A); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_A); register_code16(KC_A);
    }
}

void dance_a_s_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_A_S].step) {
        case SINGLE_TAP: unregister_code16(KC_A); break;
        case SINGLE_HOLD: unregister_code16(KC_S); break;
        case DOUBLE_TAP: unregister_code16(KC_A); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_A); break;
    }
    dance_state[DANCE_A_S].step = 0;
}
void on_dance_o_n(tap_dance_state_t *state, void *user_data);
void dance_o_n_finished(tap_dance_state_t *state, void *user_data);
void dance_o_n_reset(tap_dance_state_t *state, void *user_data);

void on_dance_o_n(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

void dance_o_n_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_O_N].step = dance_step(state);
    switch (dance_state[DANCE_O_N].step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(KC_N); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void dance_o_n_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_O_N].step) {
        case SINGLE_TAP: unregister_code16(KC_O); break;
        case SINGLE_HOLD: unregister_code16(KC_N); break;
        case DOUBLE_TAP: unregister_code16(KC_O); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
    }
    dance_state[DANCE_O_N].step = 0;
}
void on_dance_e_t(tap_dance_state_t *state, void *user_data);
void dance_e_t_finished(tap_dance_state_t *state, void *user_data);
void dance_e_t_reset(tap_dance_state_t *state, void *user_data);

void on_dance_e_t(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_E);
        tap_code16(KC_E);
        tap_code16(KC_E);
    }
    if(state->count > 3) {
        tap_code16(KC_E);
    }
}

void dance_e_t_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_E_T].step = dance_step(state);
    switch (dance_state[DANCE_E_T].step) {
        case SINGLE_TAP: register_code16(KC_E); break;
        case SINGLE_HOLD: register_code16(KC_T); break;
        case DOUBLE_TAP: register_code16(KC_E); register_code16(KC_E); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_E); register_code16(KC_E);
    }
}

void dance_e_t_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_E_T].step) {
        case SINGLE_TAP: unregister_code16(KC_E); break;
        case SINGLE_HOLD: unregister_code16(KC_T); break;
        case DOUBLE_TAP: unregister_code16(KC_E); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_E); break;
    }
    dance_state[DANCE_E_T].step = 0;
}
void on_dance_u_h(tap_dance_state_t *state, void *user_data);
void dance_u_h_finished(tap_dance_state_t *state, void *user_data);
void dance_u_h_reset(tap_dance_state_t *state, void *user_data);

void on_dance_u_h(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

void dance_u_h_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_U_H].step = dance_step(state);
    switch (dance_state[DANCE_U_H].step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case SINGLE_HOLD: register_code16(KC_H); break;
        case DOUBLE_TAP: register_code16(KC_U); register_code16(KC_U); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void dance_u_h_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_U_H].step) {
        case SINGLE_TAP: unregister_code16(KC_U); break;
        case SINGLE_HOLD: unregister_code16(KC_H); break;
        case DOUBLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_U); break;
    }
    dance_state[DANCE_U_H].step = 0;
}
void on_dance_scln_z(tap_dance_state_t *state, void *user_data);
void dance_scln_z_finished(tap_dance_state_t *state, void *user_data);
void dance_scln_z_reset(tap_dance_state_t *state, void *user_data);

void on_dance_scln_z(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SCLN);
        tap_code16(KC_SCLN);
        tap_code16(KC_SCLN);
    }
    if(state->count > 3) {
        tap_code16(KC_SCLN);
    }
}

void dance_scln_z_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_SCLN_Z].step = dance_step(state);
    switch (dance_state[DANCE_SCLN_Z].step) {
        case SINGLE_TAP: register_code16(KC_SCLN); break;
        case SINGLE_HOLD: register_code16(KC_Z); break;
        case DOUBLE_TAP: register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SCLN); register_code16(KC_SCLN);
    }
}

void dance_scln_z_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_SCLN_Z].step) {
        case SINGLE_TAP: unregister_code16(KC_SCLN); break;
        case SINGLE_HOLD: unregister_code16(KC_Z); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SCLN); break;
    }
    dance_state[DANCE_SCLN_Z].step = 0;
}
void on_dance_k_m(tap_dance_state_t *state, void *user_data);
void dance_k_m_finished(tap_dance_state_t *state, void *user_data);
void dance_k_m_reset(tap_dance_state_t *state, void *user_data);

void on_dance_k_m(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void dance_k_m_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_K_M].step = dance_step(state);
    switch (dance_state[DANCE_K_M].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(KC_M); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_HOLD: register_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void dance_k_m_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_K_M].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case SINGLE_HOLD: unregister_code16(KC_M); break;
        case DOUBLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_HOLD: unregister_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[DANCE_K_M].step = 0;
}
void on_dance_x_b(tap_dance_state_t *state, void *user_data);
void dance_x_b_finished(tap_dance_state_t *state, void *user_data);
void dance_x_b_reset(tap_dance_state_t *state, void *user_data);

void on_dance_x_b(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_x_b_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_X_B].step = dance_step(state);
    switch (dance_state[DANCE_X_B].step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case SINGLE_HOLD: register_code16(KC_B); break;
        case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break;
        case DOUBLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void dance_x_b_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_X_B].step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case SINGLE_HOLD: unregister_code16(KC_B); break;
        case DOUBLE_TAP: unregister_code16(KC_X); break;
        case DOUBLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state[DANCE_X_B].step = 0;
}
void on_dance_qw_a(tap_dance_state_t *state, void *user_data);
void dance_qw_a_finished(tap_dance_state_t *state, void *user_data);
void dance_qw_a_reset(tap_dance_state_t *state, void *user_data);

void on_dance_qw_a(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_A);
        tap_code16(KC_A);
        tap_code16(KC_A);
    }
    if(state->count > 3) {
        tap_code16(KC_A);
    }
}

void dance_qw_a_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_QW_A].step = dance_step(state);
    switch (dance_state[DANCE_QW_A].step) {
        case SINGLE_TAP: register_code16(KC_A); break;
        case DOUBLE_TAP: register_code16(KC_A); register_code16(KC_A); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_A); register_code16(KC_A);
    }
}

void dance_qw_a_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_QW_A].step) {
        case SINGLE_TAP: unregister_code16(KC_A); break;
        case DOUBLE_TAP: unregister_code16(KC_A); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_A); break;
    }
    dance_state[DANCE_QW_A].step = 0;
}
void on_dance_qw_s(tap_dance_state_t *state, void *user_data);
void dance_qw_s_finished(tap_dance_state_t *state, void *user_data);
void dance_qw_s_reset(tap_dance_state_t *state, void *user_data);

void on_dance_qw_s(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_S);
        tap_code16(KC_S);
        tap_code16(KC_S);
    }
    if(state->count > 3) {
        tap_code16(KC_S);
    }
}

void dance_qw_s_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_QW_S].step = dance_step(state);
    switch (dance_state[DANCE_QW_S].step) {
        case SINGLE_TAP: register_code16(KC_S); break;
        case DOUBLE_TAP: register_code16(KC_S); register_code16(KC_S); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_S); register_code16(KC_S);
    }
}

void dance_qw_s_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_QW_S].step) {
        case SINGLE_TAP: unregister_code16(KC_S); break;
        case DOUBLE_TAP: unregister_code16(KC_S); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_S); break;
    }
    dance_state[DANCE_QW_S].step = 0;
}
void on_dance_qw_d(tap_dance_state_t *state, void *user_data);
void dance_qw_d_finished(tap_dance_state_t *state, void *user_data);
void dance_qw_d_reset(tap_dance_state_t *state, void *user_data);

void on_dance_qw_d(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_D);
        tap_code16(KC_D);
        tap_code16(KC_D);
    }
    if(state->count > 3) {
        tap_code16(KC_D);
    }
}

void dance_qw_d_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_QW_D].step = dance_step(state);
    switch (dance_state[DANCE_QW_D].step) {
        case SINGLE_TAP: register_code16(KC_D); break;
        case DOUBLE_TAP: register_code16(KC_D); register_code16(KC_D); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_D); register_code16(KC_D);
    }
}

void dance_qw_d_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_QW_D].step) {
        case SINGLE_TAP: unregister_code16(KC_D); break;
        case DOUBLE_TAP: unregister_code16(KC_D); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_D); break;
    }
    dance_state[DANCE_QW_D].step = 0;
}
void on_dance_qw_f(tap_dance_state_t *state, void *user_data);
void dance_qw_f_finished(tap_dance_state_t *state, void *user_data);
void dance_qw_f_reset(tap_dance_state_t *state, void *user_data);

void on_dance_qw_f(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F);
        tap_code16(KC_F);
        tap_code16(KC_F);
    }
    if(state->count > 3) {
        tap_code16(KC_F);
    }
}

void dance_qw_f_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_QW_F].step = dance_step(state);
    switch (dance_state[DANCE_QW_F].step) {
        case SINGLE_TAP: register_code16(KC_F); break;
        case DOUBLE_TAP: register_code16(KC_F); register_code16(KC_F); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F); register_code16(KC_F);
    }
}

void dance_qw_f_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_QW_F].step) {
        case SINGLE_TAP: unregister_code16(KC_F); break;
        case DOUBLE_TAP: unregister_code16(KC_F); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F); break;
    }
    dance_state[DANCE_QW_F].step = 0;
}
void dance_qw_arrows_finished(tap_dance_state_t *state, void *user_data);
void dance_qw_arrows_reset(tap_dance_state_t *state, void *user_data);

void dance_qw_arrows_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_QW_ARROWS].step = dance_step(state);
    switch (dance_state[DANCE_QW_ARROWS].step) {
        case SINGLE_HOLD: layer_on(_ARROWS); break;
        case DOUBLE_HOLD: layer_on(_SHIFTED_ARROWS); break;
    }
}

void dance_qw_arrows_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_QW_ARROWS].step) {
        case SINGLE_HOLD:
          if(!is_layer_locked(_ARROWS)) {
            layer_off(_ARROWS);
          }
        break;
              case DOUBLE_HOLD:
                if(!is_layer_locked(_SHIFTED_ARROWS)) {
                  layer_off(_SHIFTED_ARROWS);
                }
                break;
    }
    dance_state[DANCE_QW_ARROWS].step = 0;
}
void on_dance_ent_num(tap_dance_state_t *state, void *user_data);
void dance_ent_num_finished(tap_dance_state_t *state, void *user_data);
void dance_ent_num_reset(tap_dance_state_t *state, void *user_data);

void on_dance_ent_num(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_ent_num_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_ENT_NUM].step = dance_step(state);
    switch (dance_state[DANCE_ENT_NUM].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case DOUBLE_TAP: register_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case DOUBLE_HOLD: layer_on(_NUMPAD); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_ent_num_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_ENT_NUM].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_TAP: unregister_code16(KC_ENTER); break;
              case DOUBLE_HOLD:
                if(!is_layer_locked(_NUMPAD)) {
                  layer_off(_NUMPAD);
                }
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[DANCE_ENT_NUM].step = 0;
}
void on_dance_7_lprn(tap_dance_state_t *state, void *user_data);
void dance_7_lprn_finished(tap_dance_state_t *state, void *user_data);
void dance_7_lprn_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7_lprn(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_7);
        tap_code16(KC_7);
        tap_code16(KC_7);
    }
    if(state->count > 3) {
        tap_code16(KC_7);
    }
}

void dance_7_lprn_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_7_LPRN].step = dance_step(state);
    switch (dance_state[DANCE_7_LPRN].step) {
        case SINGLE_TAP: register_code16(KC_7); break;
        case SINGLE_HOLD: register_code16(KC_LPRN); break;
        case DOUBLE_TAP: register_code16(KC_7); register_code16(KC_7); break;
        case DOUBLE_HOLD: register_code16(KC_LBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_7); register_code16(KC_7);
    }
}

void dance_7_lprn_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_7_LPRN].step) {
        case SINGLE_TAP: unregister_code16(KC_7); break;
        case SINGLE_HOLD: unregister_code16(KC_LPRN); break;
        case DOUBLE_TAP: unregister_code16(KC_7); break;
        case DOUBLE_HOLD: unregister_code16(KC_LBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_7); break;
    }
    dance_state[DANCE_7_LPRN].step = 0;
}
void on_dance_9_rprn(tap_dance_state_t *state, void *user_data);
void dance_9_rprn_finished(tap_dance_state_t *state, void *user_data);
void dance_9_rprn_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9_rprn(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_9);
        tap_code16(KC_9);
        tap_code16(KC_9);
    }
    if(state->count > 3) {
        tap_code16(KC_9);
    }
}

void dance_9_rprn_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_9_RPRN].step = dance_step(state);
    switch (dance_state[DANCE_9_RPRN].step) {
        case SINGLE_TAP: register_code16(KC_9); break;
        case SINGLE_HOLD: register_code16(KC_RPRN); break;
        case DOUBLE_TAP: register_code16(KC_9); register_code16(KC_9); break;
        case DOUBLE_HOLD: register_code16(KC_RBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_9); register_code16(KC_9);
    }
}

void dance_9_rprn_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_9_RPRN].step) {
        case SINGLE_TAP: unregister_code16(KC_9); break;
        case SINGLE_HOLD: unregister_code16(KC_RPRN); break;
        case DOUBLE_TAP: unregister_code16(KC_9); break;
        case DOUBLE_HOLD: unregister_code16(KC_RBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_9); break;
    }
    dance_state[DANCE_9_RPRN].step = 0;
}
void on_dance_0_dot_l(tap_dance_state_t *state, void *user_data);
void dance_0_dot_l_finished(tap_dance_state_t *state, void *user_data);
void dance_0_dot_l_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0_dot_l(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_0);
        tap_code16(KC_0);
        tap_code16(KC_0);
    }
    if(state->count > 3) {
        tap_code16(KC_0);
    }
}

void dance_0_dot_l_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_0_DOT_L].step = dance_step(state);
    switch (dance_state[DANCE_0_DOT_L].step) {
        case SINGLE_TAP: register_code16(KC_0); break;
        case SINGLE_HOLD: register_code16(KC_DOT); break;
        case DOUBLE_TAP: register_code16(KC_UNDS); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_0); register_code16(KC_0);
    }
}

void dance_0_dot_l_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_0_DOT_L].step) {
        case SINGLE_TAP: unregister_code16(KC_0); break;
        case SINGLE_HOLD: unregister_code16(KC_DOT); break;
        case DOUBLE_TAP: unregister_code16(KC_UNDS); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_0); break;
    }
    dance_state[DANCE_0_DOT_L].step = 0;
}
void on_dance_4_slsh(tap_dance_state_t *state, void *user_data);
void dance_4_slsh_finished(tap_dance_state_t *state, void *user_data);
void dance_4_slsh_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4_slsh(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_4);
        tap_code16(KC_4);
        tap_code16(KC_4);
    }
    if(state->count > 3) {
        tap_code16(KC_4);
    }
}

void dance_4_slsh_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_4_SLSH].step = dance_step(state);
    switch (dance_state[DANCE_4_SLSH].step) {
        case SINGLE_TAP: register_code16(KC_4); break;
        case SINGLE_HOLD: register_code16(KC_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_4); register_code16(KC_4); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_4); register_code16(KC_4);
    }
}

void dance_4_slsh_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_4_SLSH].step) {
        case SINGLE_TAP: unregister_code16(KC_4); break;
        case SINGLE_HOLD: unregister_code16(KC_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_4); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_4); break;
    }
    dance_state[DANCE_4_SLSH].step = 0;
}
void on_dance_5_mins_l(tap_dance_state_t *state, void *user_data);
void dance_5_mins_l_finished(tap_dance_state_t *state, void *user_data);
void dance_5_mins_l_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5_mins_l(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if(state->count > 3) {
        tap_code16(KC_5);
    }
}

void dance_5_mins_l_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_5_MINS_L].step = dance_step(state);
    switch (dance_state[DANCE_5_MINS_L].step) {
        case SINGLE_TAP: register_code16(KC_5); break;
        case SINGLE_HOLD: register_code16(KC_MINUS); break;
        case DOUBLE_TAP: register_code16(KC_5); register_code16(KC_5); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_5); register_code16(KC_5);
    }
}

void dance_5_mins_l_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_5_MINS_L].step) {
        case SINGLE_TAP: unregister_code16(KC_5); break;
        case SINGLE_HOLD: unregister_code16(KC_MINUS); break;
        case DOUBLE_TAP: unregister_code16(KC_5); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_5); break;
    }
    dance_state[DANCE_5_MINS_L].step = 0;
}
void on_dance_6_astr(tap_dance_state_t *state, void *user_data);
void dance_6_astr_finished(tap_dance_state_t *state, void *user_data);
void dance_6_astr_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6_astr(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if(state->count > 3) {
        tap_code16(KC_6);
    }
}

void dance_6_astr_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_6_ASTR].step = dance_step(state);
    switch (dance_state[DANCE_6_ASTR].step) {
        case SINGLE_TAP: register_code16(KC_6); break;
        case SINGLE_HOLD: register_code16(KC_ASTR); break;
        case DOUBLE_TAP: register_code16(KC_6); register_code16(KC_6); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_6); register_code16(KC_6);
    }
}

void dance_6_astr_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_6_ASTR].step) {
        case SINGLE_TAP: unregister_code16(KC_6); break;
        case SINGLE_HOLD: unregister_code16(KC_ASTR); break;
        case DOUBLE_TAP: unregister_code16(KC_6); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_6); break;
    }
    dance_state[DANCE_6_ASTR].step = 0;
}
void on_dance_hash_esc_l(tap_dance_state_t *state, void *user_data);
void dance_hash_esc_l_finished(tap_dance_state_t *state, void *user_data);
void dance_hash_esc_l_reset(tap_dance_state_t *state, void *user_data);

void on_dance_hash_esc_l(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_HASH);
        tap_code16(KC_HASH);
        tap_code16(KC_HASH);
    }
    if(state->count > 3) {
        tap_code16(KC_HASH);
    }
}

void dance_hash_esc_l_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_HASH_ESC_L].step = dance_step(state);
    switch (dance_state[DANCE_HASH_ESC_L].step) {
        case SINGLE_TAP: register_code16(KC_HASH); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_HASH); register_code16(KC_HASH); break;
        case DOUBLE_HOLD: layer_move(_DVORAK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_HASH); register_code16(KC_HASH);
    }
}

void dance_hash_esc_l_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_HASH_ESC_L].step) {
        case SINGLE_TAP: unregister_code16(KC_HASH); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HASH); break;
    }
    dance_state[DANCE_HASH_ESC_L].step = 0;
}
void on_dance_4_astr(tap_dance_state_t *state, void *user_data);
void dance_4_astr_finished(tap_dance_state_t *state, void *user_data);
void dance_4_astr_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4_astr(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_4);
        tap_code16(KC_4);
        tap_code16(KC_4);
    }
    if(state->count > 3) {
        tap_code16(KC_4);
    }
}

void dance_4_astr_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_4_ASTR].step = dance_step(state);
    switch (dance_state[DANCE_4_ASTR].step) {
        case SINGLE_TAP: register_code16(KC_4); break;
        case SINGLE_HOLD: register_code16(KC_ASTR); break;
        case DOUBLE_TAP: register_code16(KC_4); register_code16(KC_4); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_4); register_code16(KC_4);
    }
}

void dance_4_astr_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_4_ASTR].step) {
        case SINGLE_TAP: unregister_code16(KC_4); break;
        case SINGLE_HOLD: unregister_code16(KC_ASTR); break;
        case DOUBLE_TAP: unregister_code16(KC_4); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_4); break;
    }
    dance_state[DANCE_4_ASTR].step = 0;
}
void on_dance_5_mins_r(tap_dance_state_t *state, void *user_data);
void dance_5_mins_r_finished(tap_dance_state_t *state, void *user_data);
void dance_5_mins_r_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5_mins_r(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if(state->count > 3) {
        tap_code16(KC_5);
    }
}

void dance_5_mins_r_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_5_MINS_R].step = dance_step(state);
    switch (dance_state[DANCE_5_MINS_R].step) {
        case SINGLE_TAP: register_code16(KC_5); break;
        case SINGLE_HOLD: register_code16(KC_MINUS); break;
        case DOUBLE_TAP: register_code16(KC_5); register_code16(KC_5); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_5); register_code16(KC_5);
    }
}

void dance_5_mins_r_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_5_MINS_R].step) {
        case SINGLE_TAP: unregister_code16(KC_5); break;
        case SINGLE_HOLD: unregister_code16(KC_MINUS); break;
        case DOUBLE_TAP: unregister_code16(KC_5); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_5); break;
    }
    dance_state[DANCE_5_MINS_R].step = 0;
}
void on_dance_6_slsh(tap_dance_state_t *state, void *user_data);
void dance_6_slsh_finished(tap_dance_state_t *state, void *user_data);
void dance_6_slsh_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6_slsh(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if(state->count > 3) {
        tap_code16(KC_6);
    }
}

void dance_6_slsh_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_6_SLSH].step = dance_step(state);
    switch (dance_state[DANCE_6_SLSH].step) {
        case SINGLE_TAP: register_code16(KC_6); break;
        case SINGLE_HOLD: register_code16(KC_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_6); register_code16(KC_6); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_6); register_code16(KC_6);
    }
}

void dance_6_slsh_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_6_SLSH].step) {
        case SINGLE_TAP: unregister_code16(KC_6); break;
        case SINGLE_HOLD: unregister_code16(KC_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_6); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_6); break;
    }
    dance_state[DANCE_6_SLSH].step = 0;
}
void on_dance_0_dot_r(tap_dance_state_t *state, void *user_data);
void dance_0_dot_r_finished(tap_dance_state_t *state, void *user_data);
void dance_0_dot_r_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0_dot_r(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_0);
        tap_code16(KC_0);
        tap_code16(KC_0);
    }
    if(state->count > 3) {
        tap_code16(KC_0);
    }
}

void dance_0_dot_r_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_0_DOT_R].step = dance_step(state);
    switch (dance_state[DANCE_0_DOT_R].step) {
        case SINGLE_TAP: register_code16(KC_0); break;
        case SINGLE_HOLD: register_code16(KC_DOT); break;
        case DOUBLE_TAP: register_code16(KC_UNDS); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_0); register_code16(KC_0);
    }
}

void dance_0_dot_r_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_0_DOT_R].step) {
        case SINGLE_TAP: unregister_code16(KC_0); break;
        case SINGLE_HOLD: unregister_code16(KC_DOT); break;
        case DOUBLE_TAP: unregister_code16(KC_UNDS); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_0); break;
    }
    dance_state[DANCE_0_DOT_R].step = 0;
}
void on_dance_hash_esc_r(tap_dance_state_t *state, void *user_data);
void dance_hash_esc_r_finished(tap_dance_state_t *state, void *user_data);
void dance_hash_esc_r_reset(tap_dance_state_t *state, void *user_data);

void on_dance_hash_esc_r(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_HASH);
        tap_code16(KC_HASH);
        tap_code16(KC_HASH);
    }
    if(state->count > 3) {
        tap_code16(KC_HASH);
    }
}

void dance_hash_esc_r_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_HASH_ESC_R].step = dance_step(state);
    switch (dance_state[DANCE_HASH_ESC_R].step) {
        case SINGLE_TAP: register_code16(KC_HASH); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_HASH); register_code16(KC_HASH); break;
        case DOUBLE_HOLD: layer_move(_DVORAK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_HASH); register_code16(KC_HASH);
    }
}

void dance_hash_esc_r_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_HASH_ESC_R].step) {
        case SINGLE_TAP: unregister_code16(KC_HASH); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HASH); break;
    }
    dance_state[DANCE_HASH_ESC_R].step = 0;
}
void dance_base_lgui_finished(tap_dance_state_t *state, void *user_data);
void dance_base_lgui_reset(tap_dance_state_t *state, void *user_data);

void dance_base_lgui_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_BASE_LGUI].step = dance_step(state);
    switch (dance_state[DANCE_BASE_LGUI].step) {
        case SINGLE_TAP: layer_move(_DVORAK); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: layer_move(_DVORAK); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: layer_move(_DVORAK); break;
    }
}

void dance_base_lgui_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_BASE_LGUI].step) {
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
    }
    dance_state[DANCE_BASE_LGUI].step = 0;
}
void dance_base_rgui_finished(tap_dance_state_t *state, void *user_data);
void dance_base_rgui_reset(tap_dance_state_t *state, void *user_data);

void dance_base_rgui_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_BASE_RGUI].step = dance_step(state);
    switch (dance_state[DANCE_BASE_RGUI].step) {
        case SINGLE_TAP: layer_move(_DVORAK); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: layer_move(_DVORAK); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT_SHIFT); break;
        case DOUBLE_SINGLE_TAP: layer_move(_DVORAK); break;
    }
}

void dance_base_rgui_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_BASE_RGUI].step) {
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT_SHIFT); break;
    }
    dance_state[DANCE_BASE_RGUI].step = 0;
}
void on_dance_slsh_esc(tap_dance_state_t *state, void *user_data);
void dance_slsh_esc_finished(tap_dance_state_t *state, void *user_data);
void dance_slsh_esc_reset(tap_dance_state_t *state, void *user_data);

void on_dance_slsh_esc(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_slsh_esc_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_SLSH_ESC].step = dance_step(state);
    switch (dance_state[DANCE_SLSH_ESC].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_BSLS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_slsh_esc_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_SLSH_ESC].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[DANCE_SLSH_ESC].step = 0;
}
void on_dance_ent_l(tap_dance_state_t *state, void *user_data);
void dance_ent_l_finished(tap_dance_state_t *state, void *user_data);
void dance_ent_l_reset(tap_dance_state_t *state, void *user_data);

void on_dance_ent_l(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_ent_l_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_ENT_L].step = dance_step(state);
    switch (dance_state[DANCE_ENT_L].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_ENTER)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_ent_l_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_ENT_L].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_ENTER)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[DANCE_ENT_L].step = 0;
}
void on_dance_ent_r(tap_dance_state_t *state, void *user_data);
void dance_ent_r_finished(tap_dance_state_t *state, void *user_data);
void dance_ent_r_reset(tap_dance_state_t *state, void *user_data);

void on_dance_ent_r(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_ent_r_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_ENT_R].step = dance_step(state);
    switch (dance_state[DANCE_ENT_R].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: register_code16(RSFT(KC_ENTER)); break;
        case DOUBLE_TAP: register_code16(RGUI(KC_ENTER)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_ent_r_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_ENT_R].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD: unregister_code16(RSFT(KC_ENTER)); break;
        case DOUBLE_TAP: unregister_code16(RGUI(KC_ENTER)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[DANCE_ENT_R].step = 0;
}
void dance_sft_alt_finished(tap_dance_state_t *state, void *user_data);
void dance_sft_alt_reset(tap_dance_state_t *state, void *user_data);

void dance_sft_alt_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_SFT_ALT].step = dance_step(state);
    switch (dance_state[DANCE_SFT_ALT].step) {
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_ALT); break;
    }
}

void dance_sft_alt_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_SFT_ALT].step) {
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
    }
    dance_state[DANCE_SFT_ALT].step = 0;
}
void on_dance_f6_gui(tap_dance_state_t *state, void *user_data);
void dance_f6_gui_finished(tap_dance_state_t *state, void *user_data);
void dance_f6_gui_reset(tap_dance_state_t *state, void *user_data);

void on_dance_f6_gui(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_f6_gui_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_F6_GUI].step = dance_step(state);
    switch (dance_state[DANCE_F6_GUI].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(KC_F6); register_code16(KC_F6); break;
        case DOUBLE_HOLD: register_code16(LGUI(KC_F6)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_f6_gui_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_F6_GUI].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(KC_F6)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[DANCE_F6_GUI].step = 0;
}
void dance_sft_ctl_finished(tap_dance_state_t *state, void *user_data);
void dance_sft_ctl_reset(tap_dance_state_t *state, void *user_data);

void dance_sft_ctl_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_SFT_CTL].step = dance_step(state);
    switch (dance_state[DANCE_SFT_CTL].step) {
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_CTRL); break;
    }
}

void dance_sft_ctl_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_SFT_CTL].step) {
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
    }
    dance_state[DANCE_SFT_CTL].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_NUM_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_num_fn_finished, dance_num_fn_reset),
        [DANCE_SLSH_ARROWS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_slsh_arrows, dance_slsh_arrows_finished, dance_slsh_arrows_reset),
        [DANCE_CLIPBOARD] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_clipboard, dance_clipboard_finished, dance_clipboard_reset),
        [DANCE_SAVE_UNDO] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_save_undo, dance_save_undo_finished, dance_save_undo_reset),
        [DANCE_SPC_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_spc_shift, dance_spc_shift_finished, dance_spc_shift_reset),
        [DANCE_ENT_SHORTCUTS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ent_shortcuts, dance_ent_shortcuts_finished, dance_ent_shortcuts_reset),
        [DANCE_ARROWS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_arrows_finished, dance_arrows_reset),
        [DANCE_NUM_ARROWS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_num_arrows_finished, dance_num_arrows_reset),
        [DANCE_ENT_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ent_shift, dance_ent_shift_finished, dance_ent_shift_reset),
        [DANCE_A_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_a_s, dance_a_s_finished, dance_a_s_reset),
        [DANCE_O_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_o_n, dance_o_n_finished, dance_o_n_reset),
        [DANCE_E_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_e_t, dance_e_t_finished, dance_e_t_reset),
        [DANCE_U_H] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_u_h, dance_u_h_finished, dance_u_h_reset),
        [DANCE_SCLN_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_scln_z, dance_scln_z_finished, dance_scln_z_reset),
        [DANCE_K_M] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_k_m, dance_k_m_finished, dance_k_m_reset),
        [DANCE_X_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_x_b, dance_x_b_finished, dance_x_b_reset),
        [DANCE_QW_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_qw_a, dance_qw_a_finished, dance_qw_a_reset),
        [DANCE_QW_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_qw_s, dance_qw_s_finished, dance_qw_s_reset),
        [DANCE_QW_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_qw_d, dance_qw_d_finished, dance_qw_d_reset),
        [DANCE_QW_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_qw_f, dance_qw_f_finished, dance_qw_f_reset),
        [DANCE_QW_ARROWS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_qw_arrows_finished, dance_qw_arrows_reset),
        [DANCE_ENT_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ent_num, dance_ent_num_finished, dance_ent_num_reset),
        [DANCE_7_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7_lprn, dance_7_lprn_finished, dance_7_lprn_reset),
        [DANCE_9_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9_rprn, dance_9_rprn_finished, dance_9_rprn_reset),
        [DANCE_0_DOT_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0_dot_l, dance_0_dot_l_finished, dance_0_dot_l_reset),
        [DANCE_4_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4_slsh, dance_4_slsh_finished, dance_4_slsh_reset),
        [DANCE_5_MINS_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5_mins_l, dance_5_mins_l_finished, dance_5_mins_l_reset),
        [DANCE_6_ASTR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6_astr, dance_6_astr_finished, dance_6_astr_reset),
        [DANCE_HASH_ESC_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_hash_esc_l, dance_hash_esc_l_finished, dance_hash_esc_l_reset),
        [DANCE_4_ASTR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4_astr, dance_4_astr_finished, dance_4_astr_reset),
        [DANCE_5_MINS_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5_mins_r, dance_5_mins_r_finished, dance_5_mins_r_reset),
        [DANCE_6_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6_slsh, dance_6_slsh_finished, dance_6_slsh_reset),
        [DANCE_0_DOT_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0_dot_r, dance_0_dot_r_finished, dance_0_dot_r_reset),
        [DANCE_HASH_ESC_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_hash_esc_r, dance_hash_esc_r_finished, dance_hash_esc_r_reset),
        [DANCE_BASE_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_base_lgui_finished, dance_base_lgui_reset),
        [DANCE_BASE_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_base_rgui_finished, dance_base_rgui_reset),
        [DANCE_SLSH_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_slsh_esc, dance_slsh_esc_finished, dance_slsh_esc_reset),
        [DANCE_ENT_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ent_l, dance_ent_l_finished, dance_ent_l_reset),
        [DANCE_ENT_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ent_r, dance_ent_r_finished, dance_ent_r_reset),
        [DANCE_SFT_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sft_alt_finished, dance_sft_alt_reset),
        [DANCE_F6_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f6_gui, dance_f6_gui_finished, dance_f6_gui_reset),
        [DANCE_SFT_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sft_ctl_finished, dance_sft_ctl_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case TH_Q_ESC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_Q);
        } else {
          unregister_code16(KC_Q);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case TH_K_TAB:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_K);
        } else {
          unregister_code16(KC_K);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }  
      }  
      return false;
    case TH_X_ESC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_X);
        } else {
          unregister_code16(KC_X);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case TH_ESC_TAB:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }  
      }  
      return false;
    case TH_SLSH_BSLS:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_SLASH);
        } else {
          unregister_code16(KC_SLASH);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_BSLS);
        } else {
          unregister_code16(KC_BSLS);
        }  
      }  
      return false;
    case TH_MINS_UNDS:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_MINUS);
        } else {
          unregister_code16(KC_MINUS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_UNDS);
        } else {
          unregister_code16(KC_UNDS);
        }  
      }  
      return false;
    case TH_B_ESC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_B);
        } else {
          unregister_code16(KC_B);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case TH_M_TAB:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_M);
        } else {
          unregister_code16(KC_M);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }  
      }  
      return false;
    case TH_V_ESC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_V);
        } else {
          unregister_code16(KC_V);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case TH_CAP_A_LSFT:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_A));
        } else {
          unregister_code16(LSFT(KC_A));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case TH_CAP_O_LCTL:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_O));
        } else {
          unregister_code16(LSFT(KC_O));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case TH_CAP_E_LALT:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_E));
        } else {
          unregister_code16(LSFT(KC_E));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case TH_CAP_U_LGUI:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_U));
        } else {
          unregister_code16(LSFT(KC_U));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case TH_CAP_H_RGUI:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_H));
        } else {
          unregister_code16(LSFT(KC_H));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
        }  
      }  
      return false;
    case TH_CAP_T_LALT:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_T));
        } else {
          unregister_code16(LSFT(KC_T));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case TH_CAP_N_RCTL:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_N));
        } else {
          unregister_code16(LSFT(KC_N));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case TH_CAP_S_RSFT:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_S));
        } else {
          unregister_code16(LSFT(KC_S));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case TH_QUOT_L:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_QUOTE);
        } else {
          unregister_code16(KC_QUOTE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_L);
        } else {
          unregister_code16(KC_L);
        }  
      }  
      return false;
    case TH_COMM_R:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_COMMA);
        } else {
          unregister_code16(KC_COMMA);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_R);
        } else {
          unregister_code16(KC_R);
        }  
      }  
      return false;
    case TH_DOT_C:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DOT);
        } else {
          unregister_code16(KC_DOT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_C);
        } else {
          unregister_code16(KC_C);
        }  
      }  
      return false;
    case TH_P_G:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_P);
        } else {
          unregister_code16(KC_P);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_G);
        } else {
          unregister_code16(KC_G);
        }  
      }  
      return false;
    case TH_Y_F:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_Y);
        } else {
          unregister_code16(KC_Y);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_F);
        } else {
          unregister_code16(KC_F);
        }  
      }  
      return false;
    case TH_I_D:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_I);
        } else {
          unregister_code16(KC_I);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_D);
        } else {
          unregister_code16(KC_D);
        }  
      }  
      return false;
    case TH_Q_V:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_Q);
        } else {
          unregister_code16(KC_Q);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_V);
        } else {
          unregister_code16(KC_V);
        }  
      }  
      return false;
    case TH_J_W:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_J);
        } else {
          unregister_code16(KC_J);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_W);
        } else {
          unregister_code16(KC_W);
        }  
      }  
      return false;
    case TH_BASE_MEDIA:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          layer_move(_DVORAK);
        } else {
          layer_move(_DVORAK);
        }
      } else {
        if (record->event.pressed) {
          layer_move(_MEDIA);
        } else {
          layer_move(_MEDIA);
        }  
      }  
      return false;
    case TH_ENT_TAB:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_ENTER);
        } else {
          unregister_code16(KC_ENTER);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }  
      }  
      return false;
    case TH_8_DOT:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_8);
        } else {
          unregister_code16(KC_8);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_DOT);
        } else {
          unregister_code16(KC_DOT);
        }  
      }  
      return false;
    case TH_COMM_COLN:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_COMMA);
        } else {
          unregister_code16(KC_COMMA);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_COLN);
        } else {
          unregister_code16(KC_COLN);
        }  
      }  
      return false;
    case TH_1_DOT:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_1);
        } else {
          unregister_code16(KC_1);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_DOT);
        } else {
          unregister_code16(KC_DOT);
        }  
      }  
      return false;
    case TH_2_PLUS:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_2);
        } else {
          unregister_code16(KC_2);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_PLUS);
        } else {
          unregister_code16(KC_PLUS);
        }  
      }  
      return false;
    case TH_3_TAB:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_3);
        } else {
          unregister_code16(KC_3);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }  
      }  
      return false;
    case TH_COMM_SPC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_COMMA);
        } else {
          unregister_code16(KC_COMMA);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_SPACE);
        } else {
          unregister_code16(KC_SPACE);
        }  
      }  
      return false;
    case TH_0_DOT:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_0);
        } else {
          unregister_code16(KC_0);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_DOT);
        } else {
          unregister_code16(KC_DOT);
        }  
      }  
      return false;
    case TH_7_LBRC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_7);
        } else {
          unregister_code16(KC_7);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LBRC);
        } else {
          unregister_code16(KC_LBRC);
        }  
      }  
      return false;
    case TH_9_RBRC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_9);
        } else {
          unregister_code16(KC_9);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RBRC);
        } else {
          unregister_code16(KC_RBRC);
        }  
      }  
      return false;
    case TH_1_TAB:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_1);
        } else {
          unregister_code16(KC_1);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }  
      }  
      return false;
    case TH_SHARROWS_ESC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          layer_move(_SHIFTED_ARROWS);
        } else {
          layer_move(_SHIFTED_ARROWS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case TH_ARROWS_ESC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          layer_move(_ARROWS);
        } else {
          layer_move(_ARROWS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case TH_BASE_LGUI:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          layer_move(_DVORAK);
        } else {
          layer_move(_DVORAK);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case TH_BASE_RGUI:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          layer_move(_DVORAK);
        } else {
          layer_move(_DVORAK);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
        }  
      }  
      return false;
    case TH_QUES_TAB:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_QUES);
        } else {
          unregister_code16(KC_QUES);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }  
      }  
      return false;
    case TH_BSLS_ESC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_BSLS);
        } else {
          unregister_code16(KC_BSLS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case TH_HASH_TAB:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_HASH);
        } else {
          unregister_code16(KC_HASH);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }  
      }  
      return false;
    case TH_GRV_BASE:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_GRAVE);
        } else {
          unregister_code16(KC_GRAVE);
        }
      } else {
        if (record->event.pressed) {
          layer_move(_DVORAK);
        } else {
          layer_move(_DVORAK);
        }  
      }  
      return false;
    case TH_SPC_TAB:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_SPACE);
        } else {
          unregister_code16(KC_SPACE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }  
      }  
      return false;
    case TH_LCBR_LABK:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LCBR);
        } else {
          unregister_code16(KC_LCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LABK);
        } else {
          unregister_code16(KC_LABK);
        }  
      }  
      return false;
    case TH_RCBR_RABK:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RCBR);
        } else {
          unregister_code16(KC_RCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RABK);
        } else {
          unregister_code16(KC_RABK);
        }  
      }  
      return false;
    case TH_HASH_ESC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_HASH);
        } else {
          unregister_code16(KC_HASH);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case TH_LPRN_LCBR:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LPRN);
        } else {
          unregister_code16(KC_LPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LCBR);
        } else {
          unregister_code16(KC_LCBR);
        }  
      }  
      return false;
    case TH_RPRN_RCBR:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RPRN);
        } else {
          unregister_code16(KC_RPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RCBR);
        } else {
          unregister_code16(KC_RCBR);
        }  
      }  
      return false;
    case TH_RABK_LABK:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RABK);
        } else {
          unregister_code16(KC_RABK);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LABK);
        } else {
          unregister_code16(KC_LABK);
        }  
      }  
      return false;
    case TH_F12_ESC:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_F12);
        } else {
          unregister_code16(KC_F12);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case TH_NEWTAB_REOPEN:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LGUI(KC_T));
        } else {
          unregister_code16(LGUI(KC_T));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LGUI(LSFT(KC_T)));
        } else {
          unregister_code16(LGUI(LSFT(KC_T)));
        }  
      }  
      return false;
    case TH_UNDO_REDO:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LGUI(KC_Z));
        } else {
          unregister_code16(LGUI(KC_Z));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LGUI(LSFT(KC_Z)));
        } else {
          unregister_code16(LGUI(LSFT(KC_Z)));
        }  
      }  
      return false;
    case RGB_SLD:
        if (record->event.pressed) {
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        }
        return false;
  }
  return true;
}

