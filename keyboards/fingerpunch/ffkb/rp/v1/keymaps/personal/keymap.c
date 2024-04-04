#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOUSE
};

enum custom_keycodes {
    DCOLN,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | BSLS |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |  "  |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | DELW |        |  CMD | LOWER| Enter|    | Space| BSPC| RAISE |        | UNDO |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
// CONSIDER:
// - Check if mod-tap tab/ctrl is fine
// - Check if mod-tap shift/space is fine
// - Check if mod-tap ctrl/enter is fine
// - Replace backslash?
// - grave escape ok? (esc normally, tilde on shift, backtick on cmd, but macos mapped to swap focus, so put backtick on symbol layer)
[_QWERTY] = LAYOUT_ffkb(
  QK_GESC,         KC_Q,      KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,             KC_BSLS,
  CTL_T(KC_TAB),  KC_A,      KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,          KC_QUOT,
  KC_LSFT,        KC_Z,      KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,          KC_DQT,
                  LCTL(KC_BSPC),        KC_LCMD,      LOWER,        CTL_T(KC_ENT),       KC_SPC,  KC_BSPC,      RAISE,        KC_UNDO
),


/* Raise
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      | c-s-4| c-s-5|             |o(c-s)|o(c-a)|o(csa)| c-a-o|c-a-p |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | CAPS | c-a-a| c-a-s|o(ctl)|o(sft)|o(alt)|             | left | down |  up  | right|      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |ctrl-b|c-a-b |             | home | pgdn | pgup | end  |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | DELW |        |  CMD | LOWER| Enter|    | Space| BSPC| RAISE |        | UNDO |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Nav layer
// ctrl, shift, alt on nav layer so can easily do e.g. ctrl-shift-right
// Combis: 
// - cmd-shift-5 for video
// - cmd-shift-ctrl-4 for copying screenshot
// - cmd-shift-p command palette
// - cmd-alt for raycast (resolved with LAG?
// - ctrl-1 for changing tabs in Sublime Text/Zed
// - alt-left for changing panes within tmux
// - shift-left for changing windows within tmux
// - ctrl-backspace for deleting word
// - cmd-backspace for deleting line
// - ctrl-b for tmux prefix
// Idea: put cmd-shift on right hand
// one-shot keys also work as modifiers
[_RAISE] = LAYOUT_ffkb(
  _______, _______,   _______,   _______, SCMD(KC_4), SCMD(KC_5),      OSM(MOD_LGUI | MOD_LSFT), OSM(MOD_LGUI | MOD_LALT), OSM(MOD_LGUI | MOD_LSFT | MOD_LALT), LAG(KC_O), LAG(KC_P), _______,
  KC_CAPS, LAG(KC_A), LAG(KC_S), OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT),      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______,   _______,   _______, LCTL(KC_B), LAG(KC_B),    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                      _______,   _______, _______, _______,      _______, _______, _______, _______
),

/* Lower
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   <  |   >  |   [  |   ]  |   &  |             |   -  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |   #  |   !  |   "  |   (  |   )  |   _  |             |   =  |   4  |   5  |   6  |   :  |  $   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |   ^  |   @  |  ::  |   {  |   }  |   *  |             |   +  |   1  |   2  |   3  |   ?  |  %   |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | DELW |        |  CMD | LOWER| Enter|    | Space| BSPC| RAISE |        | UNDO |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Num/symbol layer
// Should not have to press shift to access any symbols.. else will just lead to more confusion
// Symbol and space key should be separate hands... common use case to hold shift and type caps with access
// while interleaving _
// Shift-space also separate? to type caps letters in quick succession
// Left with: !@#$%, ""
[_LOWER] = LAYOUT_ffkb(
  KC_GRV,  KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_AMPR,      KC_MINS, KC_7,    KC_8,    KC_9, KC_0,    KC_PIPE,
  KC_HASH, KC_EXLM, KC_DQT, KC_LPRN,  KC_RPRN, KC_UNDS,      KC_EQL,  KC_4,    KC_5,    KC_6,  KC_COLN, KC_DLR,
  KC_CIRC, KC_AT,   DCOLN, KC_LCBR, KC_RCBR, KC_ASTR,      KC_PPLS, KC_1,    KC_2,    KC_3, KC_QUES, KC_PERC,
                    _______, _______, _______, _______,      _______, _______, _______, _______
),

/* Mouse layer

 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |MSBTN1|MSBTN2|MSBTN3|      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             | WH_D | WH_U |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             | WBCK | WFWD |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | DELW |        |  CMD | LOWER| Enter|    | Space| BSPC| RAISE |        | UNDO |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_MOUSE] =  LAYOUT_ffkb(
  _______, _______, _______, _______, _______, _______,          KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,          KC_WH_D, KC_WH_U, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,          KC_WBAK, KC_WFWD, _______, _______, _______, _______,
                    _______, _______, _______, _______,          _______, _______, _______, _______
)
};

// used to turn on third layer if both LOWER and RAISE are activated
// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE);
// }
//
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
            case DCOLN:
                SEND_STRING("::");
                return false;
        }
    }

    return true;
}

