// clang-format off
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
// NOTE: third layer must be higher than both x and y!
// See: https://github.com/qmk/qmk_firmware/blob/master/docs/ref_functions.md
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _SYM,
    _NAV,
    _MISC,
    _MOUSE
};

enum custom_keycodes {
    DCOLN,
};

#define SYM MO(_SYM)
#define NAV MO(_NAV)

#define TAP_INTERVAL_MS 100

// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | LSFT |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | RSFT |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | DELW |        | SYM  | LSFT |  ENT |    | Space | BSPC | NAV |        | UNDO |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift.
// Trying out CAGS for mac, other OS should use GACS. (easy to roll A-G or G-S)
// Either shift or raise on thumb key...
// OPPOSITES:
// - Shift-space: so can type capitalized fast
// - SYM-Shift: So can access symbols
// - SYM-space: same as 1 (not essential? only use case I can think of is `let _ = `) where one might need to quickly interleave symbols and space consecutively
// how d
//      - most of the time it will be like let x_some_character_string = ....
// CONSIDER:_
// - Check if mod-tap tab/ctrl is fine
// - Check if mod-tap shift/space is fine
// - Check if mod-tap ctrl/enter is fine
// - Replace backslash?
// - grave escape ok? (esc normally, tilde on shift, backtick on cmd, but macos mapped to swap focus, so put backtick on symbol layer)
[_QWERTY] = LAYOUT_ffkb(
  KC_ESC,         KC_Q,      KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,             KC_I,         KC_O,         KC_P,             KC_BSLS,
  KC_TAB,  KC_A,      KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,        KC_K ,         KC_L,         KC_SCLN,          KC_QUOT,
  KC_LSFT,          LCTL_T(KC_Z),      LALT_T(KC_X),         LGUI_T(KC_C),         LSFT_T(KC_V),         KC_B,         KC_N,    RSFT_T(KC_M),             RGUI_T(KC_COMM),      RALT_T(KC_DOT),       RCTL_T(KC_SLSH),          KC_RSFT,
                  LCTL(KC_BSPC),        SYM,      KC_LSFT,        KC_ENT,         KC_SPC,  KC_BSPC,    NAV,      KC_UNDO
),

/* COLEMAK-DH
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   F  |   P  |   B  |             |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   H  |             |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | LSFT |   Z  |   X  |   C  |   D  |   V  |             |   K  |   H  |   ,  |   .  |   /  | RSFT |
 * `-----------------------------------------'             `-----------------------------------------'
 */
[_COLEMAK] = LAYOUT_ffkb(
  KC_ESC,         KC_Q,      KC_W,         KC_F,         KC_P,         KC_B,         KC_J,    KC_L,             KC_U,         KC_Y,         KC_SCLN,             KC_BSLS,
  KC_TAB,  KC_A,      KC_R,         KC_S,         KC_T,         KC_H,         KC_M,    KC_N,        KC_E,         KC_I,         KC_O,          KC_QUOT,
  KC_LSFT,          LCTL_T(KC_Z),      LALT_T(KC_X),         LGUI_T(KC_C),         LSFT_T(KC_D),         KC_V,         KC_K,    RSFT_T(KC_H),             RGUI_T(KC_COMM),      RALT_T(KC_DOT),       RCTL_T(KC_SLSH),          KC_RSFT,
                  LCTL(KC_BSPC),        SYM,      KC_LSFT,        KC_ENT,         KC_SPC,  KC_BSPC,    NAV,      KC_UNDO
),

