/* Copyright 2022 zhaqian
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

#include "dynamic_rgb_indicators.h"
#include <lib/lib8tion/lib8tion.h>
#include "color.h"
#include <stdlib.h>
#include "eeprom.h"

#ifdef DEFAULT_NUM_LOCK_ENABLE 
#define DEFAULT_NUM_LOCK_ENABLE_VAL 1
#else
#define DEFAULT_NUM_LOCK_ENABLE_VAL 0
#endif

#ifdef DEFAULT_NUM_LOCK_ALL_LED
#define DEFAULT_NUM_LOCK_ALL_LED_VAL 1
#else
#define DEFAULT_NUM_LOCK_ALL_LED_VAL 0
#endif

#ifdef DEFAULT_NUM_LOCK_KEY_LED
#define DEFAULT_NUM_LOCK_KEY_LED_VAL 1
#else
#define DEFAULT_NUM_LOCK_KEY_LED_VAL 0
#endif

#ifdef DEFAULT_NUM_LOCK_UNDERGLOW_LED
#define DEFAULT_NUM_LOCK_UNDERGLOW_LED_VAL 1
#else
#define DEFAULT_NUM_LOCK_UNDERGLOW_LED_VAL 0
#endif

#ifndef DEFAULT_NUM_LOCK_MODE
#define DEFAULT_NUM_LOCK_MODE 1
#endif

#ifdef DEFAULT_NUM_LOCK_LOGO_LED
#define DEFAULT_NUM_LOCK_LOGO_LED_VAL 1
#else
#define DEFAULT_NUM_LOCK_LOGO_LED_VAL 0
#endif

#ifndef DEFAULT_NUM_LOCK_LED
#define DEFAULT_NUM_LOCK_LED 0
#endif

#ifndef DEFAULT_NUM_LOCK_HSV
#define DEFAULT_NUM_LOCK_HSV {240, 255, DYNAMIC_RGB_INDICATORS_DEFAULT_VAL}
#endif

#ifdef DEFAULT_CAPS_LOCK_ENABLE 
#define DEFAULT_CAPS_LOCK_ENABLE_VAL 1
#else
#define DEFAULT_CAPS_LOCK_ENABLE_VAL 0
#endif

#ifdef DEFAULT_CAPS_LOCK_ALL_LED
#define DEFAULT_CAPS_LOCK_ALL_LED_VAL 1
#else
#define DEFAULT_CAPS_LOCK_ALL_LED_VAL 0
#endif

#ifdef DEFAULT_CAPS_LOCK_KEY_LED
#define DEFAULT_CAPS_LOCK_KEY_LED_VAL 1
#else
#define DEFAULT_CAPS_LOCK_KEY_LED_VAL 0
#endif

#ifdef DEFAULT_CAPS_LOCK_UNDERGLOW_LED
#define DEFAULT_CAPS_LOCK_UNDERGLOW_LED_VAL 1
#else
#define DEFAULT_CAPS_LOCK_UNDERGLOW_LED_VAL 0
#endif

#ifndef DEFAULT_CAPS_LOCK_MODE
#define DEFAULT_CAPS_LOCK_MODE 1
#endif

#ifdef DEFAULT_CAPS_LOCK_LOGO_LED
#define DEFAULT_CAPS_LOCK_LOGO_LED_VAL 1
#else
#define DEFAULT_CAPS_LOCK_LOGO_LED_VAL 0
#endif

#ifndef DEFAULT_CAPS_LOCK_LED
#define DEFAULT_CAPS_LOCK_LED 1
#endif

#ifndef DEFAULT_CAPS_LOCK_HSV
#define DEFAULT_CAPS_LOCK_HSV {0, 255, DYNAMIC_RGB_INDICATORS_DEFAULT_VAL}
#endif

#ifdef DEFAULT_SCROLL_LOCK_ENABLE 
#define DEFAULT_SCROLL_LOCK_ENABLE_VAL 1
#else
#define DEFAULT_SCROLL_LOCK_ENABLE_VAL 0
#endif

#ifdef DEFAULT_SCROLL_LOCK_ALL_LED
#define DEFAULT_SCROLL_LOCK_ALL_LED_VAL 1
#else
#define DEFAULT_SCROLL_LOCK_ALL_LED_VAL 0
#endif

#ifdef DEFAULT_SCROLL_LOCK_KEY_LED
#define DEFAULT_SCROLL_LOCK_KEY_LED_VAL 1
#else
#define DEFAULT_SCROLL_LOCK_KEY_LED_VAL 0
#endif

#ifdef DEFAULT_SCROLL_LOCK_UNDERGLOW_LED
#define DEFAULT_SCROLL_LOCK_UNDERGLOW_LED_VAL 1
#else
#define DEFAULT_SCROLL_LOCK_UNDERGLOW_LED_VAL 0
#endif

#ifndef DEFAULT_SCROLL_LOCK_MODE
#define DEFAULT_SCROLL_LOCK_MODE 1
#endif

#ifdef DEFAULT_SCROLL_LOCK_LOGO_LED
#define DEFAULT_SCROLL_LOCK_LOGO_LED_VAL 1
#else
#define DEFAULT_SCROLL_LOCK_LOGO_LED_VAL 0
#endif

#ifndef DEFAULT_SCROLL_LOCK_LED
#define DEFAULT_SCROLL_LOCK_LED 2
#endif

#ifndef DEFAULT_SCROLL_LOCK_HSV
#define DEFAULT_SCROLL_LOCK_HSV {120, 255, DYNAMIC_RGB_INDICATORS_DEFAULT_VAL}
#endif

#ifdef DEFAULT_LAYER_1_ENABLE 
#define DEFAULT_LAYER_1_ENABLE_VAL 1
#else
#define DEFAULT_LAYER_1_ENABLE_VAL 0
#endif

#ifdef DEFAULT_LAYER_1_ALL_LED
#define DEFAULT_LAYER_1_ALL_LED_VAL 1
#else
#define DEFAULT_LAYER_1_ALL_LED_VAL 0
#endif

#ifdef DEFAULT_LAYER_1_KEY_LED
#define DEFAULT_LAYER_1_KEY_LED_VAL 1
#else
#define DEFAULT_LAYER_1_KEY_LED_VAL 0
#endif

#ifdef DEFAULT_LAYER_1_UNDERGLOW_LED
#define DEFAULT_LAYER_1_UNDERGLOW_LED_VAL 1
#else
#define DEFAULT_LAYER_1_UNDERGLOW_LED_VAL 0
#endif

#ifndef DEFAULT_LAYER_1_MODE
#define DEFAULT_LAYER_1_MODE 1
#endif

#ifdef DEFAULT_LAYER_1_LOGO_LED
#define DEFAULT_LAYER_1_LOGO_LED_VAL 1
#else
#define DEFAULT_LAYER_1_LOGO_LED_VAL 0
#endif

#ifndef DEFAULT_LAYER_1_LED
#define DEFAULT_LAYER_1_LED 0
#endif

#ifndef DEFAULT_LAYER_1_HSV
#define DEFAULT_LAYER_1_HSV {0, 255, DYNAMIC_RGB_INDICATORS_DEFAULT_VAL}
#endif

// 下面是LAYER_2的设置

#ifdef DEFAULT_LAYER_2_ENABLE 
#define DEFAULT_LAYER_2_ENABLE_VAL 1
#else
#define DEFAULT_LAYER_2_ENABLE_VAL 0
#endif

#ifdef DEFAULT_LAYER_2_ALL_LED
#define DEFAULT_LAYER_2_ALL_LED_VAL 1
#else
#define DEFAULT_LAYER_2_ALL_LED_VAL 0
#endif

#ifdef DEFAULT_LAYER_2_KEY_LED
#define DEFAULT_LAYER_2_KEY_LED_VAL 1
#else
#define DEFAULT_LAYER_2_KEY_LED_VAL 0
#endif

#ifdef DEFAULT_LAYER_2_UNDERGLOW_LED
#define DEFAULT_LAYER_2_UNDERGLOW_LED_VAL 1
#else
#define DEFAULT_LAYER_2_UNDERGLOW_LED_VAL 0
#endif

#ifndef DEFAULT_LAYER_2_MODE
#define DEFAULT_LAYER_2_MODE 1
#endif

#ifdef DEFAULT_LAYER_2_LOGO_LED
#define DEFAULT_LAYER_2_LOGO_LED_VAL 1
#else
#define DEFAULT_LAYER_2_LOGO_LED_VAL 0
#endif

#ifndef DEFAULT_LAYER_2_LED
#define DEFAULT_LAYER_2_LED 0
#endif

#ifndef DEFAULT_LAYER_2_HSV
#define DEFAULT_LAYER_2_HSV {0, 255, DYNAMIC_RGB_INDICATORS_DEFAULT_VAL}
#endif

// 下面是LAYER_3的设置

#ifdef DEFAULT_LAYER_3_ENABLE 
#define DEFAULT_LAYER_3_ENABLE_VAL 1
#else
#define DEFAULT_LAYER_3_ENABLE_VAL 0
#endif

#ifdef DEFAULT_LAYER_3_ALL_LED
#define DEFAULT_LAYER_3_ALL_LED_VAL 1
#else
#define DEFAULT_LAYER_3_ALL_LED_VAL 0
#endif

#ifdef DEFAULT_LAYER_3_KEY_LED
#define DEFAULT_LAYER_3_KEY_LED_VAL 1
#else
#define DEFAULT_LAYER_3_KEY_LED_VAL 0
#endif

#ifdef DEFAULT_LAYER_3_UNDERGLOW_LED
#define DEFAULT_LAYER_3_UNDERGLOW_LED_VAL 1
#else
#define DEFAULT_LAYER_3_UNDERGLOW_LED_VAL 0
#endif

#ifndef DEFAULT_LAYER_3_MODE
#define DEFAULT_LAYER_3_MODE 1
#endif

#ifdef DEFAULT_LAYER_3_LOGO_LED
#define DEFAULT_LAYER_3_LOGO_LED_VAL 1
#else
#define DEFAULT_LAYER_3_LOGO_LED_VAL 0
#endif

#ifndef DEFAULT_LAYER_3_LED
#define DEFAULT_LAYER_3_LED 0
#endif

#ifndef DEFAULT_LAYER_3_HSV
#define DEFAULT_LAYER_3_HSV {0, 255, DYNAMIC_RGB_INDICATORS_DEFAULT_VAL}
#endif

// 下面是LAYER_4的设置

#ifdef DEFAULT_LAYER_4_ENABLE 
#define DEFAULT_LAYER_4_ENABLE_VAL 1
#else
#define DEFAULT_LAYER_4_ENABLE_VAL 0
#endif

#ifdef DEFAULT_LAYER_4_ALL_LED
#define DEFAULT_LAYER_4_ALL_LED_VAL 1
#else
#define DEFAULT_LAYER_4_ALL_LED_VAL 0
#endif

#ifdef DEFAULT_LAYER_4_KEY_LED
#define DEFAULT_LAYER_4_KEY_LED_VAL 1
#else
#define DEFAULT_LAYER_4_KEY_LED_VAL 0
#endif

#ifdef DEFAULT_LAYER_4_UNDERGLOW_LED
#define DEFAULT_LAYER_4_UNDERGLOW_LED_VAL 1
#else
#define DEFAULT_LAYER_4_UNDERGLOW_LED_VAL 0
#endif

#ifndef DEFAULT_LAYER_4_MODE
#define DEFAULT_LAYER_4_MODE 1
#endif

#ifdef DEFAULT_LAYER_4_LOGO_LED
#define DEFAULT_LAYER_4_LOGO_LED_VAL 1
#else
#define DEFAULT_LAYER_4_LOGO_LED_VAL 0
#endif

#ifndef DEFAULT_LAYER_4_LED
#define DEFAULT_LAYER_4_LED 0
#endif

#ifndef DEFAULT_LAYER_4_HSV
#define DEFAULT_LAYER_4_HSV {0, 255, DYNAMIC_RGB_INDICATORS_DEFAULT_VAL}
#endif


static const uint8_t rgb_indicators_effect_index[] = {
// to enable mode step reverse (uint8_t >= 0)
    0,
// default effect static mode
    1,
#ifdef ENABLE_RGB_INDICATORS_BREATHING
    2,
#endif

#ifdef ENABLE_RGB_INDICATORS_CYCLEBREATHING
    3,
#endif

#ifdef ENABLE_RGB_INDICATORS_CYCLEALL
    4,
#endif

#ifdef ENABLE_RGB_INDICATORS_RANDOM
    5,
#endif

#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
    6,
#endif

};

static const uint8_t rgb_indicators_effect_num = sizeof(rgb_indicators_effect_index) / sizeof(uint8_t);
static all_rgb_indicators_config_t rgb_indicators_config = {{0}, {0}, {0}, {0}, {0}, {0}, {0}};
static rgb_indicator_t rgb_indicators_state;

#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
static uint8_t changed[7] = {0};
#endif

EECONFIG_DEBOUNCE_HELPER(dynamic_rgb_indicators, EECONFIG_RGB_INDICATORS, rgb_indicators_config);

void update_dynamic_rgb_indicators(void) {
    eeconfig_flush_dynamic_rgb_indicators(true);
}

static void update_dynamic_rgb_indicators_default(void) {
    HSV tmp_hsv[7] = {DEFAULT_NUM_LOCK_HSV, DEFAULT_CAPS_LOCK_HSV, DEFAULT_SCROLL_LOCK_HSV, DEFAULT_LAYER_1_HSV, DEFAULT_LAYER_2_HSV, DEFAULT_LAYER_3_HSV, DEFAULT_LAYER_4_HSV,};
    rgb_indicators_config.num_lock_config.enable = DEFAULT_NUM_LOCK_ENABLE_VAL;
    rgb_indicators_config.num_lock_config.all_led = DEFAULT_NUM_LOCK_ALL_LED_VAL;
    rgb_indicators_config.num_lock_config.key_led = DEFAULT_NUM_LOCK_KEY_LED_VAL;
    rgb_indicators_config.num_lock_config.underglow_led = DEFAULT_NUM_LOCK_UNDERGLOW_LED_VAL;
    rgb_indicators_config.num_lock_config.logo_led = DEFAULT_NUM_LOCK_LOGO_LED_VAL;
    rgb_indicators_config.num_lock_config.mode = DEFAULT_NUM_LOCK_MODE;
    rgb_indicators_config.num_lock_config.led = DEFAULT_NUM_LOCK_LED;
    rgb_indicators_config.num_lock_config.hsv = tmp_hsv[0];

    rgb_indicators_config.caps_lock_config.enable = DEFAULT_CAPS_LOCK_ENABLE_VAL;
    rgb_indicators_config.caps_lock_config.all_led = DEFAULT_CAPS_LOCK_ALL_LED_VAL;
    rgb_indicators_config.caps_lock_config.key_led = DEFAULT_CAPS_LOCK_KEY_LED_VAL;
    rgb_indicators_config.caps_lock_config.underglow_led = DEFAULT_CAPS_LOCK_UNDERGLOW_LED_VAL;
    rgb_indicators_config.caps_lock_config.logo_led = DEFAULT_CAPS_LOCK_LOGO_LED_VAL;
    rgb_indicators_config.caps_lock_config.mode = DEFAULT_CAPS_LOCK_MODE;
    rgb_indicators_config.caps_lock_config.led = DEFAULT_CAPS_LOCK_LED;
    rgb_indicators_config.caps_lock_config.hsv = tmp_hsv[1];

    rgb_indicators_config.scroll_lock_config.enable = DEFAULT_SCROLL_LOCK_ENABLE_VAL;
    rgb_indicators_config.scroll_lock_config.all_led = DEFAULT_SCROLL_LOCK_ALL_LED_VAL;
    rgb_indicators_config.scroll_lock_config.key_led = DEFAULT_SCROLL_LOCK_KEY_LED_VAL;
    rgb_indicators_config.scroll_lock_config.underglow_led = DEFAULT_SCROLL_LOCK_UNDERGLOW_LED_VAL;
    rgb_indicators_config.scroll_lock_config.logo_led = DEFAULT_SCROLL_LOCK_LOGO_LED_VAL;
    rgb_indicators_config.scroll_lock_config.mode = DEFAULT_SCROLL_LOCK_MODE;
    rgb_indicators_config.scroll_lock_config.led = DEFAULT_SCROLL_LOCK_LED;
    rgb_indicators_config.scroll_lock_config.hsv = tmp_hsv[2];

    rgb_indicators_config.layer_1_config.enable = DEFAULT_LAYER_1_ENABLE_VAL;
    rgb_indicators_config.layer_1_config.all_led = DEFAULT_LAYER_1_ALL_LED_VAL;
    rgb_indicators_config.layer_1_config.key_led = DEFAULT_LAYER_1_KEY_LED_VAL;
    rgb_indicators_config.layer_1_config.underglow_led = DEFAULT_LAYER_1_UNDERGLOW_LED_VAL;
    rgb_indicators_config.layer_1_config.logo_led = DEFAULT_LAYER_1_LOGO_LED_VAL;
    rgb_indicators_config.layer_1_config.mode = DEFAULT_LAYER_1_MODE;
    rgb_indicators_config.layer_1_config.led = DEFAULT_LAYER_1_LED;
    rgb_indicators_config.layer_1_config.hsv = tmp_hsv[3];

    rgb_indicators_config.layer_2_config.enable = DEFAULT_LAYER_2_ENABLE_VAL;
    rgb_indicators_config.layer_2_config.all_led = DEFAULT_LAYER_2_ALL_LED_VAL;
    rgb_indicators_config.layer_2_config.key_led = DEFAULT_LAYER_2_KEY_LED_VAL;
    rgb_indicators_config.layer_2_config.underglow_led = DEFAULT_LAYER_2_UNDERGLOW_LED_VAL;
    rgb_indicators_config.layer_2_config.logo_led = DEFAULT_LAYER_2_LOGO_LED_VAL;
    rgb_indicators_config.layer_2_config.mode = DEFAULT_LAYER_2_MODE;
    rgb_indicators_config.layer_2_config.led = DEFAULT_LAYER_2_LED;
    rgb_indicators_config.layer_2_config.hsv = tmp_hsv[4];

    rgb_indicators_config.layer_3_config.enable = DEFAULT_LAYER_3_ENABLE_VAL;
    rgb_indicators_config.layer_3_config.all_led = DEFAULT_LAYER_3_ALL_LED_VAL;
    rgb_indicators_config.layer_3_config.key_led = DEFAULT_LAYER_3_KEY_LED_VAL;
    rgb_indicators_config.layer_3_config.underglow_led = DEFAULT_LAYER_3_UNDERGLOW_LED_VAL;
    rgb_indicators_config.layer_3_config.logo_led = DEFAULT_LAYER_3_LOGO_LED_VAL;
    rgb_indicators_config.layer_3_config.mode = DEFAULT_LAYER_3_MODE;
    rgb_indicators_config.layer_3_config.led = DEFAULT_LAYER_3_LED;
    rgb_indicators_config.layer_3_config.hsv = tmp_hsv[5];

    rgb_indicators_config.layer_4_config.enable = DEFAULT_LAYER_4_ENABLE_VAL;
    rgb_indicators_config.layer_4_config.all_led = DEFAULT_LAYER_4_ALL_LED_VAL;
    rgb_indicators_config.layer_4_config.key_led = DEFAULT_LAYER_4_KEY_LED_VAL;
    rgb_indicators_config.layer_4_config.underglow_led = DEFAULT_LAYER_4_UNDERGLOW_LED_VAL;
    rgb_indicators_config.layer_4_config.logo_led = DEFAULT_LAYER_4_LOGO_LED_VAL;
    rgb_indicators_config.layer_4_config.mode = DEFAULT_LAYER_4_MODE;
    rgb_indicators_config.layer_4_config.led = DEFAULT_LAYER_4_LED;
    rgb_indicators_config.layer_4_config.hsv = tmp_hsv[6];

    update_dynamic_rgb_indicators();
}

void rgb_indicators_init(void) {
    if (!eeconfig_is_enabled()) {
        eeconfig_init();
        update_dynamic_rgb_indicators_default();
    }
    eeconfig_init_dynamic_rgb_indicators();
    if (rgb_indicators_config.num_lock_config.mode == 0) {
        update_dynamic_rgb_indicators_default();
    }
    rgb_indicators_state_update();
}

void rgb_indicators_state_update(void) {
    rgb_indicators_state.num_lock = host_keyboard_led_state().num_lock;
    rgb_indicators_state.caps_lock = host_keyboard_led_state().caps_lock;
    rgb_indicators_state.scroll_lock = host_keyboard_led_state().scroll_lock;
    rgb_indicators_state.layer_1 =  layer_state_is(1);
    rgb_indicators_state.layer_2 =  layer_state_is(2); 
    rgb_indicators_state.layer_3 =  layer_state_is(3);
    rgb_indicators_state.layer_4 =  layer_state_is(4);
}

uint8_t is_rgb_indicators_enabled(void) {
    return (rgb_indicators_config.num_lock_config.enable || rgb_indicators_config.caps_lock_config.enable || rgb_indicators_config.scroll_lock_config.enable || 
            rgb_indicators_config.layer_1_config.enable || rgb_indicators_config.layer_2_config.enable || rgb_indicators_config.layer_3_config.enable || rgb_indicators_config.layer_4_config.enable);
}

uint8_t is_rgb_indicator_enabled(uint8_t indicator) {
    switch (indicator) {
        case 0: return (rgb_indicators_config.num_lock_config.enable);
        case 1: return (rgb_indicators_config.caps_lock_config.enable);
        case 2: return (rgb_indicators_config.scroll_lock_config.enable);
        case 3: return (rgb_indicators_config.layer_1_config.enable);
        case 4: return (rgb_indicators_config.layer_2_config.enable);
        case 5: return (rgb_indicators_config.layer_3_config.enable);
        case 6: return (rgb_indicators_config.layer_4_config.enable);
        default: break;
    }
    return 0;
}

uint8_t is_num_lock_enabled(void) {
    return (rgb_indicators_config.num_lock_config.enable);
}

uint8_t is_caps_lock_enabled(void) {
    return (rgb_indicators_config.caps_lock_config.enable);
}

uint8_t is_scroll_lock_enabled(void) {
    return (rgb_indicators_config.scroll_lock_config.enable);
}

uint8_t is_layer_1_enabled(void) {
    return (rgb_indicators_config.layer_1_config.enable);
}

uint8_t is_layer_2_enabled(void) {
    return (rgb_indicators_config.layer_2_config.enable);
}

uint8_t is_layer_3_enabled(void) {
    return (rgb_indicators_config.layer_3_config.enable);
}

uint8_t is_layer_4_enabled(void) {
    return (rgb_indicators_config.layer_4_config.enable);
}

static void rgb_indicator_render(uint8_t mode, uint8_t indicator) {
    switch (rgb_indicators_effect_index[mode]) {
#ifdef ENABLE_RGB_INDICATORS_BREATHING
        case 2: rgb_indicators_breathing(indicator); break;
#endif
#ifdef ENABLE_RGB_INDICATORS_CYCLEBREATHING
        case 3: rgb_indicators_cyclebreathing(indicator); break;
#endif
#ifdef ENABLE_RGB_INDICATORS_CYCLEALL
        case 4: rgb_indicators_cycleall(indicator); break;
#endif
#ifdef ENABLE_RGB_INDICATORS_RANDOM
        case 5: rgb_indicators_random(indicator); break;
#endif
#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
        case 6: rgb_indicators_random_once(indicator); break;
#endif
        default: rgb_indicators_static(indicator); break;
    }
}

static void rgb_indicators_render(void) {
    if (is_num_lock_enabled())
        rgb_indicator_render(rgb_indicators_config.num_lock_config.mode, 0);
    if (is_caps_lock_enabled())
        rgb_indicator_render(rgb_indicators_config.caps_lock_config.mode, 1);
    if (is_scroll_lock_enabled())
        rgb_indicator_render(rgb_indicators_config.scroll_lock_config.mode, 2);
    if (is_layer_1_enabled())
        rgb_indicator_render(rgb_indicators_config.layer_1_config.mode, 3);
    if (is_layer_2_enabled())
        rgb_indicator_render(rgb_indicators_config.layer_2_config.mode, 4);
    if (is_layer_3_enabled())
        rgb_indicator_render(rgb_indicators_config.layer_3_config.mode, 5);
    if (is_layer_4_enabled())
        rgb_indicator_render(rgb_indicators_config.layer_4_config.mode, 6);
}
void rgb_indicators_task(void) {
    if (is_rgb_indicators_enabled()) {
        rgb_indicators_state_update();
        rgb_indicators_render();
    }
}

void num_lock_indicator_toggle(void) {
    if (rgb_matrix_is_enabled()) {
        rgb_indicators_config.num_lock_config.enable ^= 1;
        update_dynamic_rgb_indicators();
    }
}

/*
void num_lock_indicator_mode_step(void) {
    if (rgb_matrix_is_enabled() && is_num_lock_enabled()) {
        uint8_t mod = rgb_indicators_config.num_lock_config.mode + 1;
        rgb_indicators_config.num_lock_config.mode = mod < rgb_indicators_effect_num ? mod : 1;
        update_dynamic_rgb_indicators();
    }
}

void num_lock_indicator_mode_step_reverse(void) {
    if (rgb_matrix_is_enabled() && is_num_lock_enabled()) {
        uint8_t mod = rgb_indicators_config.num_lock_config.mode - 1;
        rgb_indicators_config.num_lock_config.mode = mod < 1 ? rgb_indicators_effect_num - 1 : mod;;
        update_dynamic_rgb_indicators();
    }
}
*/

