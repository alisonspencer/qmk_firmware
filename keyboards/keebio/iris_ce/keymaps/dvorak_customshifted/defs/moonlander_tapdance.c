// #include QMK_KEYBOARD_H



// Tap Dance Declarations
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP = 1,
    TD_SINGLE_HOLD = 2,
    TD_DOUBLE_TAP = 3,
    TD_DOUBLE_HOLD = 4,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;


// Tap dance enums
enum {
    CUT_COPY_PASTE = 0,
    HOLD_ESC, 
    HOLD_TAB
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
   // Tap once for copy, tap twice for paste, hold for cut
   [CUT_COPY_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(),
   // Tap once for Escape, twice for Caps Lock
   [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};



td_state_t cur_dance(tap_dance_state_t *state);

// // For the x tap dance. Put it here so it can be used in any keymap
// void x_finished(tap_dance_state_t *state, void *user_data);
// void x_reset(tap_dance_state_t *state, void *user_data);








static tap dance_state[17];

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



void on_cut_copy_paste(tap_dance_state_t *state, void *user_data);
void cut_copy_paste_finished(tap_dance_state_t *state, void *user_data);
void cut_copy_paste_reset(tap_dance_state_t *state, void *user_data);

void on_cut_copy_paste(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_C));
    }
}

void cut_copy_paste_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case TD_SINGLE_TAP: register_code16(LGUI(KC_C)); break;
        case TD_SINGLE_HOLD: register_code16(LGUI(KC_X)); break;
        case TD_DOUBLE_TAP: register_code16(LGUI(KC_V)); break;
        case TD_DOUBLE_HOLD: register_code16(LGUI(KC_A)); break;
        case TD_DOUBLE_SINGLE_TAP: register_tap_code16(LGUI(KC_C)); break; 
        case TD_TRIPLE_TAP: register_tap_code16(LGUI(KC_Z)); break; 
        case TD_TRIPLE_HOLD: tap_code_16(LGUI(KC_S)); register_code16(LGUI(KC_S)); break;
    }
}

void cut_copy_paste_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case TD_SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
        case TD_SINGLE_HOLD: unregister_code16(LGUI(KC_X)); break;
        case TD_DOUBLE_TAP: unregister_code16(LGUI(KC_V)); break;
        case TD_DOUBLE_HOLD: unregister_code16(LGUI(KC_A)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
        case TD_TRIPLE_TAP: unregister_tap_code16(LGUI(KC_Z)); break; 
        case TD_TRIPLE_HOLD: unregister_code16(LGUI(KC_S)); break;
    }
    dance_state[7].step = 0;
}




void on_dance_k_tab(tap_dance_state_t *state, void *user_data);
void dance_k_tab_finished(tap_dance_state_t *state, void *user_data);
void dance_k_tab_reset(tap_dance_state_t *state, void *user_data);

void on_dance_k_tab(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(kc_k);
        tap_code16(kc_k);
        tap_code16(kc_k);
    }
    if(state->count > 3) {
        tap_code16(kc_k);
    }
}

void dance_k_tab_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case single_tap: register_code16(kc_k); break;
        case single_hold: register_code16(kc_tab); break;
        case double_tap: register_code16(kc_k); register_code16(kc_k); break;
        case double_single_tap: tap_code16(kc_k); register_code16(kc_k);
    }
}

void dance_k_tab_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case single_tap: unregister_code16(kc_k); break;
        case single_hold: unregister_code16(kc_tab); break;
        case double_tap: unregister_code16(kc_k); break;
        case double_single_tap: unregister_code16(kc_k); break;
    }
    dance_state[0].step = 0;
}



void on_dance_x_esc(tap_dance_state_t *state, void *user_data);
void dance_x_esc_finished(tap_dance_state_t *state, void *user_data);
void dance_x_esc_reset(tap_dance_state_t *state, void *user_data);

void on_dance_x_esc(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_x_esc_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void dance_x_esc_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state[1].step = 0;
}



void on_dance_copypaste(tap_dance_state_t *state, void *user_data);
void dance_copypaste_finished(tap_dance_state_t *state, void *user_data);
void dance_copypaste_reset(tap_dance_state_t *state, void *user_data);

void on_dance_copypaste(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(lgui(kc_c));
        tap_code16(lgui(kc_c));
        tap_code16(lgui(kc_c));
    }
    if(state->count > 3) {
        tap_code16(lgui(kc_c));
    }
}

void dance_copypaste_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case single_tap: register_code16(lgui(kc_c)); break;
        case single_hold: register_code16(lgui(kc_x)); break;
        case double_tap: register_code16(lgui(kc_v)); break;
        case double_hold: register_code16(lgui(kc_a)); break;
        case double_single_tap: tap_code16(lgui(kc_c)); register_code16(lgui(kc_c));
    }
}