/* Sym
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |   [  |   ]  |   {  |   }  |  |   |             |   -  |   _  |   =  |   +  |  :   |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |   ~  |      |      |      |      |             |  ::  |   "  |   <  |   >  |  ?   |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | DELW |        | SYM  | LSFT |  ENT |    | Space | BSPC | NAV |        | UNDO |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Num/symbol layer
// Should not have to press shift to access any symbols.. else will just lead to more confusion
// Symbol and space key should be separate hands... common use case to hold shift and type caps with access
// while interleaving _
// Shift-space also separate? to type caps letters in quick succession
// Left with: !@#$%, ""
[_SYM] = LAYOUT_ffkb(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE,      KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, KC_COLN, _______,
  _______, KC_TILD, _______, _______, _______, _______,      DCOLN,   KC_DQUO, KC_LABK, KC_RABK, KC_QUES, _______,
                    _______, _______, _______, _______,      _______, _______, _______, _______
),


/* Nav/Num
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      | c-a-a| c-a-b| c-a-s|c-a-o |c-a-p |             | home | pgdn | pgup | end  |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |   1  |  2   |  3   |  4   |  5   |             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | lctl | lalt | lcmd | lsft |      |             | left | down |   up | right|   .  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | DELW |        | SYM  | LSFT |  ENT |    | Space | BSPC | NAV |        | UNDO |
 *           `------'        `--------------------'    `--------------------.        `------'
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
[_NAV] = LAYOUT_ffkb(
  _______, LAG(KC_A), LAG(KC_B), LAG(KC_S), LAG(KC_O), LAG(KC_P),      KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______,
  _______, KC_1,   KC_2,   KC_3, KC_4,   KC_5,                         KC_6, KC_7, KC_8,  KC_9, KC_0, _______,
  _______, KC_LCTL,   KC_LALT,   KC_LGUI, KC_LSFT, _______,            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  KC_DOT, _______,
                      _______,   _______, _______, _______,      _______, _______, _______, _______
),

/* Misc
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | BOOT |QWERTY|      |      |      |      |             |      |      | MPRV | MPLY | MNXT |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | CAPS |COLEMK|      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY | PASTE|      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | DELW |        | SYM  | LSFT |  ENT |    | Space | BSPC | NAV |        | UNDO |
 *           `------'        `--------------------'    `--------------------.        `------'
 */
[_MISC] = LAYOUT_ffkb(
  QK_BOOT, DF(_QWERTY), _______, _______, _______, _______,      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
  KC_CAPS, DF(_COLEMAK),   _______,   _______, _______,   _______,                         _______, _______, _______,  _______, _______, _______,
  _______, KC_UNDO,   KC_CUT,   KC_COPY, KC_PSTE, _______,            _______, _______, _______, _______,  _______, _______,
                      _______,   _______, _______, _______,      _______, _______, _______, _______
),

/* Mouse layer
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      | SRES |  SDN |  SUP | SCRL |             |MSBTN1|MSBTN2|MSBTN3|      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      | SNRES| SNDN | SNUP | ZOOM |             | WH_U | WH_D |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | lctl | lalt | lcmd | lsft | SNPE |             | WBCK | WFWD |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | DELW |        | SYM  | LSFT |  ENT |    | Space | BSPC | NAV |        | UNDO |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_MOUSE] =  LAYOUT_ffkb(
  _______, _______, FP_SCROLL_DPI_RESET, FP_SCROLL_DPI_DN, FP_SCROLL_DPI_UP, FP_SCROLL_MOMENT,          KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______,
  _______, _______, FP_SNIPE_DPI_RESET, FP_SNIPE_DPI_DN, FP_SNIPE_DPI_UP, FP_SNIPE_MOMENT,          KC_WH_U, KC_WH_D, _______, _______, _______, _______,
  _______, KC_LCTL,   KC_LALT,   KC_LCMD, KC_LSFT, FP_ZOOM_MOMENT,          KC_WBAK, KC_WFWD, _______, _______, _______, _______,
                    _______, _______, _______, _______,                 _______, _______, _______, _______
)
};

// used to turn on third layer if both SYM and NAV are activated
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NAV, _MISC);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
            case DCOLN:
                SEND_STRING("::");
                return false;
        }
    }

    return true; // Continue normal processing
}

// quick-tap: if hold-tap is tapped within TAP_INTERVAL_MS of the first press,
// then tap is instantly triggered.
// This allows auto-repeat on tap-into-hold (e.g. tap backspace, keyup, then hold backspace).
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Match mod-tap keys. Tweak this to limit conditions that matches
    // your keyboard and habits
    if (IS_QK_MOD_TAP(keycode)) {
        // Tap the mod-tap key instantly when it follows a short interval
        if (record->event.pressed && last_input_activity_elapsed() < TAP_INTERVAL_MS) {
            record->keycode = keycode & 0xff;
            action_tapping_process(*record);
            return false; // Skip quantum processing
        }
        // Send the base keycode key up event
        else {
            keyrecord_t base_record   = *record;
            base_record.keycode       = keycode & 0xff;
            base_record.event.pressed = false;
            action_tapping_process(base_record);
        }
    }
    return true; // Continue normal processing
}

