/* Copyright 2020 LAZYDESIGNERS
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


// Tap Dance declarations
enum {
    // tap dance
    TD_QUES, // forward slash and question mark
    TD_CLN, // semi-colon and colon
    TD_QUOT, // single quote and double quote
    };


#define TAB_CTL MT(MOD_LCTL, C(KC_TAB)) // hold ctrl, tap ctrl+tab
#define TAB_GUI MT(MOD_LGUI, G(KC_TAB)) // hold gui, tap gui+tab
#define COPY_ALT MT(MOD_LALT, G(KC_C)) // hold alt, tap copy

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO

int cur_dance (qk_tap_dance_state_t *state);
void alt_finished (qk_tap_dance_state_t *state, void *user_data);
void alt_reset (qk_tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                 KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    A(KC_BSPC),
                 MEH_T(KC_TAB),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_QUOT), TD(TD_CLN),
                 SFT_T(KC_HOME),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             TD(TD_QUES),    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   TG(3),
                 TAB_CTL,  GUI_T(KC_HOME),                  LALT_T(KC_BSPC), LT(2,KC_ENT),           LT(1,KC_SPC),  HYPR_T(KC_END),                     KC_LEFT, KC_DOWN, KC_RGHT
             ),
    [1] = LAYOUT(
               RGB_TOG,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    G(KC_BSPC),
                 _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_HOME,   KC_LBRC, KC_RBRC,  KC_MINUS, KC_EQUAL, KC_BSLS,
                 _______,    KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,           XXXXXXX,  KC_END,   XXXXXXX,   XXXXXXX,   KC_MPLY,   KC_VOLU,   _______,
               LCTL(KC_TAB),  KC_LGUI,     _______, _______,          _______, _______,                     KC_MPRV,   KC_VOLD,   KC_MNXT
             ),
    [2] = LAYOUT(
                QK_BOOT,    KC_EXLM,   KC_AT,   KC_HASH,   LALT(KC_3),   KC_PERC,        KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   G(KC_BSPC),
               _______,    KC_TILD,   LSA(KC_2),   KC_DLR,   XXXXXXX,   XXXXXXX,      RGB_HUI,   RGB_VAI,   RGB_VAI,   KC_MINUS,   KC_PLUS,   KC_BSLS,
                 _______,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,       RGB_HUD,   RGB_VAD,   RGB_VAD,   XXXXXXX,   XXXXXXX,   KC_PGUP,   _______,
               XXXXXXX,    XXXXXXX,         XXXXXXX,   _______,                       _______,   KC_MS_BTN1, LGUI(KC_MINUS),   KC_PGDN,   LGUI(KC_PLUS)
             ),
    [3] = LAYOUT(
               KC_PWR,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_BTN1,   KC_MS_U,   KC_WH_D,   KC_BTN2,   KC_NO,   _______,
               KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_MS_L,   KC_MS_D,   KC_WH_U,   KC_MS_R,   KC_NO,   KC_NO,
                 _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TG(3),
               KC_NO,    KC_NO,                     KC_NO,   _______,            _______,   KC_NO,                     KC_NO,   KC_NO,   KC_NO
             ),
};


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QUES] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUES),
    [TD_QUOT] =  ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),
    [TD_CLN] =  ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
};


// Custom mods bool
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case TAB_CTL:
           if (record->event.pressed && record->tap.count) {
               tap_code16(C(KC_TAB));
               return false;
           }
           break;
    }
    return true;
    
        switch(keycode) {
            case TAB_GUI:
               if (record->event.pressed && record->tap.count) {
                   tap_code16(G(KC_TAB));
                   return false;
               }
               break;
        }
        return true;
    
    switch(keycode) {
        case COPY_ALT:
           if (record->event.pressed && record->tap.count) {
               tap_code16(G(KC_C));
               return false;
           }
           break;
    }
    return true;
};
