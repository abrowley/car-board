//
// Created by alexr on 11/01/25.
//

#ifndef CAR_BOARD_SERVO_H
#define CAR_BOARD_SERVO_H

#include "pico/stdlib.h"

#define SERVO_PIN 10
#define SERVO_MAX_ANGLE 25

void servo_set_bounds(uint, uint);

int servo_init(void);
int servo_clock_auto(void);
int servo_clock_source(uint);
int servo_clock_manual(uint);
int servo_attach(uint);
int servo_enable(void);
int servo_move_to(uint, uint);
int servo_microseconds(uint, uint);
void v_servo_task(void*);


#endif //CAR_BOARD_SERVO_H
