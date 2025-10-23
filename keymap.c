// Copyright 2023 JoyLee (@itarze)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "immobile.h"
#include "color.h"

uint8_t Shift_key_press = 0;
uint8_t KC_GRV_key_Release_flag = 0;
enum layers {
    _LB = 0,
    _LF,
    _LS,
    _LM,
    _LMF,
    _LMS
};

#define RGB_HSV_MAX 7
static uint8_t rgb_hsvs[7][3] = {
    {HSV_RED},
    {HSV_YELLOW},
    {HSV_GREEN},
    {HSV_CYAN},
    {HSV_BLUE},
    {HSV_PINK},
    {HSV_WHITE},
};

void rgb_matrix_indicators_val_user(void);
void rgb_matrix_decrease_val_user(void);
void rgb_matrix_disable_user(void);
void rgb_matrix_enable_user(void);
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LB] = LAYOUT( /* Base */
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_BSPC,    KC_INS,KC_MUTE,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,   KC_BSLS,    KC_DEL,
        KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,                KC_PGUP,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,               KC_UP,      KC_PGDN,
        KC_LCTL,   KC_LGUI, KC_LALT,                            KC_SPC,KC_SPC,KC_SPC,                             MO(_LF), KC_RCTL,    KC_LEFT,   KC_DOWN,    KC_RGHT),

    [_LF] = LAYOUT( /* Base */
        EE_CLR,    KC_MYCM, KC_WHOM, KC_MAIL, KC_CALC, KC_MSEL, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, RGB_TOG, _______,KC_MUTE,
        TO(_LM),   IM_BT1,  IM_BT2,  IM_BT3,  IM_2G4,  IM_USB, _______,  _______, _______, _______, KC_PSCR, _______, _______, RGB_MOD, _______,
        _______,   _______, _______, _______, _______, _______, KC_SCRL, KC_PAUS, KC_HOME, KC_END,  _______, _______, RGB_HUI,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          RGB_VAI, _______,
        NUM_TOF1,   GU_TOGG, _______,                            IM_BATQ,IM_BATQ,IM_BATQ,                            _______, _______, RGB_SPD, RGB_VAD, RGB_SPI),

    [_LS] = LAYOUT( /* Base */
        EE_CLR,    KC_MYCM, KC_WHOM, KC_MAIL, KC_CALC, KC_MSEL, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, RGB_TOG, _______,KC_MUTE,
        TO(_LM),   IM_BT1,  IM_BT2,  IM_BT3,  IM_2G4,  IM_USB, _______,  _______, _______, _______, KC_PSCR, _______, _______, RGB_MOD, _______,
        _______,   _______, _______, _______, _______, _______, KC_SCRL, KC_PAUS, KC_HOME, KC_END,  _______, _______, RGB_HUI,          _______,
        _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          RGB_VAI, _______,
        NUM_TOF1,   GU_TOGG, _______,                            IM_BATQ,IM_BATQ,IM_BATQ,                            _______, _______, RGB_SPD, RGB_VAD, RGB_SPI),

    [_LM] = LAYOUT(  /* Base */
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_BSPC,    KC_INS,KC_MUTE,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,   KC_BSLS,    KC_DEL,
        KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,                KC_PGUP,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,               KC_UP,      KC_PGDN,
        KC_LCTL,   KC_LALT, KC_LGUI,                            KC_SPC,KC_SPC,KC_SPC,                           MO(_LMF),KC_RCTL,    KC_LEFT,   KC_DOWN,    KC_RGHT),

    [_LMF] = LAYOUT(  /* FN */
        EE_CLR,    KC_BRIU, KC_BRID, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, RGB_TOG, _______,KC_MUTE,
        TO(_LB),   IM_BT1,  IM_BT2,  IM_BT3,  IM_2G4,  IM_USB, _______,  _______, _______, _______, KC_PSCR, _______, _______, RGB_MOD, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI,          _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_VAI, _______,
        NUM_TOF1,   _______, _______,                            IM_BATQ,IM_BATQ,IM_BATQ,                            _______, _______, RGB_SPD, RGB_VAD, RGB_SPI),
    [_LMS] = LAYOUT(  /* FN */
        EE_CLR,    KC_BRIU, KC_BRID, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, RGB_TOG, _______,KC_MUTE,
        TO(_LB),   IM_BT1,  IM_BT2,  IM_BT3,  IM_2G4,  IM_USB, _______,  _______, _______, _______, KC_PSCR, _______, _______, RGB_MOD, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI,          _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_VAI, _______,
        NUM_TOF1,   _______, _______,                            IM_BATQ,IM_BATQ,IM_BATQ,                            _______, _______, RGB_SPD, RGB_VAD, RGB_SPI)

};
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {

    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [1] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [3] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [4] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [5] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
};
#endif

