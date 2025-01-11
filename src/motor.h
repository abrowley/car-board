#ifndef CAR_BOARD_MOTOR_H
#define CAR_BOARD_MOTOR_H

#define MOTOR_LF_PWM_PIN 12
#define MOTOR_LF_DIR_PIN 13

#define MOTOR_RF_PWM_PIN 15
#define MOTOR_RF_DIR_PIN 14

#define MOTOR_RB_PWM_PIN 16
#define MOTOR_RB_DIR_PIN 17

#define MOTOR_LB_PWM_PIN 19
#define MOTOR_LB_DIR_PIN 18

#define MOTOR_PWM_FREQ 500

void init_motors(void);
void v_motor_task(void*);

#endif //CAR_BOARD_MOTOR_H
