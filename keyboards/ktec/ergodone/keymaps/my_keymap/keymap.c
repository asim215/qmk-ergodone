#include QMK_KEYBOARD_H
#include "version.h"
// #include "keymap_russian.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  VRSN = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ergodox_pretty_80(KC_DEL, KC_1, KC_2, KC_3, KC_4, KC_5, OSL(1), OSL(2), KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, TG(1), TG(2), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, MO(1), MO(2), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_GRV, KC_MINS, KC_EQL, KC_RBRC, KC_BSLS, KC_INS, KC_HOME, KC_END, KC_PGDN, KC_PGUP, KC_LGUI, KC_LALT, KC_DEL, KC_BSPC, KC_RALT, KC_LGUI, KC_SPC, KC_LCTL, KC_ENT, KC_ENT, KC_RCTL, KC_SPC),
	[1] = LAYOUT_ergodox_pretty_80(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_INS, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_WH_U, KC_TRNS, KC_NO, KC_NUM, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_BSPC, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_WH_D, KC_LPRN, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_ENT, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_R, KC_TRNS, KC_BTN3, KC_RPRN, KC_P1, KC_P2, KC_P3, KC_PAST, KC_PEQL, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, KC_MUTE, KC_P0, KC_PDOT, KC_CIRC, KC_PSLS, KC_TILD, KC_HOME, KC_END, KC_PGDN, KC_PGUP, KC_LGUI, KC_LALT, KC_DEL, KC_BSPC, KC_RALT, KC_LGUI, KC_SPC, KC_LCTL, KC_ENT, KC_ENT, KC_RCTL, KC_SPC),
	[2] = LAYOUT_ergodox_pretty_80(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_TRNS, KC_TRNS, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SLEP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, KC_MUTE, KC_NUM, KC_CAPS, KC_SCRL, KC_PSCR, KC_PAUS, KC_HOME, KC_END, KC_PGDN, KC_PGUP, KC_LGUI, KC_LALT, KC_DEL, KC_BSPC, KC_RALT, KC_LGUI, KC_SPC, KC_LCTL, KC_ENT, KC_ENT, KC_RCTL, KC_SPC)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
  }
  return true;
}

bool led_update_user(led_t led_state) {
    // stub any kb level behaviour
    return false;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    // ergodox_board_led_off();
    // ergodox_right_led_1_off();
    // ergodox_right_led_2_off();
    // ergodox_right_led_3_off();

    switch (get_highest_layer(layer_state)) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            ergodox_right_led_2_off();
            break;
        case 2:
            ergodox_right_led_1_off();
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        default:
            // none
            ergodox_led_all_off();
            break;
    }

};