// clang-format on
#ifdef RGB_MATRIX_BLINK_ENABLE
void bat_indicators_hook(uint8_t index);

blink_rgb_t blink_rgbs[RGB_MATRIX_BLINK_COUNT] = {
    {.index = IM_MM_RGB_BLINK_INDEX_BT1, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_BT2, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_BT3, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_2G4, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_W2M, .interval = 500, .times = 3, .color = {.r = 150, .g = 150, .b = 150}, .blink_cb = NULL},
    {.index = IM_MM_RGB_BLINK_INDEX_W2H, .interval = 500, .times = 3, .color = {.r = 150, .g = 150, .b = 150}, .blink_cb = NULL},
    {.index = RGB_MATRIX_BLINK_INDEX_BAT, .interval = 250, .times = 3, .color = {.r = 0x00, .g = 0x00, .b = 0x00}, .blink_cb = NULL},
    {.index = RGB_MATRIX_BLINK_INDEX_ALL, .interval = 500, .times = 5, .color = {.r = 100, .g = 100, .b = 100}, .blink_cb = NULL},
};
#endif

#ifndef MATRIX_LKEY_DISABLE
im_lkey_t lkey_define_user[IM_LKEY_COUNT] = {
    {.keycode = TO(_LB), .hole_time = 3000}, // 参数：按键值，长按时间
    {.keycode = TO(_LM), .hole_time = 3000}, // 参数：按键值，长按时间
};
#endif

typedef enum {
    BAT_NORMAL,
    BAT_LOW,
    BAT_CHRGING,
    BAT_FULL,
} bat_statue_t;
bat_statue_t bat_statue = BAT_NORMAL;

static bool bat_blink = false;
static uint8_t battery_full_flag = 1;
static uint8_t battery_chrg_flag = 1;
static bool full_flag = false;
static uint16_t laste_time_off = 0;

#ifdef RGB_MATRIX_BLINK_INDEX_BAT

void bat_indicators_hook(uint8_t index) {

    if (mm_eeconfig.devs != DEVS_USB) {
        if ((!mm_eeconfig.charging) && (bts_info.bt_info.pvol <= BATTERY_CAPACITY_LOW)) {
            /* 低电提醒 */
            rgb_matrix_blink_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_RED);
            rgb_matrix_blink_set_interval_times(index, 500, 0x3);
            bat_blink = true;
            bat_statue = BAT_LOW;
        } else {
            bat_blink = false;
        }

        if ((bts_info.bt_info.pvol < 1U) && (!mm_eeconfig.charging)) {
            if (laste_time_off == 0) laste_time_off = timer_read();
            if (timer_elapsed(laste_time_off)>10000) {
                laste_time_off=0;
                im_set_power_off();
            }
        } else {
            laste_time_off = 0;
        }
    } else {
        bat_blink = false;
    }

    rgb_matrix_blink_set(index);
}

bool rgb_matrix_blink_user(blink_rgb_t *blink_rgb) {
    if (blink_rgb->index == RGB_MATRIX_BLINK_INDEX_BAT) {
        if (bat_blink != true) {
            return false;
        }
    }
    return true;
}

#endif
typedef union {
    uint32_t raw;
    struct {
        uint8_t flag: 1;
        uint8_t rgb_enable: 1;
        uint8_t no_gui: 1;
        uint8_t rgb_status: 1;
        uint8_t layer: 3;
        uint8_t rgb_hsv_index: 3;
        uint8_t rgb_brightness;
        uint8_t Num_To_F1: 1;

    };
} confinfo_t;
confinfo_t confinfo;

