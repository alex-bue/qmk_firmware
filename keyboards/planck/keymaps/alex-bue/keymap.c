/*
Planck Keymap
By Alex
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAVIGATION,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,

  CAMP, // For Song Campanella
  IMP,  // For Fantasie Impromptue
  NOCT  // For Nocture Op 9 1
};

#define LOWER LT(_LOWER, KC_BSPC)       // Lower layer on hold, backspace on tap
#define RAISE LT(_RAISE, KC_ENTER)      // Raise layer on hold, enter on tap
#define NAV_SPC LT(_NAVIGATION, KC_SPC) // Navigation layer on hold, tap on space
#define NAV MO(_NAVIGATION)             // Alias for navigation layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | C_Esc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SEnter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NAV  | Ctrl | GUI  | ALT  |Lower |  NAV_Space  |Raise | RALT | RGUI | RCtrl| NAV  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,     KC_Y,     KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,   KC_G,     KC_H,     KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,     KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  SC_SENT,
    NAV,             KC_LCTL,  KC_LGUI,  KC_LALT,  LOWER,  NAV_SPC,  NAV_SPC,  RAISE,  KC_RALT,  KC_RGUI,  KC_RCTL,  NAV
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   _  |   +  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILDE, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_UNDS,  KC_PLUS,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    _______,  _______,  _______,  _______,  _______,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),


/* Navigation (HOLD SPACE)
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |ALT_1 |ALT_2 |ALT_3 |ALT_4 |ALT_5 |ALT_6 |ALT_7 |ALT_8 |ALT_9 |ALT_0 |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | PgDn | PgUp | LEFT | DOWN |  UP  | RGHT | Play |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |BRGTH-|BRGTH+| Prev | Vol- | Vol+ | Next | Mute |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATION] = LAYOUT_planck_grid(
    _______, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0), KC_DEL,
    _______, _______,    _______,    _______,    KC_PGDN,    KC_PGUP,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_MPLY,    _______,
    _______, _______,    _______,    _______,    KC_BRID,    KC_BRIU,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_MUTE,    _______,
    _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),


/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      | NROM | Reset|      |      |      |      |AGnorm|AGswap|  RGB |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |RGBmod| BVAL-| BVAL+|RGBmod|      |  AUD |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | SONG1| SONG2| SONG3|      |      |NK Tog| HUE- | HUE+ |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_NO,    KC_NO,    KC_NO,    EE_CLR,   QK_BOOT,  KC_NO,    KC_NO,     KC_NO,    KC_NO,    AG_NORM,  AG_SWAP,  RGB_TOG,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RGB_RMOD,  RGB_VAD,  RGB_VAI,  RGB_MOD,  KC_NO,    AU_TOGG,
    KC_NO,    CAMP,     IMP,      NOCT,     KC_NO,    KC_NO,    NK_TOGG,   RGB_HUD,  RGB_HUI,  KC_NO,    KC_NO,    KC_NO,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______
)
};

#ifdef AUDIO_ENABLE
  float campanella[][2]         = SONG(CAMPANELLA);
  float fantasie_impromptu[][2] = SONG(FANTASIE_IMPROMPTU);
  float nocturne[][2]           = SONG(NOCTURNE_OP_9_NO_1);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case CAMP:
      if (record->event.pressed) {
        PLAY_SONG(campanella);
      }
      break;
    case IMP:
      if (record->event.pressed) {
        PLAY_SONG(fantasie_impromptu);
      }
      break;
    case NOCT:
      if (record->event.pressed) {
        PLAY_SONG(nocturne);
      }
      break;
  }
  return true;
};

// Adjust tapping term on certain keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_SPC: // Increase time that space needs to be held to access nav layer
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}
