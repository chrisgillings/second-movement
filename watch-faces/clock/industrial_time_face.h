/* SPDX-License-Identifier: MIT */

/*
 * MIT License
 *
 * Copyright © 2021-2022 Joey Castillo <joeycastillo@utexas.edu> <jose.castillo@gmail.com>
 * Copyright © 2022 Alexsander Akers <me@a2.io>
 * Copyright © 2022 TheOnePerson <a.nebinger@web.de>
 * Copyright © 2023 Alex Utter <ooterness@gmail.com>
 * Copyright © 2024 Matheus Afonso Martins Moreira <matheus.a.m.moreira@gmail.com>
 * Copyright © 2026 Chris Gillings <git@ned-ludd.com>
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

#ifndef INDUSTRIAL_TIME_FACE_H_
#define INDUSTRIAL_TIME_FACE_H_

/*
 * INDUSTRIAL_TIME FACE
 *
 * Displays the current time as Industrial time (aka decimal time) in the format "HH:mm".
 *
 *   ref. https://www.reiner-sct.com/en/time-recording/industrial-time-definition-calculation-at-a-glance/
 *
 * The face is signified by the letters "In" in the bottom left time digits.
 * The Alarm button toggles between Local Time ("LoT"/"Lt") and UTC ("UTC"/Ut").
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
    bool utc_time;
} industrial_time_state_t;

void industrial_time_face_setup(uint8_t watch_face_index, void ** context_ptr);
void industrial_time_face_activate(void *context);
bool industrial_time_face_loop(movement_event_t event, void *context);
void industrial_time_face_resign(void *context);
movement_watch_face_advisory_t industrial_time_face_advise(void *context);

#define industrial_time_face ((const watch_face_t) { \
    industrial_time_face_setup, \
    industrial_time_face_activate, \
    industrial_time_face_loop, \
    industrial_time_face_resign, \
    industrial_time_face_advise, \
})

#endif // INDUSTRIAL_TIME_FACE_H_