#ifdef RGB_MATRIX_ENABLE

// 此函数不需要改动
bool mm_get_rgb_enable(void) {
#    ifdef RGBLIGHT_ENABLE
    return confinfo.rgb_enable;
#    else
    return rgb_matrix_config.enable;
#    endif
}

// 此函数不需要改动
void mm_set_rgb_enable(bool state) {
#    ifdef RGBLIGHT_ENABLE
    confinfo.rgb_enable = state;
    eeconfig_update_user(confinfo.raw);
#    else
    rgb_matrix_config.enable = state;
#    endif
}
#endif

void eeconfig_confinfo_default(void) {
    confinfo.flag = false;
    confinfo.rgb_enable = true;
    confinfo.no_gui = false;
    confinfo.rgb_status = 0;
    confinfo.layer = _LB;
    confinfo.rgb_hsv_index = 0;
    confinfo.rgb_brightness = RGB_MATRIX_DEFAULT_VAL;
    confinfo.Num_To_F1 = 0;
    eeconfig_update_user(confinfo.raw);
}
bool im_led_deinit_user(void) {

    writePin(RGB_DRIVER_EN_PIN, 0);
    writePin(POWER_DCDC_EN_PIN, 0);

    return true;
}

bool im_led_init_user() {

    writePin(POWER_DCDC_EN_PIN, 1);
    writePin(RGB_DRIVER_EN_PIN, 1);
    return true;
}

// 初始化一些GPIO PIN 相关的操作
bool im_pre_init_user(void) {
    setPinInputHigh(CHRG_PIN);
    setPinOutput(RGB_DRIVER_EN_PIN);

    setPinOutput(POWER_DCDC_EN_PIN);
    writePin(POWER_DCDC_EN_PIN, 1);

    return true;
}

static uint32_t readbat = 0x00;
// 初始化和参数相关的操作，在恢复出厂设置时此函数会被调用
bool im_init_user(void) {
    setPinOutput(RGB_DRIVER_EN_PIN);
    writePin(RGB_DRIVER_EN_PIN, 1);
    setPinInputHigh(CHRG_PIN);
    setPinInputHigh(FULL_PIN);

    confinfo.raw = eeconfig_read_user();
    if (!confinfo.raw) {
        eeconfig_confinfo_default();
    }
    readbat = timer_read32();
#ifdef RGB_MATRIX_BLINK_INDEX_BAT
    rgb_matrix_blink_set(RGB_MATRIX_BLINK_INDEX_BAT);
#endif

    return true;
}

// 恢复出厂设置回调函数
bool im_reset_settings_user(void) {

    rgb_matrix_blink_set_color(RGB_MATRIX_BLINK_INDEX_ALL, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0x0, 0x0);
    rgb_matrix_blink_set_interval_times(RGB_MATRIX_BLINK_INDEX_ALL, 500, 3);
    rgb_matrix_blink_set(RGB_MATRIX_BLINK_INDEX_ALL);

    return true;
}
bool chrg_flag = false;
// 无限循环
bool im_loop_user(void) {

    if (timer_elapsed32(readbat) >= 3000) {
        readbat = timer_read32();
        battery_chrg_flag = readPin(CHRG_PIN);
        battery_full_flag = readPin(FULL_PIN);
    }

    if ((!mm_eeconfig.charging) && full_flag ) {
        full_flag = false;
    }

    if ((chrg_flag) && (!battery_full_flag)) {
        if (bat_statue != BAT_FULL) bts_send_vendor(v_bat_full);
        full_flag = true;
        bat_statue = BAT_FULL;
    }

    if ((!mm_eeconfig.charging) && (bat_statue != BAT_LOW)) {
        if (bat_statue != BAT_NORMAL) bts_send_vendor(v_bat_stop_charging);
        bat_statue = BAT_NORMAL;
    }

    return true;
}

