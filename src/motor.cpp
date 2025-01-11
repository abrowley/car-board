#include "motor.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "FreeRTOS.h"
#include "task.h"
#include "car-board.h"


void set_pwm(uint gpio, float freq,float duty_cycle){
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    float clock_freq = 125000000.0f;
    uint32_t divider = clock_freq / (freq * 65536);  // Compute divider for given frequency
    pwm_set_clkdiv(slice_num, divider);
    // Set the PWM wrap value (maximum count value)
    pwm_set_wrap(slice_num, 65535);  // 16-bit counter (0 - 65535)
    // Set the duty cycle
    pwm_set_gpio_level(gpio, (uint16_t)(duty_cycle * 65536));
    // Enable the PWM
    pwm_set_enabled(slice_num, true);
}

void v_motor_task(void*){
    gpio_put(MOTOR_LB_DIR_PIN, false);
    gpio_put(MOTOR_RB_DIR_PIN, true);
    gpio_put(MOTOR_LF_DIR_PIN, false);
    gpio_put(MOTOR_RF_DIR_PIN, false);

    set_pwm(MOTOR_LB_PWM_PIN,50.0f,0.5f);
    set_pwm(MOTOR_RB_PWM_PIN,50.0f,0.5f);
    set_pwm(MOTOR_LF_PWM_PIN,50.0f,0.5f);
    set_pwm(MOTOR_RF_PWM_PIN,50.0f,0.5f);

    while (true){
        vTaskDelay(DELAY);
    }
}