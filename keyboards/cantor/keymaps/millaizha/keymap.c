// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

// Cantor remix keymap by @millaizha

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "action_tapping.h"

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
#define ESC_1 LT(5,KC_ESC)
#define BSPC_2 LT(2,KC_BSPC)
#define TAB_3 LT(3,KC_TAB)
#define SPC_4 LT(4,KC_SPC)
#define BSPC_8 LT(8,KC_SPC)
#define DEL_5 LT(5,KC_DEL)

// Modifier key shortcuts
#define LOCK_PC LGUI(KC_L)
#define SNIP_PC SGUI(KC_S)
#define SETTINGS LGUI(KC_I)

// Multi-tap function tap dance
typedef enum multi_tap_dance 
{
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

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
    COPY_Q,
    CUT_X,
    PASTE_V,
    UNDO_Z,
    BSPC_T_DANCE,
    LOL_T_DANCE,
    GAME_CHAT,
    GAME
};

// Multi tap dance functions
int cur_dance(tap_dance_state_t *state)
{
    if (state->count == 1) 
    {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) 
    {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else if (state->count == 3) 
    {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return 7;
};

// Tap dance config for game team/all chat
void td_game_chat_finished(tap_dance_state_t *state, void *user_data) 
{
    layer_on(7);
    if (state->count == 1) 
    {
        register_code16(KC_ENT);
    } else 
    {
        register_code16(LSFT(KC_ENT));
    }
};

void td_game_chat_reset(tap_dance_state_t *state, void *user_data) 
{
    if (state->count == 1) 
    {
        unregister_code16(KC_ENT);
    } else 
    {
        unregister_code16(LSFT(KC_ENT));
    }
};

// Key event after chatting in game
bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch (keycode) {
        case GAME:
            if (record->event.pressed) 
            {
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

void td_lol_finished(tap_dance_state_t *state, void *user_data) 
{
    lol_tap_state.state = cur_dance(state);
    switch (lol_tap_state.state) 
    {
        case TD_SINGLE_TAP: register_code(KC_P); break;
        case TD_SINGLE_HOLD: register_code(KC_TAB); break;
        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: layer_on(9);
    }
};

void td_lol_reset(tap_dance_state_t *state, void *user_data) 
{
    switch (lol_tap_state.state) 
    {
        case TD_SINGLE_TAP: unregister_code(KC_P); break;
        case TD_SINGLE_HOLD: unregister_code(KC_TAB); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: layer_off(9);
    }
    lol_tap_state.state = 0;
};

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = 
{
    // Tap once for Q, twice for Copy
    [COPY_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LCTL(KC_C)),
    // Tap once for X, twice for Cut
    [CUT_X] = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL(KC_X)),
    // Tap once for V, twice for Paste
    [PASTE_V] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V)),
    // Tap once for Z, twice for Undo
    [UNDO_Z] = ACTION_TAP_DANCE_DOUBLE(KC_Z, LCTL(KC_Z)),
    // Tap once for Enter, twice for Shift + Enter
    [GAME_CHAT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_game_chat_finished, td_game_chat_reset),
    // Tap once for P, twice for Escape. Hold for Tab, tap + hold for MO(10)
    [LOL_T_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lol_finished, td_lol_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{

  [_LAYER0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,TD(COPY_Q), KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,   GUI_A,   ALT_R,   CTL_S,  SHFT_T,   KC_G,                         KC_M,    SFT_N,   CTL_E,   ALT_I,  GUI_O,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,TD(UNDO_Z),TD(CUT_X),  KC_C,  KC_D, TD(PASTE_V),                     KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  ESC_1, BSPC_2, TAB_3,       KC_ENT,  SPC_4,    DEL_5
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,  KC_NO,   KC_NO,  KC_BRID, KC_BRIU,  KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  KC_NO,  KC_MPRV, KC_MPLY, KC_MNXT,  KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  KC_NO,   KC_NO,  KC_VOLD, KC_VOLU, KC_MUTE,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_TRNS, KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_GRV,                       KC_SCLN, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_BSLS, KC_LBRC, KC_LCBR, KC_MINS, KC_EQL,                       KC_PLUS, KC_UNDS, KC_RCBR, KC_RBRC, KC_PIPE,  KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               KC_BSPC, KC_TRNS, KC_ENT,       KC_SPC, KC_COMM, KC_DOT
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_F11,                        KC_F12, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  TO(6),  KC_CALC, G(KC_1), G(KC_2), KC_PSCR,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_DOT, KC_CAPS, KC_TRNS,     KC_NO,   KC_NO,   KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC,KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TILD,                       KC_COLN,KC_LEFT,  KC_UP,  KC_DOWN, KC_RIGHT, KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_LT,   KC_GT,  KC_QUES,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_NO,   KC_NO,   KC_NO,      KC_NO,  KC_TRNS,  KC_NO
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER5] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO, MS_ACL0,  KC_NO,  MS_BTN5, MS_BTN4,  KC_NO,                     MS_WHLU,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, MS_ACL1, MS_BTN3, MS_BTN2, MS_BTN1,  KC_NO,                   MS_WHLD, MS_LEFT, MS_UP, MS_DOWN, MS_RGHT, KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, MS_ACL2, MS_BTN6, MS_BTN7, MS_BTN8,  KC_NO,                   KC_NO, MS_WHLL, MS_WHLR, KC_NO,   KC_NO,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               KC_TRNS, KC_LCTL, KC_LSFT,       KC_NO, KC_NO, KC_TRNS
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
             KC_NO,   KC_Z,    KC_X, TD(COPY_Q), KC_D, TD(PASTE_V),                     KC_K,    KC_H,  KC_COMM, KC_DOT,  KC_SLSH,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               KC_LSFT,  BSPC_8, KC_TAB,       GAME,   KC_SPC, KC_CAPS
                                            //`--------------------------'  `--------------------------'
    ),
    [_LAYER8] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_GRV,                       KC_SCLN, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,  KC_NO, 
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_NO, KC_BSLS, KC_LBRC, KC_LCBR, KC_MINS, KC_EQL,                       KC_PLUS, KC_UNDS, KC_RCBR, KC_RBRC, KC_PIPE,  KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               KC_BSPC, KC_TRNS, KC_ENT,       KC_SPC, KC_COMM, KC_DOT
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
