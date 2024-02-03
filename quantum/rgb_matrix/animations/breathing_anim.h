#ifdef ENABLE_RGB_MATRIX_BREATHING
RGB_MATRIX_EFFECT(BREATHING)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool BREATHING(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV      hsv  = rgb_matrix_config.hsv;
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);

#ifndef LED_CENTER   
    RGB rgb       = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

#else 
    RGB rgb1 = rgb_matrix_hsv_to_rgb(hsv);
    hsv.h += rgb_matrix_config.speed;
    RGB rgb2 = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < LED_CENTER; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
    };
    for (uint8_t i = LED_CENTER; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
       
    }
    
#endif
    return rgb_matrix_check_finished_leds(led_max);

}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // ENABLE_RGB_MATRIX_BREATHING
