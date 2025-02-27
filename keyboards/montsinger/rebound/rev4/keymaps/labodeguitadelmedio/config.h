/*
Copyright 2020 Ross Montsinger
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define TAPPING_TERM 175

#define GUI_COPY MT(MOD_LGUI, KC_F23)
#define CMD_COPY LGUI_T(KC_LANG6)

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_NUMERIC

#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */


/* USB Device descriptor parameter */

#define VENDOR_ID 0x524D
#define PRODUCT_ID 0x0001
#define DEVICE_VER 0x0002


/* key matrix size */

#define MATRIX_ROWS 8
#define MATRIX_COLS 7

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on
diode)
 * ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

#define MATRIX_ROW_PINS { D1, D0, D4, C6, F7, F6, F5, F4 }
#define MATRIX_COL_PINS { D7, E6, B4, B5, B2, B3, B1 }
#define UNUSED_PINS { B6 }

#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN B6
#define RGBLED_NUM 17

/* Bootmagic Lite key configuration */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0
