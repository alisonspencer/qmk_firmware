#include "custom_keycodes.c"

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
