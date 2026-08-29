/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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

#ifndef TWILIGHT_FACE_H_
#define TWILIGHT_FACE_H_

/*
 * TWILIGHT AND DAWN FACE
 *
 * The Twilight face is designed to display the next eight twilight moments
 * for a given location, in order from the current time.  From midnight, for instance:
 *
 *   Astronomical Dawn, Nautical Dawn, Civil Dawn and Sunrise
 *   Astronomical Twilight, Nautical Twilight, Civil Twilight and Sunset
 *
 * It also functions as an interface for setting the
 * location register, which other watch faces can use for various purposes.
 *
 * Refer to the wiki for usage instructions (once it is written):
 *  https://www.sensorwatch.net/docs/watchfaces/complication/#twilights
 */

#include "movement.h"

typedef struct {
    uint8_t sign: 1;    // 0-1
    uint8_t hundreds: 5;    // 0-1, ignored for latitude
    uint8_t tens: 5;        // 0-18 (wraps at 10 on clasic LCD, 18 on custom LCD)
    uint8_t ones: 4;        // 0-9 (must wrap at 10)
    uint8_t tenths: 4;      // 0-9 (must wrap at 10)
    uint8_t hundredths: 4;  // 0-9 (must wrap at 10)
} twilight_lat_lon_settings_t;

typedef struct {
    uint8_t page;
    uint8_t rise_index;
    uint8_t active_digit;
    bool location_changed;
    watch_date_time_t rise_set_expires;
    twilight_lat_lon_settings_t working_latitude;
    twilight_lat_lon_settings_t working_longitude;
    uint8_t longLatToUse;
} twilight_state_t;

typedef struct {
    double time;
    char custom_text[3];
    char default_text[2];
} twilight_moment_t;

void twilight_face_setup(uint8_t watch_face_index, void ** context_ptr);
void twilight_face_activate(void *context);
bool twilight_face_loop(movement_event_t event, void *context);
void twilight_face_resign(void *context);

#define twilight_face ((const watch_face_t){ \
    twilight_face_setup, \
    twilight_face_activate, \
    twilight_face_loop, \
    twilight_face_resign, \
    NULL, \
})

#endif // TWILIGHT_FACE_H_
