#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _L1 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-------------------------------------------------------------------------------------------------.
 * | `    |   1  |   2  |   3  |   4  |   5  | Esc  |      |   6  |   7  |   8  |   9  |   0  | -    |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | [    | None |   Y  |   U  |   I  |   O  |   P  | \    |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  | ]    | =    |   H  |   J  |   K  |   L  |   ;  | '    |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | None | None |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | None | None | None |  Fn1 | Gui  | Back | Del  | Enter| Space| Alt  |left  | down |  up  | right|
 * `-------------------------------------------------------------------------------------------------'
 */

[_QWERTY] = LAYOUT_ortho_4x12(
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,    KC_CAPS,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_MINS, \
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,   KC_NO,      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_BSLS, \
   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_RBRC,   KC_EQL,     KC_H,    KC_J,    KC_K,    KC_L ,  KC_SCLN,  KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,     KC_NO,      KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT, \
   KC_NO,   KC_NO,   KC_NO,   MO(_L1), KC_LGUI, KC_BSPC, KC_DEL,    KC_ENT,     KC_SPC,  KC_LALT, KC_LEFT, KC_DOWN,KC_UP,    KC_RIGHT \
),

/* Layer 1
 * ,---------------------------------------------------------------------------------------------------.
 * | None |  F1  |  F2  |  F3  |  F4  |  F5  | F11  | F12  |  F6  |  F7  |  F8   |  F9  |  F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+-------+------+-------+------|
 * | None | None | None | None | None | None | None | None | None | None |  up   | None | None  | None |
 * |------+------+------+------+------+------+------+------+------+------+-------+------+-------+------|
 * | Ctrl | None | None | None | None | None | None | None | None | left | down  | right| None  | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+-------+------+-------+------|
 * | Shift| None | None | None | None | None | Snd- | Snd+ | None | Mute | None  | None | None  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+-------+------+-------+------|
 * | None | None | None |Transp| Gui  | Alt  | F14  | F15  | Alt  | Gui  | None  | None | None  | None |
 * `---------------------------------------------------------------------------------------------------'
 */

[_L1] = LAYOUT_ortho_4x12(
   KC_NO,   KC_F1, KC_F2, KC_F3,   KC_F4,   KC_F5,    KC_F11,  KC_12,   KC_6,    KC_7,    KC_8,    KC_9,     KC_10, KC_NO, \
   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,    KC_NO, KC_NO, \
   KC_LCTL, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_LCTL, \
   KC_LSFT, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_VOLD, KC_VOLU, KC_NO,   KC_MUTE, KC_NO,   KC_NO,    KC_NO, KC_RSFT, \
   KC_NO,   KC_NO, KC_NO, KC_TRNS, KC_LGUI, KC_LALT,  KC_F14,  KC_F15,  KC_LALT, KC_LGUI, KC_NO,   KC_NO,    KC_NO, KC_NO, \
),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
