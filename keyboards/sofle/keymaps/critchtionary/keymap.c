// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "oled.c"

enum sofle_layers {
    _QWERTY,
    _COMMANDS,
    _SYMBOLS,

    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_PRVWD,
    KC_NXTWD,
    KC_SNIP,
    KC_WINUP,
    KC_WINDN,
    KC_WINLF,
    KC_WINRT,
    KC_WINFL,
    KC_LOCK,
    KC_RSRCH,
    KC_GBP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |RShift|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |  `   |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \ Bspc \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */ 

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_QUOT,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_RSFT,
  KC_GRV,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                  KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_SPC,    KC_BSPC, TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  ~   |  -   |   "  |   [  |   ]  |                    |   +  |   7  |   8  |   9  |   *  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  !   |  _   |   '  |   (  |   )  |-------.    ,-------|   =  |   4  |   5  |   6  |   #  |RShift|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |  £   |  ^   |  |   |   :  |   {  |   }  |-------|    |-------|   0  |   1  |   2  |   3  |   \  | Enter|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \ Bspc \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_SYMBOLS] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,
  _______, KC_TILD, KC_MINS, KC_DQUO, KC_LBRC, KC_RBRC,                         KC_PLUS, KC_7,  KC_8,  KC_9,  KC_ASTR, KC_F12,
  _______, KC_EXLM, KC_UNDS, KC_QUOT, KC_LPRN, KC_RPRN,                         KC_EQL,  KC_4,  KC_5,  KC_6,  KC_HASH, _______,
  KC_GBP,  KC_CIRC, KC_PIPE, KC_COLN, KC_LCBR, KC_RCBR, _______,       _______, KC_0,    KC_1,  KC_2,  KC_3,  KC_BSLS, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* COMMANDS
 * ,----------------------------------------.                     ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps | Ins  | Pscr | Menu |RSrch |      |                    | PgUp | PWrd |  Up  | NWrd | DLine| F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|      | Snip |      |      |      |-------.    ,-------| PgDn | Left | Down | Right|  Del |RShift|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |   `  | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | Home |      |  End |      |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \ Bspc \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_COMMANDS] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                           KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,
  KC_CAPS, KC_INS,  KC_PSCR, KC_APP,  KC_RSRCH, XXXXXXX,                         KC_PGUP, KC_PRVWD, KC_UP,    KC_NXTWD, C(KC_BSPC), KC_F12,
  _______, XXXXXXX, KC_SNIP, XXXXXXX, XXXXXXX,  XXXXXXX,                         KC_PGDN, KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,     _______,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  XXXXXXX, _______,       _______, XXXXXXX, KC_HOME,  XXXXXXX,  KC_END,   XXXXXXX,    _______,
                     _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Lock |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|     |QWERTY|      |      |      |                    |      |WinFl | WinUp|      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      |WinLf | WinDn| WinRt|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \ Bspc \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  KC_LOCK, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  QK_BOOT, XXXXXXX, KC_QWERTY, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_WINFL, KC_WINUP, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, CG_TOGG,   XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_WINLF, KC_WINDN, KC_WINRT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

void move_window(uint16_t direction, bool pressed) {
    if (pressed) {
        if (keymap_config.swap_lctl_lgui) {
            // Mac
            register_mods(mod_config(MOD_LALT));
            register_mods(mod_config(MOD_LGUI));
            register_code(direction);
        } else {
            // Windows
            register_mods(mod_config(MOD_LGUI));
            register_code(direction);
        }
    } else {
        if (keymap_config.swap_lctl_lgui) {
            unregister_mods(mod_config(MOD_LALT));
            unregister_mods(mod_config(MOD_LGUI));
            unregister_code(direction);
        } else {
            unregister_mods(mod_config(MOD_LGUI));
            unregister_code(direction);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // Mac
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    // Windows
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // Mac
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    // Windows
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_SNIP:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // Mac
                    register_mods(mod_config(MOD_LCTL));
                    register_mods(mod_config(MOD_LSFT));
                    register_code(KC_4);
                } else {
                    // Windows
                    register_mods(mod_config(MOD_LGUI));
                    register_mods(mod_config(MOD_LSFT));
                    register_code(KC_S);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_mods(mod_config(MOD_LSFT));
                    unregister_code(KC_4);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_mods(mod_config(MOD_LSFT));
                    unregister_code(KC_S);
                }
            }
            break;
        case KC_WINUP:
            move_window(KC_UP, record->event.pressed);
            break;
        case KC_WINDN:
            move_window(KC_DOWN, record->event.pressed);
            break;
        case KC_WINLF:
            move_window(KC_LEFT, record->event.pressed);
            break;
        case KC_WINRT:
            move_window(KC_RIGHT, record->event.pressed);
            break;
        case KC_WINFL:
            move_window(KC_ENT, record->event.pressed);
            break;
        case KC_LOCK:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // Mac
                    register_mods(mod_config(MOD_LCTL));
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_Q);
                } else {
                    // Windows
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_L);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_Q);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_L);
                }
            }
            break;
        case KC_RSRCH:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // Mac
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_R);
                } else {
                    // Windows
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_R);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_R);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_R);
                }
            }
            break;
        case KC_GBP:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // Mac
                    set_unicode_input_mode(UNICODE_MODE_MACOS);
                } else {
                    // Windows
                    set_unicode_input_mode(UNICODE_MODE_WINDOWS);
                }
                send_unicode_string("£");
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Left encoder is backwards
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
   } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
    return false;
}

#endif
