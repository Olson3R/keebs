// Copyright 2024 Scott Olson (@olson3r)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Use EEPROM to determine handedness
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_split_keyboard.md#handedness-by-eeprom
#define EE_HANDS

// #define SPLIT_USB_DETECT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md
#define ENCODERS_PAD_A { GP4 }
#define ENCODERS_PAD_B { GP3 }
#define ENCODER_RESOLUTION 2

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