void caps_lock_indicator_toggle(void) {
    if (rgb_matrix_is_enabled()) {
        rgb_indicators_config.caps_lock_config.enable ^= 1;
        update_dynamic_rgb_indicators();
    }
}
/*
void caps_lock_indicator_mode_step(void) {
    if (rgb_matrix_is_enabled() && is_caps_lock_enabled()) {
        uint8_t mod = rgb_indicators_config.caps_lock_config.mode + 1;
        rgb_indicators_config.caps_lock_config.mode = mod < rgb_indicators_effect_num ? mod : 1;
        update_dynamic_rgb_indicators();
    }
}

void caps_lock_indicator_mode_step_reverse(void) {
    if (rgb_matrix_is_enabled() && is_caps_lock_enabled()) {
        uint8_t mod = rgb_indicators_config.caps_lock_config.mode - 1;
        rgb_indicators_config.caps_lock_config.mode = mod < 1 ? rgb_indicators_effect_num  - 1 : mod;;
        update_dynamic_rgb_indicators();
    }
}
*/

void scroll_lock_indicator_toggle(void) {
    if (rgb_matrix_is_enabled()) {
        rgb_indicators_config.scroll_lock_config.enable ^= 1;
        update_dynamic_rgb_indicators();
    }
}
/*
void scroll_lock_indicator_mode_step(void) {
    if (rgb_matrix_is_enabled() && is_scroll_lock_enabled()) {
        uint8_t mod = rgb_indicators_config.scroll_lock_config.mode + 1;
        rgb_indicators_config.scroll_lock_config.mode = mod < rgb_indicators_effect_num ? mod : 1;
        update_dynamic_rgb_indicators();
    }
}

void scroll_lock_indicator_mode_step_reverse(void) {
    if (rgb_matrix_is_enabled() && is_scroll_lock_enabled()) {
        uint8_t mod = rgb_indicators_config.scroll_lock_config.mode - 1;
        rgb_indicators_config.scroll_lock_config.mode = mod < 1 ? rgb_indicators_effect_num  - 1 : mod;
        update_dynamic_rgb_indicators();
    }
}
*/

