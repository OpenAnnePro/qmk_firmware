#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
  _FN3_LAYER,
};

// #define CAPS_LOCATION (MATRIX_COLS * 2 + 0)

	// Key symbols are based on QMK. Use them to remap your keyboard
	/*
	* Layer _BASE_LAYER


	* ,-----------------------------------------------------------------------------------------.
	* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
	* |-----------------------------------------------------------------------------------------+
	* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  | Delete |
	* |-----------------------------------------------------------------------------------------+
	* | FN1     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
	* |-----------------------------------------------------------------------------------------+
	* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
	* |-----------------------------------------------------------------------------------------+
	* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
	* \-----------------------------------------------------------------------------------------/


	* Layer TAP in _BASE_LAYER


	* ,-----------------------------------------------------------------------------------------.
	* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
	* |-----------------------------------------------------------------------------------------+
	* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
	* |-----------------------------------------------------------------------------------------+
	* |  Caps   |     |     |     |     |     |     |     |     |     |     |     |             |
	* |-----------------------------------------------------------------------------------------+
	* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
	* |-----------------------------------------------------------------------------------------+
	* |       |       |       |                                 |   PS  |  LEFT | DOWN  | RIGHT |
	* \-----------------------------------------------------------------------------------------/
	*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_DEL,
    LT(_FN1_LAYER,KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, RALT_T(KC_PSCR), LT(_FN1_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT)
),
  
	 /*
	* Layer _FN1_LAYER
	* ,-----------------------------------------------------------------------------------------.
	* |  `  | F01 | F02 | F03 | F04 | F05 | F06 | F07 | F08 | F09 | F10 | F11 | F12 |   Delete  |
	* |-----------------------------------------------------------------------------------------+
	* |  FN3   |     | UP  |     |     |     |     |     | UP  |     | PS  |HOME |END  |   \    |
	* |-----------------------------------------------------------------------------------------+
	* |         |LEFT |DOWN |RIGHT|     |     |     |LEFT |DOWN |RIGHT|PGUP |PGDWN|             |
	* |-----------------------------------------------------------------------------------------+
	* |            |     |mute |v-dn |v-up |scrlk|     |     |     | INS | DEL |                |
	* |-----------------------------------------------------------------------------------------+
	* |       |       |       |              pause              |       |       |FN2_LOCK|      |
	* \-----------------------------------------------------------------------------------------/
	*/

 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV,        KC_F1,    KC_F2,     KC_F3,    KC_F4,   KC_F5,  KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_DEL,
    MO(_FN3_LAYER), _______, KC_UP,     _______, _______, _______, _______, _______, KC_UP, _______, KC_PSCR, KC_HOME, KC_END,  KC_BSLS,
    _______,        KC_LEFT, KC_DOWN,   KC_RGHT,    _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN, _______,
    _______,        _______, KC_MUTE,   KC_VOLD, KC_VOLU,  KC_SLCK, _______, _______, _______, KC_INS, KC_DEL, _______,
    _______,        _______, _______,   KC_MEDIA_PLAY_PAUSE,                          _______, _______, TO(_FN2_LAYER), _______
),
  /*
  * Layer _FN2_LAYER
	* ,-----------------------------------------------------------------------------------------.
	* |     | BT1 | BT2 | BT3 | BT4 |     |     |     |     |     |     |     |  =  |   Delete  |
	* |-----------------------------------------------------------------------------------------+
	* |        |     | UP  |     |     |     |     |  7  |  8  |  9  |  +  |  *  |  ,  |   \    |
	* |-----------------------------------------------------------------------------------------+
	* |         |LEFT |DOWN |RIGHT|     |     |     |  4  |  5  |  6  |  -  |  /  |  num_enter  |
	* |-----------------------------------------------------------------------------------------+
	* |            |     |     |     |     |     | num |  1  |  2  |  3  |  .  |                |
	* |-----------------------------------------------------------------------------------------+
	* |       |       |       |                                 |   0   |       |  BASE  |      |
	* \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    _______, KC_AP2_BT1, KC_AP2_BT2,KC_AP2_BT3,KC_AP2_BT4, _______, _______, _______, _______, _______, _______, _______, KC_PEQL, KC_DEL,
    _______, _______, KC_UP, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_PAST, KC_PCMM, KC_BSLS,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PSLS, KC_PENT,
    _______, _______, _______, _______, _______, _______, KC_NLCK, KC_P1, KC_P2, KC_P3, KC_PDOT,  _______,
    _______, _______, _______,                               _______,                       KC_P0, _______, TO(_BASE_LAYER), _______
 ),
 
	   /*
	  * Layer _FN3_LAYER
	* ,-----------------------------------------------------------------------------------------.
	* |  `  | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | F24 |   Unpair  |
	* |-----------------------------------------------------------------------------------------+
	* |        | BT1 | BT2 | BT3 | BT4 |     |     |     |pwake|pshut|sleep|br_dn|br_up|  usb   |
	* |-----------------------------------------------------------------------------------------+
	* |         |led_0|led_1|prof-|prof+|light|speed|     |     |     |     |     |             |
	* |-----------------------------------------------------------------------------------------+
	* |            |     |     |calc |     |     |     |     |prev |next |stop|                |
	* |-----------------------------------------------------------------------------------------+
	* |       |       |       |                                 |       |       |        |      |
	* \-----------------------------------------------------------------------------------------/
	  *
	  */
  [_FN3_LAYER] = KEYMAP( /* Base */
    KC_GRV,  KC_F13,   KC_F14,    KC_F15,  KC_F16,    KC_F17,    KC_F18,     KC_F19,    KC_F20,     KC_F21,    KC_F22,   KC_F23,  KC_F24,   KC_AP2_BT_UNPAIR,
    _______, KC_AP2_BT1,    KC_AP2_BT2,    KC_AP2_BT3,     KC_AP2_BT4, _______, _______, _______, KC_WAKE, KC_PWR, KC_SLEP, KC_BRID, KC_BRIU,  KC_AP2_USB,
    _______, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_PREV_PROFILE, KC_AP_LED_NEXT_PROFILE, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_CALC, _______,  _______, _______, _______, KC_MPRV, KC_MNXT, KC_MSTP, _______,
    _______, _______, _______,                            _______,                   _______, _______, _______, _______
 )
 

};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}

bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    annepro2LedSetMask(CAPS_LOCATION);
  } else {
    annepro2LedClearMask(CAPS_LOCATION);
  }
  return true;
}