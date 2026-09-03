/* SPDX-License-Identifier: MIT */

/*
 * MIT License
 *
 * Copyright © 2021-2022 Joey Castillo <joeycastillo@utexas.edu> <jose.castillo@gmail.com>
 * Copyright © 2022 Alexsander Akers <me@a2.io>
 * Copyright © 2022 TheOnePerson <a.nebinger@web.de>
 * Copyright © 2023 Alex Utter <ooterness@gmail.com>
 * Copyright © 2024 Matheus Afonso Martins Moreira <matheus.a.m.moreira@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SUN_TRANSITS_FACE_H_
#define SUN_TRANSITS_FACE_H_

/*
 * SUN_TRANSITS FACE
 *
 * Displays the upcoming sun transits that define
 * the seasonal Solstices, Equinoxes and Cross-Quarter days
 * adjusted for hemisphere and local timezone.
 *
 * At activation, the next upcoming transit name and date is shown.
 * The Alarm button steps forward and the Light button steps back.
 *
 */

#include "movement.h"

typedef struct {
    struct {
        watch_date_time_t previous;
    } date_time;
    uint8_t last_battery_check;
    uint8_t watch_face_index;
    bool time_signal_enabled;
    bool battery_low;
} sun_transits_state_t;

void sun_transits_face_setup(uint8_t watch_face_index, void ** context_ptr);
void sun_transits_face_activate(void *context);
bool sun_transits_face_loop(movement_event_t event, void *context);
void sun_transits_face_resign(void *context);
movement_watch_face_advisory_t sun_transits_face_advise(void *context);

#define sun_transits_face ((const watch_face_t) { \
    sun_transits_face_setup, \
    sun_transits_face_activate, \
    sun_transits_face_loop, \
    sun_transits_face_resign, \
    sun_transits_face_advise, \
})

#endif // SUN_TRANSITS_FACE_H_