void layer_1_indicator_toggle(void) {
    if (rgb_matrix_is_enabled()) {
        rgb_indicators_config.layer_1_config.enable ^= 1;
        update_dynamic_rgb_indicators();
    }
}

void layer_2_indicator_toggle(void) {
    if (rgb_matrix_is_enabled()) {
        rgb_indicators_config.layer_2_config.enable ^= 1;
        update_dynamic_rgb_indicators();
    }
}

void layer_3_indicator_toggle(void) {
    if (rgb_matrix_is_enabled()) {
        rgb_indicators_config.layer_3_config.enable ^= 1;
        update_dynamic_rgb_indicators();
    }
}

void layer_4_indicator_toggle(void) {
    if (rgb_matrix_is_enabled()) {
        rgb_indicators_config.layer_4_config.enable ^= 1;
        update_dynamic_rgb_indicators();
    }
}
void rgb_indicators_mode_step(void) {

    uint8_t indicator = rgb_indicators_get_indicator();

    if (rgb_matrix_is_enabled() && (indicator != 255)) {
        uint8_t mod = rgb_indicators_get_mode(indicator) + 1;
        mod = (mod < rgb_indicators_effect_num) ? mod : 1;
        rgb_indicators_set_mode(indicator, mod, true);
    }
}

void rgb_indicators_mode_step_reverse(void) {
    uint8_t indicator = rgb_indicators_get_indicator();

    if (rgb_matrix_is_enabled() && (indicator != 255)) {
        uint8_t mod = rgb_indicators_get_mode(indicator) - 1;
        mod = mod < 1 ? rgb_indicators_effect_num - 1 : mod;;
        rgb_indicators_set_mode(indicator, mod, true);
    }
}

