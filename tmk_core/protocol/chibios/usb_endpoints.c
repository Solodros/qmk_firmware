// Copyright 2023 Stefan Kerkmann (@KarlK90)
// SPDX-License-Identifier: GPL-3.0-or-later

#include <ch.h>
#include <hal.h>

#include "usb_main.h"
#include "usb_driver.h"
#include "usb_endpoints.h"
#include "report.h"

usb_endpoint_in_t usb_endpoints_in[USB_ENDPOINT_IN_COUNT] = {
// clang-format off
#if defined(SHARED_EP_ENABLE)
    [USB_ENDPOINT_IN_SHARED] = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_INTR, SHARED_EPSIZE, SHARED_IN_EPNUM, SHARED_IN_CAPACITY, NULL,
    QMK_USB_REPORT_STORAGE(
        &usb_shared_get_report,
        &usb_shared_set_report,
        &usb_shared_reset_report,
        &usb_shared_get_idle_rate,
        &usb_shared_set_idle_rate,
        &usb_shared_idle_timer_elapsed,
        (REPORT_ID_COUNT + 1),
#if defined(KEYBOARD_SHARED_EP)
        QMK_USB_REPORT_STROAGE_ENTRY(REPORT_ID_KEYBOARD, sizeof(report_keyboard_t)),
#endif
#if defined(MOUSE_SHARED_EP)
        QMK_USB_REPORT_STROAGE_ENTRY(REPORT_ID_MOUSE, sizeof(report_mouse_t)),
#endif
#if defined(EXTRAKEY_ENABLE)
        QMK_USB_REPORT_STROAGE_ENTRY(REPORT_ID_SYSTEM, sizeof(report_extra_t)),
        QMK_USB_REPORT_STROAGE_ENTRY(REPORT_ID_CONSUMER, sizeof(report_extra_t)),
#endif
#if defined(PROGRAMMABLE_BUTTON_ENABLE)
        QMK_USB_REPORT_STROAGE_ENTRY(REPORT_ID_PROGRAMMABLE_BUTTON, sizeof(report_programmable_button_t)),
#endif
#if defined(NKRO_ENABLE)
        QMK_USB_REPORT_STROAGE_ENTRY(REPORT_ID_NKRO, sizeof(report_nkro_t)),
#endif
#if defined(JOYSTICK_SHARED_EP)
        QMK_USB_REPORT_STROAGE_ENTRY(REPORT_ID_JOYSTICK, sizeof(report_joystick_t)),
#endif
#if defined(DIGITIZER_SHARED_EP)
        QMK_USB_REPORT_STROAGE_ENTRY(REPORT_ID_DIGITIZER, sizeof(report_digitizer_t)),
#endif
        )
    ),
#endif
// clang-format on

#if !defined(KEYBOARD_SHARED_EP)
    [USB_ENDPOINT_IN_KEYBOARD] = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_INTR, KEYBOARD_EPSIZE, KEYBOARD_IN_EPNUM, KEYBOARD_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(sizeof(report_keyboard_t))),
#endif

#if defined(MOUSE_ENABLE) && !defined(MOUSE_SHARED_EP)
    [USB_ENDPOINT_IN_MOUSE] = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_INTR, MOUSE_EPSIZE, MOUSE_IN_EPNUM, MOUSE_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(sizeof(report_mouse_t))),
#endif

#if defined(JOYSTICK_ENABLE) && !defined(JOYSTICK_SHARED_EP)
    [USB_ENDPOINT_IN_JOYSTICK] = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_INTR, JOYSTICK_EPSIZE, JOYSTICK_IN_EPNUM, JOYSTICK_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(sizeof(report_joystick_t))),
#endif

#if defined(DIGITIZER_ENABLE) && !defined(DIGITIZER_SHARED_EP)
    [USB_ENDPOINT_IN_DIGITIZER] = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_INTR, DIGITIZER_EPSIZE, DIGITIZER_IN_EPNUM, DIGITIZER_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(sizeof(report_digitizer_t))),
#endif

#if defined(CONSOLE_ENABLE)
#    if defined(USB_ENDPOINTS_ARE_REORDERABLE)
    [USB_ENDPOINT_IN_CONSOLE] = QMK_USB_ENDPOINT_IN_SHARED(USB_EP_MODE_TYPE_INTR, CONSOLE_EPSIZE, CONSOLE_IN_EPNUM, CONSOLE_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(CONSOLE_EPSIZE)),
#    else
    [USB_ENDPOINT_IN_CONSOLE]  = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_INTR, CONSOLE_EPSIZE, CONSOLE_IN_EPNUM, CONSOLE_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(CONSOLE_EPSIZE)),
#    endif
#endif

#if defined(RAW_ENABLE)
#    if defined(USB_ENDPOINTS_ARE_REORDERABLE)
    [USB_ENDPOINT_IN_RAW] = QMK_USB_ENDPOINT_IN_SHARED(USB_EP_MODE_TYPE_INTR, RAW_EPSIZE, RAW_IN_EPNUM, RAW_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(RAW_EPSIZE)),
#    else
    [USB_ENDPOINT_IN_RAW]      = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_INTR, RAW_EPSIZE, RAW_IN_EPNUM, RAW_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(RAW_EPSIZE)),
#    endif
#endif

#if defined(HIDRGB_PROTOCOL_ENABLE)
#    if defined(USB_ENDPOINTS_ARE_REORDERABLE)
    [USB_ENDPOINT_IN_HIDRGB] = QMK_USB_ENDPOINT_IN_SHARED(USB_EP_MODE_TYPE_INTR, HIDRGB_EPSIZE, HIDRGB_IN_EPNUM, HIDRGB_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(HIDRGB_EPSIZE)),
