/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Lucian Copeland for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_ESPRESSIF_COMMON_HAL_PWMIO_PWMOUT_H
#define MICROPY_INCLUDED_ESPRESSIF_COMMON_HAL_PWMIO_PWMOUT_H

#include "common-hal/microcontroller/Pin.h"
#include "components/driver/ledc/include/driver/ledc.h"

typedef struct {
    mp_obj_base_t base;
    ledc_timer_config_t tim_handle;
    ledc_channel_config_t chan_handle;
    const mcu_pin_obj_t *pin;
    uint8_t duty_resolution;
    bool variable_frequency : 1;
    bool deinited : 1;
} pwmio_pwmout_obj_t;

void pwmout_reset(void);

#endif // MICROPY_INCLUDED_ESPRESSIF_COMMON_HAL_PWMIO_PWMOUT_H
