#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FUNCTION_LAYER,
  _MEDIA_AND_NAVIGATION_LAYER,
  _NUMPAD_LAYER,
  _MOUSE_LAYER,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD
};

enum {
    ESC_LAYR, // Our custom tap dance key; add any other tap dance keys to this enum 
};

/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | FN1     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  FN2  |  Alt  |                FN2              |  Win  |  FN2  |  FN1  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* | ESC     |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |                |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |               Space             |       |       |       |       |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
     KC_GRV,                    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,   KC_6,      KC_7,    KC_8,     KC_9,     KC_0, KC_MINS,  KC_EQL, KC_BSPC,
    LT(_MOUSE_LAYER,KC_TAB),    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,   KC_Y,      KC_U,    KC_I,     KC_O,     KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    TD(ESC_LAYR), KC_A,  KC_S,  KC_D,  KC_F,  KC_G,   KC_H,      KC_J,    KC_K,     KC_L,  KC_SCLN, KC_QUOT,  KC_ENT,
    KC_LSFT, KC_Z,              KC_X,  KC_C,  KC_V,  KC_B,  KC_N,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
    KC_LCTL,     TT(_NUMPAD_LAYER), KC_LALT, LT(_MEDIA_AND_NAVIGATION_LAYER, KC_SPC), KC_LGUI, LT(_MEDIA_AND_NAVIGATION_LAYER,KC_APP), MO(_FUNCTION_LAYER), KC_RCTL
),
  /*
  * Layer _FUNCTION_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | Caps|  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |  7  |  8  |  9  |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |  0  |  4  |  5  |  6  |     | LFT | DWN | UP  | RGT |  ;  |  '  |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |  1  |  2  |  3  |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FUNCTION_LAYER] = KEYMAP( /* Base */
    KC_CAPS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_PSCR, _______,    KC_7,    KC_8,    KC_9, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    KC_0,    KC_4,    KC_5,    KC_6, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______,
    _______, _______,    KC_1,    KC_2,    KC_3, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
),
  /*
  * Layer _MEDIA_AND_NAVIGATION_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | USB | BT1 | BT2 | BT3 | BT4 |     |     |     |LEDOF|LEDON|     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     | UP  |     |     | MUTE| PREV| PLAY| NEXT|     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     | LFT | DWN | RGT |     | HOME|PGDWN| PGUP| END |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |VOLDN|VOLUP|     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_MEDIA_AND_NAVIGATION_LAYER] = KEYMAP( /* Base */
    KC_AP2_USB, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______,  KC_AP_LED_ON, KC_AP_LED_OFF, _______, _______, KC_AP2_BT_UNPAIR,
       _______,    _______,    _______,      KC_UP,    _______, _______, KC_MUTE, KC_MPRV, KC_MPLY,       KC_MNXT,       _______, KC_BRID, KC_BRIU, _______,
       _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT, _______, KC_HOME, KC_PGDN, KC_PGUP,        KC_END,       _______, _______, _______,
       _______,    _______,    _______,    _______,    _______, _______, KC_VOLD, KC_VOLU, _______,       _______,       _______, _______,
       _______,    _______,    _______,    _______,    _______, _______, _______, _______
 ),
  /*
  * Layer _NUMPAD_LAYER
  * ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |  7  |  8  |  9  |     |  +  |  7  |  8  |  9  |  .  |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |  0  |  4  |  5  |  6  |     |  0  |  4  |  5  |  6  |  /  |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |  1  |  2  |  3  |  ,  |  *  |  1  |  2  |  3  |  -  |                |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |               0                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_NUMPAD_LAYER] = KEYMAP( /* Base */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,    KC_7,    KC_8,    KC_9, _______, KC_PPLS,    KC_7,    KC_8,    KC_9, KC_PDOT, _______, _______, _______,
    _______,    KC_0,    KC_4,    KC_5,    KC_6, _______,    KC_0,    KC_4,    KC_5,    KC_6, KC_PMNS, _______, _______,
    _______, _______,    KC_1,    KC_2,    KC_3, KC_COMM, KC_PAST,    KC_1,    KC_2,    KC_3, KC_PSLS, _______,
    _______, _______, _______,    KC_0, _______, _______, _______, _______
 ),
  /*
  * Layer _MOUSE_LAYER - Mouse Layer
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |ACL2 |WL-U |MS-U |WL-D |ACL1 |ACL0 |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     |BTN3 |MS-L |MS-D |MS-R |BTN2 |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |BTN4 |BTN5 |WL-L |WL-R |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |              BTN1               |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_MOUSE_LAYER] = KEYMAP( /* Base */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_BTN3, KC_BTN4, KC_BTN5, _______, _______, _______, 
    _______, _______, _______, KC_BTN1, _______, _______, _______, _______
 ),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (!state->pressed) return DOUBLE_TAP;
    else return DOUBLE_HOLD;
  }  else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
  .is_press_action = true,
  .state = 0
};

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_ESC);
      break;
    case SINGLE_HOLD:
      layer_on(_FUNCTION_LAYER);
      break;
    case DOUBLE_TAP:
      // Check to see if the layer is already set
      if (layer_state_is(_MOUSE_LAYER)) {
        // If already set, then switch it off
        layer_off(_MOUSE_LAYER);
      } else {
        // If not already set, then switch the layer on
        layer_on(_MOUSE_LAYER);
      }
      break;
    case DOUBLE_HOLD:
      layer_on(_NUMPAD_LAYER);
      break;
  }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
  // If the key was held down and now is released then switch off the layer
  if (ql_tap_state.state == SINGLE_HOLD) {
    layer_off(_FUNCTION_LAYER);
  }
  if (ql_tap_state.state == DOUBLE_HOLD) {
    layer_off(_NUMPAD_LAYER);
  }
  ql_tap_state.state = 0;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
  [ESC_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275)
};