void rgb_matrix_disable_user(void) {
    confinfo.rgb_status = 1;
    confinfo.rgb_brightness = rgb_matrix_get_val();
    eeconfig_update_user(confinfo.raw);
    rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), 0);
}

void rgb_matrix_enable_user(void) {
    confinfo.rgb_status = 0;
    eeconfig_update_user(confinfo.raw);
    rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), confinfo.rgb_brightness);
}

bool im_mm_rgb_blink_hook_user(uint8_t index, mm_linker_rgb_t state) {

#if defined(RGB_MATRIX_BLINK_ENABLE) && defined(MULTIMODE_ENABLE)
    switch (state) {
        case mlrs_lback_succeed:
        case mlrs_pair_succeed: {
            im_mm_rgb_blink_set_state(mlrs_none);
            return true;
        } break;

        default:
            break;
    }
#endif

    return true;
}

const uint8_t f1_12_keycode[]=
{KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12};
bool im_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_RIGHT_SHIFT:
    case KC_LEFT_SHIFT:
    {
        Shift_key_press = record->event.pressed;
        return true;
    }
    break;
    case KC_ESC:{

            if (record->event.pressed)
            {
                if(Shift_key_press == 1 )
                {
                    register_code16(KC_GRV);
                    KC_GRV_key_Release_flag =1;
                     return false;
                }

            }
            else
            {
                if(KC_GRV_key_Release_flag == 1){
                    unregister_code16(KC_GRV);
                    KC_GRV_key_Release_flag=0;
                    return false;
                }

            }
        return true;
    }
    break;
    case KC_1:
    case KC_2:
    case KC_3:
    case KC_4:
    case KC_5:
    case KC_6:
    case KC_7:
    case KC_8:
    case KC_9:
    case KC_0:
    {
            if(confinfo.Num_To_F1 ==true){
                if (record->event.pressed) {
                        register_code16(f1_12_keycode[keycode-KC_1 ]);
                    } else {
                        unregister_code16(f1_12_keycode[keycode-KC_1 ]);
                    }
                    return false;
            }
    }
        return true;
    break;
    case KC_MINS:
     {
            if(confinfo.Num_To_F1 ==true){
                if (record->event.pressed) {
                        register_code16(KC_F11);
                    } else {
                        unregister_code16(KC_F11);
                    }
                    return false;
            }
    }
        return true;
    break;
    case KC_EQL:
    {
            if(confinfo.Num_To_F1 ==true){
                if (record->event.pressed) {
                        register_code16(KC_F12);
                    } else {
                        unregister_code16(KC_F12);
                    }
                    return false;
            }
    }
        return true;
    break;
    case NUM_TOF1:
        if (record->event.pressed)
        {
            confinfo.Num_To_F1 = !confinfo.Num_To_F1;
            eeconfig_update_user(confinfo.raw);
        }
        return false;
    break;
    case KC_LGUI: {
        if (record->event.pressed)
        {
            if(confinfo.no_gui)
            return false;
            else
            return true;
        }
    }break;
    case GU_TOGG: {
        if(record->event.pressed){
            confinfo.no_gui = !confinfo.no_gui;
            eeconfig_update_user(confinfo.raw);
        }
        return false;
    }break;
    case RGB_HUI:
        if (record->event.pressed) {
            uint8_t now_mode_one = rgb_matrix_get_mode();
            if((now_mode_one == 6) ||(now_mode_one == 13) ||(now_mode_one == 15) ||(now_mode_one == 16) ||(now_mode_one == 25) ||(now_mode_one == 26) ||(now_mode_one == 34)){
                confinfo.rgb_hsv_index = (confinfo.rgb_hsv_index + 1) % 6;
                rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                                    rgb_hsvs[confinfo.rgb_hsv_index][1],
                                    rgb_matrix_get_val());
            }else{
                confinfo.rgb_hsv_index = (confinfo.rgb_hsv_index + 1) % 7;
                rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                                    rgb_hsvs[confinfo.rgb_hsv_index][1],
                                    rgb_matrix_get_val());
            }
            eeconfig_update_user(confinfo.raw);
        }
        return false;
        break;
    case RGB_HUD:
        if (record->event.pressed) {
            uint8_t now_mode_one = rgb_matrix_get_mode();
            if((now_mode_one == 6) ||(now_mode_one == 13) ||(now_mode_one == 15) ||(now_mode_one == 16) ||(now_mode_one == 25) ||(now_mode_one == 26) ||(now_mode_one == 34)){
                (confinfo.rgb_hsv_index == 0)? (confinfo.rgb_hsv_index = 5):(confinfo.rgb_hsv_index = confinfo.rgb_hsv_index - 1);
                rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                                    rgb_hsvs[confinfo.rgb_hsv_index][1],
                                    rgb_matrix_get_val());
            }else{
                (confinfo.rgb_hsv_index == 0)? (confinfo.rgb_hsv_index = 6):(confinfo.rgb_hsv_index = confinfo.rgb_hsv_index - 1);
                rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                                    rgb_hsvs[confinfo.rgb_hsv_index][1],
                                    rgb_matrix_get_val());

            }
            eeconfig_update_user(confinfo.raw);
        }
        return false;
        break;
    case RGB_MOD: {
        if(record->event.pressed){
            if(rgb_matrix_get_mode() == 31) {
                rgb_matrix_mode(33);
                return false;
            }
        }
        return true;
    }break;
    case RGB_RMOD: {
        if(record->event.pressed){
            if(rgb_matrix_get_mode() == 33) {
                rgb_matrix_mode(31);
                return false;
            }
        }
        return true;
    }break;

    case IM_BATQ:{
        return (mm_eeconfig.devs != DEVS_USB);
    }break;

    case TO(_LB):
    case TO(_LM): {
        return false;
    }break;
    case US_TS1: { // 低频
        if (record->event.pressed) {
            bts_send_vendor(0x60);
            bts_rf_send_carrier(0, 5, 0x01);
        } break;
        return false;
    } break;
    case US_TS2: { // 中频
        if (record->event.pressed) {
            bts_send_vendor(0x60);
            bts_rf_send_carrier(19, 5, 0x01);
        } break;
        return false;
    } break;
    case US_TS3: { // 高频
        if (record->event.pressed) {
            bts_send_vendor(0x60);
            bts_rf_send_carrier(38, 5, 0x01);
        } break;
        return false;
    } break;
    case US_STOP: { // 停止
        if (record->event.pressed) {
            bts_rf_send_stop();
        } break;
        return false;
    } break;
    default:
    break;
    }
    return true;
}

