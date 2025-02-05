// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// enum {
//     TD_PP_L1,
//     TD_PP_L0,
//     TD_SS_BL
// };

// typedef enum {
//     TD_NONE,
//     TD_SINGLE_TAP,
//     TD_TRIPLE_TAP_HOLD
// } td_ss_bl_state_t;

// static td_ss_bl_state_t td_ss_bl_state;

// td_ss_bl_state_t cur_dance(tap_dance_state_t *state) {
//     if (state->count == 3) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         return TD_TRIPLE_TAP_HOLD;
//     }

//     return TD_SINGLE_TAP;
// }

// void td_screenshot_or_bootloader_finished (tap_dance_state_t *state, void *user_data) {
//     td_ss_bl_state = cur_dance(state);
//     switch (td_ss_bl_state) {
//         case TD_SINGLE_TAP:
//             register_code(KC_LGUI);
//             register_code(KC_LCTL);
//             register_code(KC_LSFT);
//             register_code(KC_4);
//             break;
//         case TD_TRIPLE_TAP_HOLD:
//             reset_keyboard();
//             break;
//         default:
//             break;
//     }
// }

// void td_screenshot_or_bootloader_reset (tap_dance_state_t *state, void *user_data) {
//     switch (td_ss_bl_state) {
//         case TD_SINGLE_TAP:
//             unregister_code(KC_LGUI);
//             unregister_code(KC_LCTL);
//             unregister_code(KC_LSFT);
//             unregister_code(KC_4);
//             break;
//         default:
//             break;
//     }
// }

// // Tap Dance definitions
// tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_PP_L0] = ACTION_TAP_DANCE_LAYER_MOVE(KC_MEDIA_PLAY_PAUSE, 0),
//     [TD_PP_L1] = ACTION_TAP_DANCE_LAYER_MOVE(KC_MEDIA_PLAY_PAUSE, 1),
//     [TD_SS_BL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_screenshot_or_bootloader_finished, td_screenshot_or_bootloader_reset)
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_A, LSFT_T(KC_S), LT(1, KC_D), KC_F, KC_G,
        LCTL_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,
        KC_SPACE, KC_ENTER,
        KC_BACKSPACE, KC_LEFT_GUI, TO(1),

        KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_H, KC_J, LT(1, KC_K), RSFT_T(KC_L), KC_SEMICOLON,
        KC_N, KC_M, KC_COMMA, RALT_T(KC_DOT), RCTL_T(KC_SLASH),
        KC_ENTER, KC_SPACE,
        KC_RIGHT_GUI, KC_ESCAPE, KC_SPACE
    ),
    [1] = LAYOUT(
        KC_BRIGHTNESS_UP, KC_MINUS, KC_EQUAL, KC_GRAVE, QK_BOOTLOADER,
        KC_QUOTE, LSFT_T(KC_BRIGHTNESS_DOWN), KC_UP, KC_LEFT_BRACKET, KC_RIGHT_BRACKET,
        KC_TAB, KC_LEFT, KC_DOWN, KC_RIGHT,MT(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK),
        KC_SPACE, KC_ENTER,
        KC_BACKSPACE, KC_LEFT_GUI, TO(0),

        KC_SPACE, KC_7, KC_8, KC_9, KC_P,
        KC_ASTERISK, KC_4, KC_5, RSFT_T(KC_6), KC_0,
        KC_TAB, KC_1, KC_2, KC_3, KC_BACKSLASH,
        KC_ENTER, KC_SPACE,
        KC_RIGHT_GUI, KC_ESCAPE, KC_SPACE
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [1] = { ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) }
};
#endif
