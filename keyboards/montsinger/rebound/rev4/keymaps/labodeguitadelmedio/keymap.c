#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.



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

[0] = LAYOUT_all(
   KC_ESC,         KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,                    KC_Y,         KC_U,         KC_I,    KC_O,            KC_P,     A(KC_BSPC),
   MEH_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,         KC_G,          KC_PGUP,  KC_H,         KC_J,         KC_K,    KC_L,            TD(TD_QUOT), TD(TD_CLN),
   SFT_T(KC_HOME), KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,          KC_PGDN,  KC_N,         KC_M,         KC_COMM, KC_DOT,          KC_UP,    TD(TD_QUES),
   TAB_CTL,        KC_LGUI, LALT_T(KC_BSPC), LALT_T(KC_BSPC), LT(2,KC_ENT), LT(2,KC_ENT),  KC_MUTE,  LT(1,KC_SPC), LT(1,KC_SPC), HYPR_T(KC_END), KC_LEFT, KC_DOWN,  KC_RGHT
),

[1] = LAYOUT_all(
  RGB_TOG,         KC_1,    KC_2,    KC_3,    KC_4,         KC_5,                    KC_6,         KC_7,         KC_8,    KC_9,            KC_0,     KC_DEL,
  _______,         KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,         _______,  KC_F11,       KC_LBRC,      KC_RBRC, KC_MINUS,        KC_EQUAL, KC_BSLS,
  _______,         KC_F6,   KC_F7,   KC_F8,   KC_F9,        KC_F10,        _______,  KC_F12,       _______,      _______, _______,         KC_VOLU,  KC_MPLY,
  _______,         _______, _______, _______, _______,      _______,       _______,  _______,      _______,      _______, KC_MPRV,         KC_VOLD,  KC_MNXT
),
    
[2] = LAYOUT_all(
  QK_BOOT,           KC_EXLM, KC_AT,     KC_HASH, LALT(KC_3), KC_PERC,                 KC_CIRC,      KC_AMPR,      KC_ASTR, KC_LPRN,         KC_RPRN,  KC_BSPC,
  _______,         _______, LSA(KC_2), KC_DLR,  _______,    _______,       _______,  RGB_HUI,      RGB_VAI,      RGB_SAI, KC_MINUS,        KC_PLUS,  KC_BSLS,
  _______,         _______, _______,   _______, _______,    _______,       _______,  RGB_HUD,      RGB_VAD,      RGB_SAD, _______,         KC_PGUP,  _______,
  _______,         _______, _______,   _______, _______,    _______,       _______,  _______,      _______,      KC_MNXT, LGUI(KC_MINUS),  KC_PGDN,  LGUI(KC_PLUS)
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


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code16(S(KC_VOLD));
    } else {
      tap_code16(KC_VOLU);
    }
    return true;
}