void rgb_indicators_led_step(void) {

    uint8_t indicator = rgb_indicators_get_indicator();

    if (rgb_matrix_is_enabled() && (indicator != 255)) {
        if (rgb_indicators_get_all_led(indicator)) {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 1, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
            } 
        else if (rgb_indicators_get_key_led(indicator)) {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 1, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
            } 
        else if (rgb_indicators_get_underglow_led(indicator)) {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 1, false);
            } 
        else if (rgb_indicators_get_logo_led(indicator)) {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
            rgb_indicators_set_led(indicator, 0, false);
            } 
        else if (rgb_indicators_get_led(indicator) >= (RGB_MATRIX_LED_COUNT - 1)) {
            rgb_indicators_enable_all_led(indicator, 1, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
            } 
        else {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
            rgb_indicators_set_led(indicator, (rgb_indicators_get_led(indicator) + 1), false);
            };

        update_dynamic_rgb_indicators();
    }        
}

void rgb_indicators_led_step_reverse(void) {

    uint8_t indicator = rgb_indicators_get_indicator();

    if (rgb_matrix_is_enabled() && (indicator != 255)) {
        if (rgb_indicators_get_all_led(indicator)) {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
            rgb_indicators_set_led(indicator, (RGB_MATRIX_LED_COUNT - 1), false);
        } else if (rgb_indicators_get_key_led(indicator)) {
            rgb_indicators_enable_all_led(indicator, 1, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
        } else if (rgb_indicators_get_underglow_led(indicator)) {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 1, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
        } else if (rgb_indicators_get_logo_led(indicator)) {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 1, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
        } else if (rgb_indicators_get_led(indicator) <= 0) {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 1, false);
        } else {
            rgb_indicators_enable_all_led(indicator, 0, false);
            rgb_indicators_enable_key_led(indicator, 0, false);
            rgb_indicators_enable_underglow_led(indicator, 0, false);
            rgb_indicators_enable_logo_led(indicator, 0, false);
            rgb_indicators_set_led(indicator, (rgb_indicators_get_led(indicator) - 1), false);
        }

        update_dynamic_rgb_indicators();
    }        
}

