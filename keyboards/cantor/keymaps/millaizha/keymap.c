// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

// Cantor remix keymap by @millaizha

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

// Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

// Layer-tap mods
#define ESC_4 LT(4,KC_ESC)
#define BSPC_3 LT(3,KC_BSPC)
#define TAB_5 LT(5,KC_TAB)
#define ENT_3 LT(3,KC_ENT)
#define SPC_1 LT(1,KC_SPC)
#define SPC_8 LT(9,KC_SPC)
#define DEL_2 LT(2,KC_DEL)

// Modifier key shortcuts
#define SFT_ENT LSFT(KC_ENT)
#define LOCK_PC LGUI(KC_L)
#define SNIP_PC SGUI(KC_S)
#define SETTINGS LGUI(KC_I)

// Multi-tap function tap dance
enum multi_tap_dance {
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
};

typedef struct {
    bool is_press_action;
    int state;
} td_tap_t;

// Tap dance and custom keycodes declarations
enum custom_keycodes {
    COPY_C,
    CUT_X,
    PASTE_V,
    UNDO_Z,
    TAB_ESC,
    G_CAPS,
    LOL_T_DANCE,
    VALO_T_DANCE,
    GAME_CHAT,
    GAME
};

// Multi tap dance functions
int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return 7;
}

// Tap dance config for game team/all chat
void td_game_chat_finished(qk_tap_dance_state_t *state, void *user_data) {
    layer_on(8);
    if (state->count == 1) {
        register_code16(KC_ENT);
    } else {
        register_code16(SFT_ENT);
    }
}

void td_game_chat_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_ENT);
    } else {
        unregister_code16(SFT_ENT);
    }
}

// Key event after chatting in game
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GAME:
            if (record->event.pressed) {
                register_code16(KC_ENT);
                layer_off(8);
                unregister_code16(KC_ENT);
            }
            break;
    }
    return true;
}

// Game tap-hold dance
static td_tap_t g_tap_state = {
    .is_press_action = true,
    .state = 0
};

static td_tap_t esc_tap_state = {
    .is_press_action = true,
    .state = 0
};

void td_g_finished(qk_tap_dance_state_t *state, void *user_data) {
    g_tap_state.state = cur_dance(state);
    switch (g_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_G); break;
        case TD_SINGLE_HOLD: register_code(KC_CAPS); break;
    }
}

void td_g_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (g_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_G); break;
        case TD_SINGLE_HOLD: unregister_code(KC_CAPS); break;
    }
    g_tap_state.state = 0;
}

void td_esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    esc_tap_state.state = cur_dance(state);
    switch (esc_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ESC); break;
        case TD_SINGLE_HOLD: register_code(KC_TAB); break;
    }
}

void td_esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (esc_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_SINGLE_HOLD: unregister_code(KC_TAB); break;
    }
    esc_tap_state.state = 0;
}

// LOL quad tap dance
static td_tap_t lol_tap_state = {
    .is_press_action = true,
    .state = 0
};

void td_lol_finished(qk_tap_dance_state_t *state, void *user_data) {
    lol_tap_state.state = cur_dance(state);
    switch (lol_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_GRV); break;
        case TD_SINGLE_HOLD: register_code(KC_TAB); break;
        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: layer_on(10);
    }
}

void td_lol_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lol_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_GRV); break;
        case TD_SINGLE_HOLD: unregister_code(KC_TAB); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: layer_off(10);
    }
    lol_tap_state.state = 0;
}

// Valorant quad tap dance
static td_tap_t valo_tap_state = {
    .is_press_action = true,
    .state = 0
};

void td_valo_finished(qk_tap_dance_state_t *state, void *user_data) {
    valo_tap_state.state = cur_dance(state);
    switch (valo_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_B); break;
        case TD_SINGLE_HOLD: register_code(KC_LALT); break;
        case TD_DOUBLE_TAP: register_code(KC_T); break;
        case TD_DOUBLE_HOLD: layer_on(10);
    }
}

