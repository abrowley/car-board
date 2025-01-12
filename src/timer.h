#ifndef CAR_BOARD_TIMER_H
#define CAR_BOARD_TIMER_H

#include "pico/stdlib.h"
#include "hardware/timer.h"

uint32_t timer_read();

uint32_t timer_elapsed_us(uint32_t t1, uint32_t t2);

uint32_t timer_elapsed_ms(uint32_t t1, uint32_t t2);

#endif //CAR_BOARD_TIMER_H
