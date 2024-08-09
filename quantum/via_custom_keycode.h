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

#pragma once

enum via_custom_keycodes {
    REV = 0x7DFF,
#ifdef AUTO_SWITCH_LAYERS_ENABLE
    WINDOWS_FN_VKEY,
    MACOS_FN_VKEY,
#endif

#ifdef RADIAL_CONTROLLER_ENABLE
    RD_BUT,
    RD_L,
    RD_R,
    RD_LC,
    RD_RC,
#endif

#ifdef RGB_MATRIX_CONTROL_ENABLE
#ifndef RGB_MATRIX_CONTROL_SWITCH_ENABLE
	UG_R_T,
	K_R_T,
#ifdef  LOGO_RGB_CONTROL_ENABLE
    L_R_T,
#endif
#else
    R_C_SW,
#endif
    IND_ON_TOG,
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
	UG_R_MS,
    UG_R_MF,
    UG_R_MR,
#ifndef UNDERGLOW_RGB_MATRIX_API_DISABLE
    UG_R_HI,
    UG_R_HD,
    UG_R_SI,
    UG_R_SD,
    UG_R_VI,
    UG_R_VD,
    UG_R_SPI,
    UG_R_SPD,
#endif
#endif
#if defined(RGB_INDICATORS_ENABLE) && !defined(DYNAMIC_RGB_INDICATORS_ENABLE)
    RGB_IND_TOG,
    RGB_IND_MF,
    RGB_IND_MR,
#endif
#if defined(RGB_INDICATORS_ENABLE) && defined(DYNAMIC_RGB_INDICATORS_ENABLE)
    NUM_TOG,
    CAPS_TOG,
    SCROLL_TOG,
    RGB_INDS_MF,
    RGB_INDS_MR,
    RGB_INDS_LF,
    RGB_INDS_LR,
    RGB_INDS_HI,
    RGB_INDS_HD,
    RGB_INDS_SI,
    RGB_INDS_SD,
    RGB_INDS_VI,
    RGB_INDS_VD,
#endif

//#ifdef VIA_CUSTOM_SETTING_KEYCODE_ENABLE
    WIN_LOCK,
    CLEAR_EEPROM,
    D3U4,
//#endif
    NEW_USER,
};

bool process_via_custom_keycode(uint16_t keycode, keyrecord_t *record);