void td_valo_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (valo_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_B); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_T); break;
        case TD_DOUBLE_HOLD: layer_off(10);
    }
    valo_tap_state.state = 0;
}

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for C, twice for Copy
    [COPY_C] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C)),
    // Tap once for X, twice for Cut
    [CUT_X] = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL(KC_X)),
    // Tap once for V, twice for Paste
    [PASTE_V] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V)),
    // Tap once for Z, twice for Undo
    [UNDO_Z] = ACTION_TAP_DANCE_DOUBLE(KC_Z, LCTL(KC_Z)),
    // Tap once for Escape, hold for Tab
    [TAB_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_esc_finished, td_esc_reset),
    // Tap once for G, hold for Caps
    [G_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_g_finished, td_g_reset),
    // Tap once for Enter, twice for Shift + Enter
    [GAME_CHAT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_game_chat_finished, td_game_chat_reset),
    // Tap once for Grave, twice for Escape. Hold for Tab, tap + hold for MO(10)
    [LOL_T_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lol_finished, td_lol_reset),
    // Tap once for B, twice for T. Hold for Alt, tap + hold for MO(10)
    [VALO_T_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_valo_finished, td_valo_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   GUI_A,   ALT_R,   CTL_S,  SHFT_T,   KC_G,                         KC_M,    SFT_N,   CTL_E,   ALT_I,  GUI_O,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_NO, TD(UNDO_Z), TD(CUT_X), TD(COPY_C), KC_D, TD(PASTE_V),                KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  ESC_4, BSPC_3, TAB_5,          ENT_3, SPC_1, DEL_2
                                            //`--------------------------'  `--------------------------'
    ),
    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, KC_LBRC,   KC_7,    KC_8,    KC_9,  KC_RBRC,                        KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_SCLN,   KC_4,    KC_5,    KC_6,  KC_EQL,                         KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_GRV,    KC_1,    KC_2,    KC_3,  KC_BSLS,                        KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  KC_DOT, KC_0, KC_MINS,        KC_NO, KC_TRNS, KC_NO
                                            //`--------------------------'  `--------------------------'

    ),
    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      KC_BTN2, KC_RSFT, KC_RCTL, KC_RALT, KC_RSFT,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_TILD, KC_EXLM,  KC_AT,  KC_HASH, KC_PIPE,                      KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               KC_LPRN, KC_RPRN, KC_UNDS,       KC_NO, KC_NO, KC_TRNS
                                            //`--------------------------'  `--------------------------'
    ),
    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, QK_BOOT, KC_MPRV, KC_MPLY, KC_MNXT, LOCK_PC,                       KC_NO,  KC_RALT,  KC_UP,  KC_TAB,  KC_CALC,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, SNIP_PC,                      KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, SETTINGS, KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_MYCM, KC_MUTE, KC_VOLD, KC_VOLU, KC_F13,                       KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,   KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 KC_NO, KC_TRNS, KC_NO,         KC_TRNS, KC_NO, KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_PSCR,                      KC_BTN2, KC_RSFT, KC_RCTL, KC_RALT, KC_ENT,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_SCRL,                      KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_PAUS,                      KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 KC_TRNS, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [5] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  KC_NO,   KC_NO,   TO(7),   TO(6),   KC_NO,                        KC_NO,   KC_LEFT,KC_DOWN, KC_RGHT,  KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  KC_NO, KC_NO, KC_TRNS,        KC_NO, KC_NO, KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [6] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                        KC_NO,  KC_RALT, KC_TAB,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                        KC_NO,  KC_MPRV, KC_MPLY, KC_MNXT,  KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   KC_A,   KC_S,     KC_D,    KC_F,    KC_B,                        KC_NO,  KC_VOLD, KC_VOLU,  KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         TD(LOL_T_DANCE), KC_SPC, KC_LCTL, TD(GAME_CHAT), LALT(KC_Z), TO(0)
                                            //`--------------------------'  `--------------------------'
    ),
    [7] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,TD(TAB_ESC),KC_Q,    KC_W,    KC_E,    KC_R,                        KC_NO,  KC_RALT, KC_TAB,   KC_NO,   KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,                        KC_NO,  KC_MPRV, KC_MPLY, KC_MNXT,  KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_LCTL,   KC_4,    KC_X,    KC_C,    KC_V,                        KC_NO,  KC_VOLD, KC_VOLU,  KC_NO,   KC_NO,   KC_NO,  
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        TD(VALO_T_DANCE), KC_SPC, TD(G_CAPS), TD(GAME_CHAT), LALT(KC_Z), TO(0)
                                            //`--------------------------'  `--------------------------'
    ),
    [8] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   KC_Z,    KC_X, TD(COPY_C), KC_D, TD(PASTE_V),                     KC_K,    KC_H,  KC_COMM, KC_DOT,  KC_SLSH,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LSFT, KC_BSPC, KC_TAB,       GAME, SPC_8, KC_CAPS
                                            //`--------------------------'  `--------------------------'
    ),
    [9] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, KC_LBRC,   KC_7,    KC_8,    KC_9,  KC_RBRC,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_SCLN,   KC_4,    KC_5,    KC_6,  KC_EQL,                        KC_NO,  KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_GRV,    KC_1,    KC_2,    KC_3,  KC_BSLS,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 KC_DOT, KC_0, KC_MINS,        KC_NO, KC_TRNS, KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [10] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_F1,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 KC_TRNS, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO
                                            //`--------------------------'  `--------------------------'
    )
};

