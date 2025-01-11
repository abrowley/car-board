//
// Created by alexr on 11/01/25.
//

#ifndef CAR_BOARD_WS2812_H
#define CAR_BOARD_WS2812_H

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

#define WS2812_PIN 11

#define IS_RGBW false
#define NUM_PIXELS 150

static inline void put_pixel(PIO pio, uint sm, uint32_t pixel_grb);
static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b);
static inline uint32_t urgbw_u32(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
void pattern_snakes(PIO pio, uint sm, uint len, uint t);
void pattern_random(PIO pio, uint sm, uint len, uint t);
void pattern_sparkle(PIO pio, uint sm, uint len, uint t);
void pattern_greys(PIO pio, uint sm, uint len, uint t);

typedef void (*pattern)(PIO pio, uint sm, uint len, uint t);
const struct {
    pattern pat;
    const char *name;
} pattern_table[] = {
        {pattern_snakes,  "Snakes!"},
        {pattern_random,  "Random data"},
        {pattern_sparkle, "Sparkles"},
        {pattern_greys,   "Greys"},
};

void v_ws2812_task(void*);

#endif //CAR_BOARD_WS2812_H