void rgb_indicators_increase_hue(void) {

    uint8_t indicator = rgb_indicators_get_indicator();

    if (rgb_matrix_is_enabled() && (indicator != 255)) {
    rgb_indicators_set_hsv(indicator,(rgb_indicators_get_hue(indicator) + RGB_MATRIX_HUE_STEP), rgb_indicators_get_sat(indicator),rgb_indicators_get_val(indicator),true);
    }
}

void rgb_indicators_decrease_hue(void) {

    uint8_t indicator = rgb_indicators_get_indicator();
    
    if (rgb_matrix_is_enabled() && (indicator != 255)) {
    rgb_indicators_set_hsv(indicator,(rgb_indicators_get_hue(indicator) - RGB_MATRIX_HUE_STEP), rgb_indicators_get_sat(indicator),rgb_indicators_get_val(indicator), true);
    }
}

void rgb_indicators_increase_sat(void) {

    uint8_t indicator = rgb_indicators_get_indicator();
    
    if (rgb_matrix_is_enabled() && (indicator != 255)) {
    rgb_indicators_set_hsv(indicator,rgb_indicators_get_hue(indicator),(qadd8(rgb_indicators_get_sat(indicator), RGB_MATRIX_SAT_STEP)),rgb_indicators_get_val(indicator), true);
    }
}

void rgb_indicators_decrease_sat(void) {
        
    uint8_t indicator = rgb_indicators_get_indicator();
    
    if (rgb_matrix_is_enabled() && (indicator != 255)) {
    rgb_indicators_set_hsv(indicator,rgb_indicators_get_hue(indicator),(qsub8(rgb_indicators_get_sat(indicator), RGB_MATRIX_SAT_STEP)), rgb_indicators_get_val(indicator), true);
   }
}

void rgb_indicators_increase_val(void) {
        
    uint8_t indicator = rgb_indicators_get_indicator();
    
    if (rgb_matrix_is_enabled() && (indicator != 255)) {
    rgb_indicators_set_hsv(indicator, rgb_indicators_get_hue(indicator), rgb_indicators_get_sat(indicator), (qadd8(rgb_indicators_get_val(indicator), RGB_MATRIX_VAL_STEP)), true);
   }
}

void rgb_indicators_decrease_val(void) {
        
    uint8_t indicator = rgb_indicators_get_indicator();
    
    if (rgb_matrix_is_enabled() && (indicator != 255)) {
    rgb_indicators_set_hsv(indicator, rgb_indicators_get_hue(indicator), rgb_indicators_get_sat(indicator), (qsub8(rgb_indicators_get_val(indicator), RGB_MATRIX_VAL_STEP)), true);
   }
}