bool im_lkey_process_user(uint16_t keycode, bool pressed) {

    switch (keycode) {
        case TO(_LB): {
            if (pressed) {
                rgb_matrix_blink_set_interval_times(IM_MM_RGB_BLINK_INDEX_W2M, 250, 1);
                rgb_matrix_blink_set(IM_MM_RGB_BLINK_INDEX_W2M);
                set_single_persistent_default_layer(_LB);
                confinfo.layer = _LB;
            eeconfig_update_user(confinfo.raw);
            }
            return false;
        } break;
        case TO(_LM): {
            if (pressed) {
                rgb_matrix_blink_set_interval_times(IM_MM_RGB_BLINK_INDEX_W2M, 250, 3);
                rgb_matrix_blink_set(IM_MM_RGB_BLINK_INDEX_W2M);
                set_single_persistent_default_layer(_LM);
                confinfo.layer = _LM;
                confinfo.no_gui = false;
                eeconfig_update_user(confinfo.raw);
            }
            return false;
        } break;

    }
    return true;
}
#ifdef RGB_MATRIX_ENABLE

#ifndef RGB_MATRIX_BAT_VAL
#    define RGB_MATRIX_BAT_VAL R GB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {


    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(36, 0xff, 0xff, 0xff);
    }

    if ((!battery_chrg_flag) && (!full_flag)) {
        if (bat_statue != BAT_CHRGING) bts_send_vendor(v_bat_charging);
        rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_BLUE);
        chrg_flag = true;
        bat_statue = BAT_CHRGING;
    }

    if (confinfo.no_gui)
    {
        rgb_matrix_set_color(2, 0xff, 0xff, 0xff);

    }
    return true;
}
#endif
