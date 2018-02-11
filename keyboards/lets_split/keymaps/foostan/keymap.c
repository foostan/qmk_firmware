#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

// Macro name shortcuts
#define LWR M(_LOWER)
#define RIS M(_RAISE)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KEYMAP( \
//,-----------------------------------------------------------------------.  ,-----------------------------------------------------------------------.
        KC_ESC,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,          KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,   KC_BSPC,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
      KC_LCTRL,       KC_A,       KC_S,       KC_D,       KC_F,       KC_G,          KC_H,       KC_J,       KC_K,       KC_L,    KC_SCLN,   KC_QUOT,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
       KC_LSFT,       KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,          KC_N,       KC_M,    KC_COMM,     KC_DOT,    KC_SLSH,    KC_TAB,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
       XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LALT,      LOWER,     KC_SPC,        KC_ENT,      RAISE,    KC_RALT,    XXXXXXX,    XXXXXXX,   XXXXXXX \
//`-----------------------------------------------------------------------'  `-----------------------------------------------------------------------'
),

[_LOWER] = KEYMAP( \
//,-----------------------------------------------------------------------.  ,-----------------------------------------------------------------------.
        KC_ESC,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,          KC_6,       KC_7,       KC_8,       KC_9,       KC_0,   KC_BSPC,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
      KC_LCTRL,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,         KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_F10,   XXXXXXX,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
       KC_LSFT,     KC_F11,     KC_F12,     KC_F13,     KC_F14,     KC_F15,        KC_F16,     KC_F17,     KC_F18,     KC_F19,     KC_F20,   XXXXXXX,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
       XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LALT,      LOWER,     KC_SPC,       KC_BSPC,      RAISE,     KC_TAB,    XXXXXXX,    XXXXXXX,   XXXXXXX \
//`-----------------------------------------------------------------------'  `-----------------------------------------------------------------------'
),

[_RAISE] = KEYMAP( \
//,-----------------------------------------------------------------------.  ,-----------------------------------------------------------------------.
        KC_ESC,    KC_EXLM,      KC_AT,    KC_HASH,     KC_DLR,    KC_PERC,       KC_CIRC,    KC_AMPR,    KC_ASTR,   KC_LPRN,     KC_RPRN,   KC_BSPC,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
      KC_LCTRL,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       KC_MINS,     KC_EQL, S(KC_LBRC), S(KC_RBRC), S(KC_BSLS),    KC_GRV,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
       KC_LSFT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    S(KC_MINS),  S(KC_EQL),    KC_LBRC,    KC_RBRC,    KC_BSLS, S(KC_GRV),\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
       XXXXXXX,    XXXXXXX,    XXXXXXX,     KC_TAB,      LOWER,     KC_ESC,        KC_ENT,      RAISE,    KC_RALT,    XXXXXXX,    XXXXXXX,   XXXXXXX \
//`-----------------------------------------------------------------------'  `-----------------------------------------------------------------------'
),

[_ADJUST] = KEYMAP( \
//,-----------------------------------------------------------------------.  ,-----------------------------------------------------------------------.
         RESET,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,\
//|-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------|
       KC_MS_L,    KC_MS_D,    KC_BTN1,    KC_LALT,      LOWER,     KC_SPC,        KC_ENT,      RAISE,    KC_RALT,    KC_BTN2,    KC_MS_U,   KC_MS_R \
//`-----------------------------------------------------------------------'  `-----------------------------------------------------------------------'
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
