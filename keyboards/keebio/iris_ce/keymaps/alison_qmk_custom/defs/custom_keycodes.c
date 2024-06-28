// #include QMK_KEYBOARD_H

#include "features/achordion.h"
#include "features/layer_lock.h"
#include "features/select_word.h"


// Complex custom keycodes (here to prevent circular referencing)
enum custom_keycodes {
    LLOCK = SAFE_RANGE,  // https://getreuer.info/posts/keyboards/layer-lock/index.html
    SELECT_WORD = SAFE_RANGE  // https://getreuer.info/posts/keyboards/select-word/index.html
};


// Define keycodes 
// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_O LCTL_T(KC_O)
#define HOME_E LALT_T(KC_E)
#define HOME_U LGUI_T(KC_U)
#define HOME_I HYPR_T(KC_I)

// Right-hand home row mods
#define HOME_D MEH_T(KC_D)
#define HOME_H RGUI_T(KC_H)
#define HOME_T LALT_T(KC_T)
#define HOME_N RCTL_T(KC_N)
#define HOME_S RSFT_T(KC_S)


// cut copy paste undo redo
#define s_cut LGUI(KC_X)
#define s_copy LGUI(KC_C)
#define s_paste LGUI(KC_V)
#define s_save LGUI(KC_S)
#define s_undo LGUI(KC_Z)
#define s_redo LSG(KC_Z)



// Layer Toggles
#define GO_HOME TO(_DVORAK)

#define TG_LYRS TT(_LAYERS)
#define TG_NUM TG(_NUMPAD)

#define TMP_SYMB OSL(_SYMBOLS)
#define TMP_BRKT OSL(_BRACKETS)
#define TMP_FUNC OSL(_FN)


#define SHFT_SPC LT(_DVORAK_SHIFTED, KC_SPC)
#define SHFT_ENT LT(_DVORAK_SHIFTED, KC_ENT)
#define DV_SPC LT(_DVORAK_SHIFTED, KC_SPC) 
#define DV_ENT LT(_DVORAK_SHIFTED, KC_ENT)


#define TO_QWR TO(_QWERTY)
#define TO_LYR TO(_LAYERS)
#define TO_MED TO(_MEDIA)
#define TO_ARR TO(_ARROWS)
#define TO_SYM TO(_SYMBOLS)
#define TO_BRK TO(_BRACKETS)
#define TO_FN TO(_FN)

#define MO_QWR MO(_QWERTY)
#define MO_LYR MO(_LAYERS)
#define MO_MED MO(_MEDIA)
#define MO_ARR MO(_ARROWS)
#define MO_SYM MO(_SYMBOLS)
#define MO_BRK MO(_BRACKETS)
#define MO_FN MO(_FN)

#define TM_QWR OSL(_QWERTY)
#define TM_LYR OSL(_LAYERS)
#define TM_MED OSL(_MEDIA)
#define TM_ARR OSL(_ARROWS)
#define TM_SYM OSL(_SYMBOLS)
#define TM_BRK OSL(_BRACKETS)
#define TM_FN OSL(_FN)

