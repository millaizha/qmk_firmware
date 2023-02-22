// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

// Cantor remix keymap by @millaizha

#include QMK_KEYBOARD_H

// Layers
#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
#define _LAYER5 5
#define _LAYER6 6
#define _LAYER7 7
#define _LAYER8 8
#define _LAYER9 9

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
#define SPC_7 LT(8,KC_SPC)
#define DEL_2 LT(2,KC_DEL)

// Modifier key shortcuts
#define LOCK_PC LGUI(KC_L)
#define SNIP_PC SGUI(KC_S)
#define SETTINGS LGUI(KC_I)

// Multi-tap function tap dance
enum multi_tap_dance 
{
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
};

typedef struct
{
    bool is_press_action;
    int state;
} td_tap_t;

enum custom_keycodes 
{
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
    LAYER6,
    LAYER7,
    LAYER8,
    LAYER9,
};

// Tap dance and custom keycodes declarations
enum 
{
    COPY_C,
    CUT_X,
    PASTE_V,
    BSPC_T_DANCE,
    LOL_T_DANCE,
    GAME_CHAT,
    GAME
};

// Multi tap dance functions
int cur_dance(qk_tap_dance_state_t *state) 
{
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
};

// Tap dance config for game team/all chat
void td_game_chat_finished(qk_tap_dance_state_t *state, void *user_data) 
{
    layer_on(7);
    if (state->count == 1) {
        register_code16(KC_ENT);
    } else {
        register_code16(LSFT(KC_ENT));
    }
};

void td_game_chat_reset(qk_tap_dance_state_t *state, void *user_data) 
{
    if (state->count == 1) {
        unregister_code16(KC_ENT);
    } else {
        unregister_code16(LSFT(KC_ENT));
    }
};

// Key event after chatting in game
bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch (keycode) {
        case GAME:
            if (record->event.pressed) {
                register_code16(KC_ENT);
                layer_off(7);
                unregister_code16(KC_ENT);
            }
            break;
    }
    return true;
};

// LOL quad tap dance
static td_tap_t lol_tap_state = 
{
    .is_press_action = true,
    .state = 0
};

void td_lol_finished(qk_tap_dance_state_t *state, void *user_data) 
{
    lol_tap_state.state = cur_dance(state);
    switch (lol_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_P); break;
        case TD_SINGLE_HOLD: register_code(KC_TAB); break;
        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: layer_on(9);
    }
};

void td_lol_reset(qk_tap_dance_state_t *state, void *user_data) 
{
    switch (lol_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_P); break;
        case TD_SINGLE_HOLD: unregister_code(KC_TAB); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: layer_off(9);
    }
    lol_tap_state.state = 0;
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = 
{
    // Tap once for C, twice for Copy
    [COPY_C] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C)),
    // Tap once for X, twice for Cut
    [CUT_X] = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL(KC_X)),
    // Tap once for V, twice for Paste
    [PASTE_V] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V)),
    // Tap once for Enter, twice for Shift + Enter
    [GAME_CHAT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_game_chat_finished, td_game_chat_reset),
    // Tap once for Grave, twice for Escape. Hold for Tab, tap + hold for MO(10)
    [LOL_T_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lol_finished, td_lol_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{

  [_LAYER0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   GUI_A,   ALT_R,   CTL_S,  SHFT_T,   KC_G,                         KC_M,    SFT_N,   CTL_E,   ALT_I,  GUI_O,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   KC_Z, TD(CUT_X), TD(COPY_C), KC_D, TD(PASTE_V),                   KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  ESC_4, BSPC_3, TAB_5,         ENT_3, SPC_1, DEL_2
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, KC_LBRC,   KC_7,    KC_8,    KC_9,  KC_RBRC,                        KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_SCLN,   KC_4,    KC_5,    KC_6,  KC_EQL,                         KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_GRV,    KC_1,    KC_2,    KC_3,  KC_BSLS,                        KC_NO, KC_COMM,  KC_SPC, KC_BSPC,  KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  KC_DOT, KC_0, KC_MINS,        KC_NO, KC_TRNS, KC_NO
                                            //`--------------------------'  `--------------------------'

    ),
    [_LAYER2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,  KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,  KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_TILD, KC_EXLM,  KC_AT,  KC_HASH, KC_PIPE,                      KC_BTN3, KC_BTN4, KC_BTN5, KC_WH_U, KC_WH_R,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               KC_LPRN, KC_RPRN, KC_UNDS,       KC_NO, KC_NO, KC_TRNS
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, KC_CALC, KC_MPRV, KC_MPLY, KC_MNXT, LOCK_PC,                       KC_NO,  KC_RALT,  KC_UP,  KC_TAB,  KC_FIND,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, SNIP_PC,                      KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, SETTINGS, KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_MYCM, KC_MUTE, KC_VOLD, KC_VOLU, KC_F13,                       KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,   KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 KC_NO, KC_TRNS, KC_NO,         KC_TRNS, KC_NO, KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_PSCR,                      KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,  KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_SCRL,                      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,  KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_PAUS,                      KC_BTN3, KC_BTN4, KC_BTN5, KC_WH_U, KC_WH_R,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 KC_TRNS, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER5] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  KC_NO,   KC_NO,   KC_NO,   TO(6),   KC_NO,                        KC_NO,   KC_LEFT,KC_DOWN, KC_RGHT,  KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  KC_NO, KC_NO, KC_TRNS,        KC_NO, KC_NO, KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER6] = LAYOUT_split_3x6_3(
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
    [_LAYER7] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   GUI_A,   ALT_R,   CTL_S,  SHFT_T,   KC_G,                         KC_M,    SFT_N,   CTL_E,   ALT_I,  GUI_O,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   KC_Z,    KC_X, TD(COPY_C), KC_D, TD(PASTE_V),                     KC_K,    KC_H,  KC_COMM, KC_DOT,  KC_SLSH,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LSFT, KC_BSPC, KC_TAB,       GAME, SPC_7, KC_CAPS
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER8] = LAYOUT_split_3x6_3(
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
    [_LAYER9] = LAYOUT_split_3x6_3(
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