void dance_copypaste_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case single_tap: unregister_code16(lgui(kc_c)); break;
        case single_hold: unregister_code16(lgui(kc_x)); break;
        case double_tap: unregister_code16(lgui(kc_v)); break;
        case double_hold: unregister_code16(lgui(kc_a)); break;
        case double_single_tap: unregister_code16(lgui(kc_c)); break;
    }
    dance_state[2].step = 0;
}


void on_dance_minus_underscore(tap_dance_state_t *state, void *user_data);
void dance_minus_underscore_finished(tap_dance_state_t *state, void *user_data);
void dance_minus_underscore_reset(tap_dance_state_t *state, void *user_data);

void on_dance_minus_underscore(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(kc_minus);
        tap_code16(kc_minus);
        tap_code16(kc_minus);
    }
    if(state->count > 3) {
        tap_code16(kc_minus);
    }
}

void dance_minus_underscore_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case single_tap: register_code16(kc_minus); break;
        case single_hold: register_code16(kc_unds); break;
        case double_tap: register_code16(kc_minus); register_code16(kc_minus); break;
        case double_single_tap: tap_code16(kc_minus); register_code16(kc_minus);
    }
}

void dance_minus_underscore_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case single_tap: unregister_code16(kc_minus); break;
        case single_hold: unregister_code16(kc_unds); break;
        case double_tap: unregister_code16(kc_minus); break;
        case double_single_tap: unregister_code16(kc_minus); break;
    }
    dance_state[4].step = 0;
}
void on_dance_b_esc(tap_dance_state_t *state, void *user_data);
void dance_b_esc_finished(tap_dance_state_t *state, void *user_data);
void dance_b_esc_reset(tap_dance_state_t *state, void *user_data);

void on_dance_b_esc(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(kc_b);
        tap_code16(kc_b);
        tap_code16(kc_b);
    }
    if(state->count > 3) {
        tap_code16(kc_b);
    }
}

void dance_b_esc_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case single_tap: register_code16(kc_b); break;
        case single_hold: register_code16(kc_escape); break;
        case double_tap: register_code16(kc_b); register_code16(kc_b); break;
        case double_single_tap: tap_code16(kc_b); register_code16(kc_b);
    }
}

void dance_b_esc_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case single_tap: unregister_code16(kc_b); break;
        case single_hold: unregister_code16(kc_escape); break;
        case double_tap: unregister_code16(kc_b); break;
        case double_single_tap: unregister_code16(kc_b); break;
    }
    dance_state[5].step = 0;
}
void on_dance_m_tab(tap_dance_state_t *state, void *user_data);
void dance_m_tab_finished(tap_dance_state_t *state, void *user_data);
void dance_m_tab_reset(tap_dance_state_t *state, void *user_data);

void on_dance_m_tab(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(kc_m);
        tap_code16(kc_m);
        tap_code16(kc_m);
    }
    if(state->count > 3) {
        tap_code16(kc_m);
    }
}

void dance_m_tab_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case single_tap: register_code16(kc_m); break;
        case single_hold: register_code16(kc_tab); break;
        case double_tap: register_code16(kc_m); register_code16(kc_m); break;
        case double_single_tap: tap_code16(kc_m); register_code16(kc_m);
    }
}

void dance_m_tab_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case single_tap: unregister_code16(kc_m); break;
        case single_hold: unregister_code16(kc_tab); break;
        case double_tap: unregister_code16(kc_m); break;
        case double_single_tap: unregister_code16(kc_m); break;
    }
    dance_state[6].step = 0;
}

void on_dance_enter_vars(tap_dance_state_t *state, void *user_data);
void dance_enter_vars_finished(tap_dance_state_t *state, void *user_data);
void dance_enter_vars_reset(tap_dance_state_t *state, void *user_data);

void on_dance_enter_vars(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(kc_enter);
        tap_code16(kc_enter);
        tap_code16(kc_enter);
    }
    if(state->count > 3) {
        tap_code16(kc_enter);
    }
}

void dance_enter_vars_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case single_tap: register_code16(kc_enter); break;
        case double_tap: register_code16(rgui(kc_enter)); break;
        case double_hold: register_code16(kc_space); break;
        case double_single_tap: tap_code16(kc_enter); register_code16(kc_enter);
    }
}

void dance_enter_vars_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case single_tap: unregister_code16(kc_enter); break;
        case double_tap: unregister_code16(rgui(kc_enter)); break;
        case double_hold: unregister_code16(kc_space); break;
        case double_single_tap: unregister_code16(kc_enter); break;
    }
    dance_state[8].step = 0;
}