#    else
    [USB_ENDPOINT_IN_HIDRGB]      = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_INTR, HIDRGB_EPSIZE, HIDRGB_IN_EPNUM, HIDRGB_IN_CAPACITY, NULL, QMK_USB_REPORT_STORAGE_DEFAULT(HIDRGB_EPSIZE)),
#    endif
#endif

#if defined(MIDI_ENABLE)
#    if defined(USB_ENDPOINTS_ARE_REORDERABLE)
    [USB_ENDPOINT_IN_MIDI] = QMK_USB_ENDPOINT_IN_SHARED(USB_EP_MODE_TYPE_BULK, MIDI_STREAM_EPSIZE, MIDI_STREAM_IN_EPNUM, MIDI_STREAM_IN_CAPACITY, NULL, NULL),
#    else
    [USB_ENDPOINT_IN_MIDI]     = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_BULK, MIDI_STREAM_EPSIZE, MIDI_STREAM_IN_EPNUM, MIDI_STREAM_IN_CAPACITY, NULL, NULL),
#    endif
#endif

#if defined(VIRTSER_ENABLE)
#    if defined(USB_ENDPOINTS_ARE_REORDERABLE)
    [USB_ENDPOINT_IN_CDC_DATA] = QMK_USB_ENDPOINT_IN_SHARED(USB_EP_MODE_TYPE_BULK, CDC_EPSIZE, CDC_IN_EPNUM, CDC_IN_CAPACITY, virtser_usb_request_cb, NULL),
#    else
    [USB_ENDPOINT_IN_CDC_DATA] = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_BULK, CDC_EPSIZE, CDC_IN_EPNUM, CDC_IN_CAPACITY, virtser_usb_request_cb, NULL),
#    endif
    [USB_ENDPOINT_IN_CDC_SIGNALING] = QMK_USB_ENDPOINT_IN(USB_EP_MODE_TYPE_INTR, CDC_NOTIFICATION_EPSIZE, CDC_NOTIFICATION_EPNUM, CDC_SIGNALING_DUMMY_CAPACITY, NULL, NULL),
#endif
};

usb_endpoint_in_lut_t usb_endpoint_interface_lut[TOTAL_INTERFACES] = {
#if !defined(KEYBOARD_SHARED_EP)
    [KEYBOARD_INTERFACE] = USB_ENDPOINT_IN_KEYBOARD,
#endif

#if defined(RAW_ENABLE)
    [RAW_INTERFACE] = USB_ENDPOINT_IN_RAW,
#endif

#if defined(HIDRGB_PROTOCOL_ENABLE)
    [HIDRGB_INTERFACE] = USB_ENDPOINT_IN_HIDRGB,
#endif

#if defined(MOUSE_ENABLE) && !defined(MOUSE_SHARED_EP)
    [MOUSE_INTERFACE] = USB_ENDPOINT_IN_MOUSE,
#endif

#if defined(SHARED_EP_ENABLE)
    [SHARED_INTERFACE] = USB_ENDPOINT_IN_SHARED,
#endif

#if defined(CONSOLE_ENABLE)
    [CONSOLE_INTERFACE] = USB_ENDPOINT_IN_CONSOLE,
#endif

#if defined(MIDI_ENABLE)
    [AS_INTERFACE] = USB_ENDPOINT_IN_MIDI,
#endif

#if defined(VIRTSER_ENABLE)
    [CCI_INTERFACE] = USB_ENDPOINT_IN_CDC_SIGNALING,
    [CDI_INTERFACE] = USB_ENDPOINT_IN_CDC_DATA,
#endif

#if defined(JOYSTICK_ENABLE) && !defined(JOYSTICK_SHARED_EP)
    [JOYSTICK_INTERFACE] = USB_ENDPOINT_IN_JOYSTICK,
#endif

#if defined(DIGITIZER_ENABLE) && !defined(DIGITIZER_SHARED_EP)
    [DIGITIZER_INTERFACE] = USB_ENDPOINT_IN_DIGITIZER,
#endif
};

usb_endpoint_out_t usb_endpoints_out[USB_ENDPOINT_OUT_COUNT] = {
#if defined(RAW_ENABLE)
    [USB_ENDPOINT_OUT_RAW] = QMK_USB_ENDPOINT_OUT(USB_EP_MODE_TYPE_INTR, RAW_EPSIZE, RAW_OUT_EPNUM, RAW_OUT_CAPACITY),
#endif

#if defined(HIDRGB_PROTOCOL_ENABLE)
    [USB_ENDPOINT_OUT_HIDRGB] = QMK_USB_ENDPOINT_OUT(USB_EP_MODE_TYPE_INTR, HIDRGB_EPSIZE, HIDRGB_OUT_EPNUM, HIDRGB_OUT_CAPACITY),
#endif

#if defined(MIDI_ENABLE)
    [USB_ENDPOINT_OUT_MIDI] = QMK_USB_ENDPOINT_OUT(USB_EP_MODE_TYPE_BULK, MIDI_STREAM_EPSIZE, MIDI_STREAM_OUT_EPNUM, MIDI_STREAM_OUT_CAPACITY),
#endif

#if defined(VIRTSER_ENABLE)
    [USB_ENDPOINT_OUT_CDC_DATA] = QMK_USB_ENDPOINT_OUT(USB_EP_MODE_TYPE_BULK, CDC_EPSIZE, CDC_OUT_EPNUM, CDC_OUT_CAPACITY),
#endif
};
