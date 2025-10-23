/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* USB */
#define MANUFACTURER "Lucky65V2"
#define PRODUCT "Lucky65V2"
#define VENDOR_ID 0x342d
#define PRODUCT_ID 0xe407
#define DEVICE_VER 0x0001
#define FORCE_NKRO
#define USB_SUSPEND_WAKEUP_DELAY 1000

/* Multimode */
#ifdef MULTIMODE_ENABLE
#    define MM_USB_EN_PIN C13
#    define MM_USB_EN_STATE 0

#    define MM_BT1_NAME "Lucky65V2-1"
#    define MM_BT2_NAME "Lucky65V2-2"
#    define MM_BT3_NAME "Lucky65V2-3"

#    define MM_DONGLE_PRODUCT "Lucky65V2"


// USB模式未插入USB时跟随无线模式一致，进行超时休眠
#    define MM_USB_AUTO_SLEEP_DISABLE
#    define IM_MM_USB_TIMES 1

#    define MM_BAT_CABLE_PIN B9

#    define RGB_MATRIX_BAT_INDEX_MAP {65,  64,  63,  62,  61,  60,  59,  58,  57,  56,}
#    define IM_BAT_REQ_LEVEL1_COLOR RGB_RED
#    define IM_BAT_REQ_LEVEL2_COLOR RGB_RED
#    define IM_BAT_REQ_LEVEL3_COLOR RGB_RED

#    define MM_SLEEP_TIMEOUT (3 * 60000) // 3 min

#    define RGB_DRIVER_EN_PIN B12
#    define IM_LKEY_COUNT 4 // 用户自定义长按按键数量

#    define RGB_MATRIX_BLINK_COUNT 13
#    define RGB_MATRIX_BLINK_INDEX_BAT 3
#    define RGB_MATRIX_BLINK_INDEX_ALL 0xFF

#    define IM_MM_RGB_BLINK_INDEX_BT1 38
#    define IM_MM_RGB_BLINK_INDEX_BT2 39
#    define IM_MM_RGB_BLINK_INDEX_BT3 40
#    define IM_MM_RGB_BLINK_INDEX_2G4 41

#    define IM_MM_LBACK_TIMEOUT (30 * 1000)
#    define IM_MM_PAIR_TIMEOUT (180 * 1000)
#    define IM_MM_SUCCEED_TIME (2 * 1000)

#    define IM_MM_LBACK_COLOR_BT1 0, 100, 150
#    define IM_MM_LBACK_COLOR_BT2 RGB_YELLOW
#    define IM_MM_LBACK_COLOR_BT3 255,0,127
#    define IM_MM_LBACK_COLOR_2G4 RGB_BLUE

#    define IM_MM_PAIR_COLOR_BT1 0, 100, 150
#    define IM_MM_PAIR_COLOR_BT2 RGB_YELLOW
#    define IM_MM_PAIR_COLOR_BT3 255,0,127
#    define IM_MM_PAIR_COLOR_2G4 RGB_BLUE

#define IM_RGB_BAT_REQ_CLOSE_ALL

#endif

/*DCDC*/
#define CHRG_PIN C7
#define FULL_PIN C6

#define POWER_DCDC_EN_PIN B13

#define BATTERY_CAPACITY_LOW 30
#define BATTERY_CAPACITY_STOP 0

#define IM_MM_RGB_BLINK_INDEX_W2M 37
#define IM_MM_RGB_BLINK_INDEX_W2H 37

#define ENCODERS_PAD_A { C8 }
#define ENCODERS_PAD_B { C9 }
#define ENCODER_MAP_KEY_DELAY 1
#define ENCODER_RESOLUTION 2

/* UART */
#define SERIAL_DRIVER SD3
#define SD1_TX_PIN C10
#define SD1_RX_PIN C11
#define SELECT_SOFT_SERIAL_SPEED 1

/* DEBOUNCE */
#define DEBOUNCE 8
#define HOLD_ON_OTHER_KEY_PRESS

/* Key Matrix */
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define MATRIX_ROWS 5
#define MATRIX_COLS 15
#define DIODE_DIRECTION ROW2COL
#define MATRIX_COL_PINS \
    { B0, B1, B2, B3, B4, B5, B6, B7, C12, D2, B10, B11, A10, A15, A9}
#define MATRIX_ROW_PINS \
    { A1, A2, A3, A4, A8 }

/* SPI Config for LED Driver */
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN A5
#define SPI_MOSI_PIN A7
#define SPI_MISO_PIN A6

/* Flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN B14
#define WEAR_LEVELING_BACKING_SIZE (4 * 1024)
#define WEAR_LEVELING_LOGICAL_SIZE (WEAR_LEVELING_BACKING_SIZE / 2)
#define FEE_PAGE_COUNT (WEAR_LEVELING_BACKING_SIZE / FEE_PAGE_SIZE)

/* RGB Matrix */
#define RGB_DI_PIN B15
#define WS2812_SPI SPIDM2
#define WS2812_SPI_DIVISOR 24

#define RGB_MATRIX_LED_COUNT (67)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_MATRIX_STARTUP_MODE 13
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_VAL_STEP 20
#define RGB_MATRIX_DEFAULT_VAL 200
#define RGB_MATRIX_SPD_STEP 25
#define RGB_MATRIX_DEFAULT_SPD 75
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_TRIGGER_ON_KEYDOWN

// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
