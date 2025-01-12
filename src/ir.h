//
// Created by alexr on 12/01/25.
//

#ifndef CAR_BOARD_IR_H
#define CAR_BOARD_IR_H

#include "pico/stdlib.h"
#include "hardware/pio.h"
#define IR_PIN 22

int nec_rx_init(PIO pio, uint pin);
bool nec_decode_frame(uint32_t sm, uint8_t *p_address, uint8_t *p_data);

void v_ir_task(void*);

#endif //CAR_BOARD_IR_H