void rgb_indicators_enable(uint8_t indicator, bool update) {
    switch (indicator) {
        case 0: rgb_indicators_config.num_lock_config.enable = 1; break;
        case 1: rgb_indicators_config.caps_lock_config.enable = 1; break;
        case 2: rgb_indicators_config.scroll_lock_config.enable = 1; break;
        case 3: rgb_indicators_config.layer_1_config.enable = 1; break;
        case 4: rgb_indicators_config.layer_2_config.enable = 1; break;
        case 5: rgb_indicators_config.layer_3_config.enable = 1; break;
        case 6: rgb_indicators_config.layer_4_config.enable = 1; break;
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

void rgb_indicators_disable(uint8_t indicator, bool update) {
    switch (indicator) {
        case 0: rgb_indicators_config.num_lock_config.enable = 0; break;
        case 1: rgb_indicators_config.caps_lock_config.enable = 0; break;
        case 2: rgb_indicators_config.scroll_lock_config.enable = 0; break;
        case 3: rgb_indicators_config.layer_1_config.enable = 0; break;
        case 4: rgb_indicators_config.layer_2_config.enable = 0; break;
        case 5: rgb_indicators_config.layer_3_config.enable = 0; break;
        case 6: rgb_indicators_config.layer_4_config.enable = 0; break;
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

void rgb_indicators_enable_all_led(uint8_t indicator, uint8_t enable, bool update) {
    switch (indicator) {
        case 0: rgb_indicators_config.num_lock_config.all_led = enable; break;
        case 1: rgb_indicators_config.caps_lock_config.all_led = enable; break;
        case 2: rgb_indicators_config.scroll_lock_config.all_led = enable; break;
        case 3: rgb_indicators_config.layer_1_config.all_led = enable; break;
        case 4: rgb_indicators_config.layer_2_config.all_led = enable; break;
        case 5: rgb_indicators_config.layer_3_config.all_led = enable; break;
        case 6: rgb_indicators_config.layer_4_config.all_led = enable; break;
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

void rgb_indicators_enable_key_led(uint8_t indicator, uint8_t enable, bool update) {
    switch (indicator) {
        case 0: rgb_indicators_config.num_lock_config.key_led = enable; break;
        case 1: rgb_indicators_config.caps_lock_config.key_led = enable; break;
        case 2: rgb_indicators_config.scroll_lock_config.key_led = enable; break;
        case 3: rgb_indicators_config.layer_1_config.key_led = enable; break;
        case 4: rgb_indicators_config.layer_2_config.key_led = enable; break;
        case 5: rgb_indicators_config.layer_3_config.key_led = enable; break;
        case 6: rgb_indicators_config.layer_4_config.key_led = enable; break;
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

void rgb_indicators_enable_underglow_led(uint8_t indicator, uint8_t enable, bool update) {
    switch (indicator) {
        case 0: rgb_indicators_config.num_lock_config.underglow_led = enable; break;
        case 1: rgb_indicators_config.caps_lock_config.underglow_led = enable; break;
        case 2: rgb_indicators_config.scroll_lock_config.underglow_led = enable; break;
        case 3: rgb_indicators_config.layer_1_config.underglow_led = enable; break;
        case 4: rgb_indicators_config.layer_2_config.underglow_led = enable; break;
        case 5: rgb_indicators_config.layer_3_config.underglow_led = enable; break;
        case 6: rgb_indicators_config.layer_4_config.underglow_led = enable; break;
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

void rgb_indicators_enable_logo_led(uint8_t indicator, uint8_t enable, bool update) {
    switch (indicator) {
        case 0: rgb_indicators_config.num_lock_config.logo_led = enable; break;
        case 1: rgb_indicators_config.caps_lock_config.logo_led = enable; break;
        case 2: rgb_indicators_config.scroll_lock_config.logo_led = enable; break;
        case 3: rgb_indicators_config.layer_1_config.logo_led = enable; break;
        case 4: rgb_indicators_config.layer_2_config.logo_led = enable; break;
        case 5: rgb_indicators_config.layer_3_config.logo_led = enable; break;
        case 6: rgb_indicators_config.layer_4_config.logo_led = enable; break;
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

void rgb_indicators_set_mode(uint8_t indicator, uint8_t mod, bool update) {
    switch (indicator) {
        case 0: rgb_indicators_config.num_lock_config.mode = mod; break;
        case 1: rgb_indicators_config.caps_lock_config.mode = mod; break;
        case 2: rgb_indicators_config.scroll_lock_config.mode = mod; break;
        case 3: rgb_indicators_config.layer_1_config.mode = mod; break;
        case 4: rgb_indicators_config.layer_2_config.mode = mod; break;
        case 5: rgb_indicators_config.layer_3_config.mode = mod; break;
        case 6: rgb_indicators_config.layer_4_config.mode = mod; break;    
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

void rgb_indicators_set_led(uint8_t indicator, uint8_t led, bool update) {
    switch (indicator) {
        case 0: rgb_indicators_config.num_lock_config.led = led; break;
        case 1: rgb_indicators_config.caps_lock_config.led = led; break;
        case 2: rgb_indicators_config.scroll_lock_config.led = led; break;
        case 3: rgb_indicators_config.layer_1_config.led = led; break;
        case 4: rgb_indicators_config.layer_2_config.led = led; break;
        case 5: rgb_indicators_config.layer_3_config.led = led; break;
        case 6: rgb_indicators_config.layer_4_config.led = led; break;
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

void rgb_indicators_set_hsv(uint8_t indicator, uint8_t hue, uint8_t sat, uint8_t val, bool update) {
    switch (indicator) {
        case 0: {
            rgb_indicators_config.num_lock_config.hsv.h = hue;
            rgb_indicators_config.num_lock_config.hsv.s = sat;
          rgb_indicators_config.num_lock_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val; 
            break;
        }
        case 1: {
            rgb_indicators_config.caps_lock_config.hsv.h = hue;
            rgb_indicators_config.caps_lock_config.hsv.s = sat;
          rgb_indicators_config.caps_lock_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val; 
            break;
        }
        case 2: {
            rgb_indicators_config.scroll_lock_config.hsv.h = hue;
            rgb_indicators_config.scroll_lock_config.hsv.s = sat;
           rgb_indicators_config.scroll_lock_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val; 
            break;
        }
        case 3: {
            rgb_indicators_config.layer_1_config.hsv.h = hue;
            rgb_indicators_config.layer_1_config.hsv.s = sat;
            rgb_indicators_config.layer_1_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        case 4: {
            rgb_indicators_config.layer_2_config.hsv.h = hue;
            rgb_indicators_config.layer_2_config.hsv.s = sat;
            rgb_indicators_config.layer_2_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        case 5: {
            rgb_indicators_config.layer_3_config.hsv.h = hue;
            rgb_indicators_config.layer_3_config.hsv.s = sat;
            rgb_indicators_config.layer_3_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        case 6: {
            rgb_indicators_config.layer_4_config.hsv.h = hue;
            rgb_indicators_config.layer_4_config.hsv.s = sat;
            rgb_indicators_config.layer_4_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

void rgb_indicators_set_val(uint8_t indicator, uint8_t val, bool update) {
    switch (indicator) {
        case 0: {
            rgb_indicators_config.num_lock_config.hsv.v =  (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        case 1: {
            rgb_indicators_config.caps_lock_config.hsv.v =  (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        case 2: {
            rgb_indicators_config.scroll_lock_config.hsv.v =  (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        case 3: {
            rgb_indicators_config.layer_1_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        case 4: {
            rgb_indicators_config.layer_2_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        case 5: {
            rgb_indicators_config.layer_3_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        case 6: {
            rgb_indicators_config.layer_4_config.hsv.v = (val > DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS) ? DYNAMIC_RGB_INDICATORS_MAXIMUM_BRIGHTNESS : val;
            break;
        }
        default: break;
    }
    if (update)
        update_dynamic_rgb_indicators();
}

uint8_t rgb_indicators_get_indicator(void) {
    if        (is_num_lock_enabled() && !(is_caps_lock_enabled()) && !(is_scroll_lock_enabled())) {
        return 0;
    } else if (!(is_num_lock_enabled()) && (is_caps_lock_enabled()) && !(is_scroll_lock_enabled())) {
        return 1;
    } else if (!(is_num_lock_enabled()) && !(is_caps_lock_enabled()) && (is_scroll_lock_enabled())) {
        return 2;//前三项不判断层，不论在什么层，只要前三指示灯任一开启，优先调前三指示灯
    } else if ((is_layer_1_enabled()) && !(is_num_lock_enabled()) && !(is_caps_lock_enabled()) && !(is_scroll_lock_enabled())) {
        return 3;
    } else if ((is_layer_2_enabled()) && !(is_num_lock_enabled()) && !(is_caps_lock_enabled()) && !(is_scroll_lock_enabled())) {
        return 4;
    } else if ((is_layer_3_enabled()) && !(is_num_lock_enabled()) && !(is_caps_lock_enabled()) && !(is_scroll_lock_enabled())) {
        return 5;
    } else if ((is_layer_4_enabled()) && !(is_num_lock_enabled()) && !(is_caps_lock_enabled()) && !(is_scroll_lock_enabled())) {
        return 6;
    } else {
        return 255; // 无效值，表示不满足条件
    }
}

uint8_t rgb_indicators_get_multiple_led(uint8_t indicator) {
    return rgb_indicators_get_all_led(indicator) || rgb_indicators_get_key_led(indicator) ||
           rgb_indicators_get_underglow_led(indicator) || rgb_indicators_get_logo_led(indicator);
}

uint8_t rgb_indicators_get_all_led(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.all_led;
        case 1: return rgb_indicators_config.caps_lock_config.all_led;
        case 2: return rgb_indicators_config.scroll_lock_config.all_led;
        case 3: return rgb_indicators_config.layer_1_config.all_led;
        case 4: return rgb_indicators_config.layer_2_config.all_led;
        case 5: return rgb_indicators_config.layer_3_config.all_led;
        case 6: return rgb_indicators_config.layer_4_config.all_led;
        default: return 0;
    }
}

uint8_t rgb_indicators_get_key_led(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.key_led;
        case 1: return rgb_indicators_config.caps_lock_config.key_led;
        case 2: return rgb_indicators_config.scroll_lock_config.key_led;
        case 3: return rgb_indicators_config.layer_1_config.key_led;
        case 4: return rgb_indicators_config.layer_2_config.key_led;
        case 5: return rgb_indicators_config.layer_3_config.key_led;
        case 6: return rgb_indicators_config.layer_4_config.key_led;
        default: return 0;
    }
}

uint8_t rgb_indicators_get_underglow_led(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.underglow_led;
        case 1: return rgb_indicators_config.caps_lock_config.underglow_led;
        case 2: return rgb_indicators_config.scroll_lock_config.underglow_led;
        case 3: return rgb_indicators_config.layer_1_config.underglow_led;
        case 4: return rgb_indicators_config.layer_2_config.underglow_led;
        case 5: return rgb_indicators_config.layer_3_config.underglow_led;
        case 6: return rgb_indicators_config.layer_4_config.underglow_led;
        default: return 0;
    }
}

uint8_t rgb_indicators_get_logo_led(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.logo_led;
        case 1: return rgb_indicators_config.caps_lock_config.logo_led;
        case 2: return rgb_indicators_config.scroll_lock_config.logo_led;
        case 3: return rgb_indicators_config.layer_1_config.logo_led;
        case 4: return rgb_indicators_config.layer_2_config.logo_led;
        case 5: return rgb_indicators_config.layer_3_config.logo_led;
        case 6: return rgb_indicators_config.layer_4_config.logo_led;
        default: return 0;
    }
}

uint8_t rgb_indicators_get_led(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.led;
        case 1: return rgb_indicators_config.caps_lock_config.led;
        case 2: return rgb_indicators_config.scroll_lock_config.led;
        case 3: return rgb_indicators_config.layer_1_config.led;
        case 4: return rgb_indicators_config.layer_2_config.led;
        case 5: return rgb_indicators_config.layer_3_config.led;
        case 6: return rgb_indicators_config.layer_4_config.led;
        default: return 0;
    }
}

uint8_t rgb_indicators_get_mode(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.mode;
        case 1: return rgb_indicators_config.caps_lock_config.mode;
        case 2: return rgb_indicators_config.scroll_lock_config.mode;
        case 3: return rgb_indicators_config.layer_1_config.mode;
        case 4: return rgb_indicators_config.layer_2_config.mode;
        case 5: return rgb_indicators_config.layer_3_config.mode;
        case 6: return rgb_indicators_config.layer_4_config.mode;
        default: return 0;
    }
}

uint8_t rgb_indicators_get_hue(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.hsv.h;
        case 1: return rgb_indicators_config.caps_lock_config.hsv.h;
        case 2: return rgb_indicators_config.scroll_lock_config.hsv.h;
        case 3: return rgb_indicators_config.layer_1_config.hsv.h;
        case 4: return rgb_indicators_config.layer_2_config.hsv.h;
        case 5: return rgb_indicators_config.layer_3_config.hsv.h;
        case 6: return rgb_indicators_config.layer_4_config.hsv.h;
        default: return 0;
    }
}

uint8_t rgb_indicators_get_sat(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.hsv.s;
        case 1: return rgb_indicators_config.caps_lock_config.hsv.s;
        case 2: return rgb_indicators_config.scroll_lock_config.hsv.s;
        case 3: return rgb_indicators_config.layer_1_config.hsv.s;
        case 4: return rgb_indicators_config.layer_2_config.hsv.s;
        case 5: return rgb_indicators_config.layer_3_config.hsv.s;
        case 6: return rgb_indicators_config.layer_4_config.hsv.s;
        default: return 0;
    }
}

uint8_t rgb_indicators_get_val(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.hsv.v;
        case 1: return rgb_indicators_config.caps_lock_config.hsv.v;
        case 2: return rgb_indicators_config.scroll_lock_config.hsv.v;
        case 3: return rgb_indicators_config.layer_1_config.hsv.v;
        case 4: return rgb_indicators_config.layer_2_config.hsv.v;
        case 5: return rgb_indicators_config.layer_3_config.hsv.v;
        case 6: return rgb_indicators_config.layer_4_config.hsv.v;
        default: return 0;
    }
}

HSV rgb_indicators_get_hsv(uint8_t indicator) {
    switch (indicator) {
        case 0: return rgb_indicators_config.num_lock_config.hsv;
        case 1: return rgb_indicators_config.caps_lock_config.hsv;
        case 2: return rgb_indicators_config.scroll_lock_config.hsv;
        case 3: return rgb_indicators_config.layer_1_config.hsv;
        case 4: return rgb_indicators_config.layer_2_config.hsv;
        case 5: return rgb_indicators_config.layer_3_config.hsv;
        case 6: return rgb_indicators_config.layer_4_config.hsv;
        default: return rgb_indicators_config.scroll_lock_config.hsv; // Default case
    }
}

static void rgb_indicators_set_color_multiple(uint8_t indicator, RGB rgb) {
    if (rgb_indicators_get_all_led(indicator) == 1) {
        rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
    } else {
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                if (rgb_indicators_get_underglow_led(indicator) == 1) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
#ifdef LOGO_RGB_CONTROL_ENABLE
            } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
                if (rgb_indicators_get_logo_led(indicator) == 1) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
#endif
            } else {
                if (rgb_indicators_get_key_led(indicator) == 1) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
        }
    }
}

static void rgb_indicators_set_color(uint8_t indicator, HSV hsv) {
    switch (indicator) {
        case 0: {
            if (rgb_indicators_state.num_lock == 1) {
                RGB rgb = hsv_to_rgb(hsv);
                if (rgb_indicators_get_multiple_led(indicator) == 1)
                    rgb_indicators_set_color_multiple(indicator, rgb);
                else
                    rgb_matrix_set_color(rgb_indicators_config.num_lock_config.led, rgb.r, rgb.g, rgb.b);
            }
#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
            else
                changed[0] = 0;
#endif
            break;
        }
        case 1: {
            if (rgb_indicators_state.caps_lock == 1) {
                RGB rgb = hsv_to_rgb(hsv);
                if (rgb_indicators_get_multiple_led(indicator) == 1)
                    rgb_indicators_set_color_multiple(indicator, rgb);
                else
                    rgb_matrix_set_color(rgb_indicators_config.caps_lock_config.led, rgb.r, rgb.g, rgb.b);
            }
#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
            else
                changed[1] = 0;
#endif
            break;
        }
        case 2: {
            if (rgb_indicators_state.scroll_lock == 1) {
                RGB rgb = hsv_to_rgb(hsv);
                if (rgb_indicators_get_multiple_led(indicator) == 1)
                    rgb_indicators_set_color_multiple(indicator, rgb);
                else
                    rgb_matrix_set_color(rgb_indicators_config.scroll_lock_config.led, rgb.r, rgb.g, rgb.b);
            }
#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
            else
                changed[2] = 0;
#endif
            break;
        }
        case 3: {
            if (rgb_indicators_state.layer_1 == 1) {
            RGB rgb = hsv_to_rgb(hsv);
                if (rgb_indicators_get_multiple_led(indicator) == 1)
                    rgb_indicators_set_color_multiple(indicator, rgb);
                else
                    rgb_matrix_set_color(rgb_indicators_config.layer_1_config.led, rgb.r, rgb.g, rgb.b);
            }
#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
            else
                changed[3] = 0;
#endif
            break;
        }
        case 4: {
            if (rgb_indicators_state.layer_2 == 1) {
            RGB rgb = hsv_to_rgb(hsv);
                if (rgb_indicators_get_multiple_led(indicator) == 1)
                    rgb_indicators_set_color_multiple(indicator, rgb);
                else
                    rgb_matrix_set_color(rgb_indicators_config.layer_2_config.led, rgb.r, rgb.g, rgb.b);
            }
#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
            else
                changed[4] = 0;
#endif
            break;
        }
        case 5: {
            if (rgb_indicators_state.layer_3 == 1) {
            RGB rgb = hsv_to_rgb(hsv);
                if (rgb_indicators_get_multiple_led(indicator) == 1)
                    rgb_indicators_set_color_multiple(indicator, rgb);
                else
                    rgb_matrix_set_color(rgb_indicators_config.layer_3_config.led, rgb.r, rgb.g, rgb.b);
            }
#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
            else
                changed[5] = 0;
#endif
            break;
        }
        case 6: {
            if (rgb_indicators_state.layer_4 == 1) {
            RGB rgb = hsv_to_rgb(hsv);
                if (rgb_indicators_get_multiple_led(indicator) == 1)
                    rgb_indicators_set_color_multiple(indicator, rgb);
                else
                    rgb_matrix_set_color(rgb_indicators_config.layer_4_config.led, rgb.r, rgb.g, rgb.b);
            }
#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
            else
                changed[6] = 0;
#endif
            break;
        }
        default: break;
    }
}

void rgb_indicators_static(uint8_t indicator) {
    HSV hsv = rgb_indicators_get_hsv(indicator);
    rgb_indicators_set_color(indicator, hsv);
}

#ifdef ENABLE_RGB_INDICATORS_BREATHING
void rgb_indicators_breathing(uint8_t indicator) {
    HSV hsv = rgb_indicators_get_hsv(indicator);
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    rgb_indicators_set_color(indicator, hsv);
}
#endif

#ifdef ENABLE_RGB_INDICATORS_CYCLEBREATHING
static uint8_t is_breathing_highest[7] = {1};
static uint8_t is_breathing_lowest[7] = {1};
static uint8_t hue_index[7] = {0};
static uint8_t val_index[7] = {0};
static uint8_t hue_stepper[7] = {0};

void rgb_indicators_cyclebreathing(uint8_t indicator) {
    HSV hsv = rgb_indicators_get_hsv(indicator);
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    if (is_breathing_lowest[indicator]){
        val_index[indicator] = hsv.v;
        hue_index[indicator] = hue_stepper[indicator];
        hue_stepper[indicator] += 8;
        is_breathing_lowest[indicator] ^= 1;
    } else {
        if (hsv.v >= val_index[indicator] && is_breathing_highest[indicator]) {
            is_breathing_highest[indicator] ^= 1;
        } else {
            if (hsv.v <= 0 && !is_breathing_highest[indicator]) {
                is_breathing_highest[indicator] ^= 1;
                is_breathing_lowest[indicator] ^= 1;
            }
        }
    }
    hsv.h = hue_index[indicator];
    rgb_indicators_set_color(indicator, hsv);
}
#endif

#ifdef ENABLE_RGB_INDICATORS_CYCLEALL
void rgb_indicators_cycleall(uint8_t indicator) {
    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    HSV hsv = rgb_indicators_get_hsv(indicator);
    hsv.h = time;
    rgb_indicators_set_color(indicator, hsv);
}
#endif

#ifdef ENABLE_RGB_INDICATORS_RANDOM
static uint8_t timer[7] = {0};
static uint8_t hue[7] = {0};
void rgb_indicators_random(uint8_t indicator) {
    HSV hsv = rgb_indicators_get_hsv(indicator);
    if (timer[indicator] > 50) {
        srand(timer_read());
        hue[indicator] = rand() % 256;
        timer[indicator] = 0;
    } else {
        timer[indicator] ++;
    }
    hsv.h = hue[indicator];
    rgb_indicators_set_color(indicator, hsv);
}
#endif

#ifdef ENABLE_RGB_INDICATORS_RANDOM_ONCE
static uint8_t hue_once[7] = {0};
void rgb_indicators_random_once(uint8_t indicator) {
    HSV hsv = rgb_indicators_get_hsv(indicator);
    if (changed[indicator] == 0) {
        changed[indicator] = 1;
        srand(timer_read());
        hue_once[indicator] = rand() % 256;
    }
    hsv.h = hue_once[indicator];
    rgb_indicators_set_color(indicator, hsv);
}
#endif

bool process_rgb_indicators(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_IND_NUM_LOCK_TOG:
            if (record->event.pressed) {
                num_lock_indicator_toggle();
            }
            return false;         
        case RGB_IND_CAPS_LOCK_TOG:
            if (record->event.pressed) {
                caps_lock_indicator_toggle();
            }
            return false;

        case RGB_IND_SCROLL_LOCK_TOG:
            if (record->event.pressed) {
                scroll_lock_indicator_toggle();
            }
            return false;
        
        case RGB_IND_LAYER_1_TOG:
            if (record->event.pressed) {
                layer_1_indicator_toggle();  // 切换 Layer 1 指示灯状态
            }
            return false;

        case RGB_IND_LAYER_2_TOG:
            if (record->event.pressed) {
                layer_2_indicator_toggle();  // 切换 Layer 2 指示灯状态
            }
            return false;

        case RGB_IND_LAYER_3_TOG:
            if (record->event.pressed) {
                layer_3_indicator_toggle();  // 切换 Layer 3 指示灯状态
            }
            return false;

        case RGB_IND_LAYER_4_TOG:
            if (record->event.pressed) {
                layer_4_indicator_toggle();  // 切换 Layer 4 指示灯状态
            }
            return false;
        
        case RGB_INDS_MODE_F:
            if (record->event.pressed) {
                rgb_indicators_mode_step();
            }
            return false;
    
        case RGB_INDS_MODE_R:
            if (record->event.pressed) {
                rgb_indicators_mode_step_reverse();
            }
            return false;
        case RGB_INDS_LED_F:
            if (record->event.pressed) {
                rgb_indicators_led_step();
            }
            return false;
        case RGB_INDS_LED_R:
            if (record->event.pressed) {
                rgb_indicators_led_step_reverse();
            }
            return false;
        case RGB_INDS_HUE_I:
            if (record->event.pressed) {
                rgb_indicators_increase_hue();
            }
            return false;
        case RGB_INDS_HUE_D:
            if (record->event.pressed) {
                rgb_indicators_decrease_hue();
            }
            return false;
        case RGB_INDS_SAT_I:
            if (record->event.pressed) {
                rgb_indicators_increase_sat();
            }
            return false;
        case RGB_INDS_SAT_D:
            if (record->event.pressed) {
                rgb_indicators_decrease_sat();
            }
            return false;
        case RGB_INDS_VAL_I:
            if (record->event.pressed) {
                rgb_indicators_increase_val();
            }
            return false;
        case RGB_INDS_VAL_D:
            if (record->event.pressed) {
                rgb_indicators_decrease_val();
            }
            return false;
    }
    return true;
}
/*
bool process_rgb_indicators(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_IND_NUM_LOCK_TOG:
            if (record->event.pressed) {
                num_lock_indicator_toggle();
            }
            return false;
        case RGB_IND_NUM_LOCK_MF:
            if (record->event.pressed) {
                num_lock_indicator_mode_step();
            }
            return false;
        case RGB_IND_NUM_LOCK_MR:
            if (record->event.pressed) {
                num_lock_indicator_mode_step_reverse();
            }
            return false;           
        case RGB_IND_CAPS_LOCK_TOG:
            if (record->event.pressed) {
                caps_lock_indicator_toggle();
            }
            return false;
        case RGB_IND_CAPS_LOCK_MF:
            if (record->event.pressed) {
                caps_lock_indicator_mode_step();
            }
            return false;
        case RGB_IND_CAPS_LOCK_MR:
            if (record->event.pressed) {
                caps_lock_indicator_mode_step_reverse();
            }
            return false; 
        case RGB_IND_SCROLL_LOCK_TOG:
            if (record->event.pressed) {
                scroll_lock_indicator_toggle();
            }
            return false;
        case RGB_IND_SCROLL_LOCK_MF:
            if (record->event.pressed) {
                scroll_lock_indicator_mode_step();
            }
            return false;
        case RGB_IND_SCROLL_LOCK_MR:
            if (record->event.pressed) {
                scroll_lock_indicator_mode_step_reverse();
            }
            return false;
    }
    return true;
}
*/