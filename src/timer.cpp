#include "hardware/timer.h"
#include "timer.h"

uint32_t timer_read() {
    return time_us_32();
}

// return the elapsed time in us between two 32-bit timestamps
// note the need to deal with rollovers
uint32_t timer_elapsed_us(uint32_t t1, uint32_t t2) {
    if (t2 > t1) return t2 - t1;
    else return UINT32_MAX - t1 + t2 + 1;
}

// return the elapsed time in use between two 32-bit timestamps
uint32_t timer_elapsed_ms(uint32_t t1, uint32_t t2) {
    return timer_elapsed_us(t1, t2) / 1000;
}