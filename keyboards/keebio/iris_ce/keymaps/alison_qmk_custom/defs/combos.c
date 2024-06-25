#include "custom_keycodes.c"

// Combo Definitions
const uint16_t PROGMEM combo_comment[] = { KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM combo_enter[] = { KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo_layerlock[] = { KC_SCLN, KC_Q, KC_DOT, KC_P,  COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_comment, LGUI(KC_SLASH))
    , COMBO(combo_enter, KC_ENTER)
    , COMBO(combo_layerlock, LLOCK)
};
