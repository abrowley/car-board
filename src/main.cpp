#include "FreeRTOS.h"
#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>
#include "task.h"
#include "car-board.h"
#include "wifi.h"
#include "lcd.h"
#include "servo.h"
#include "ws2812.h"
#include "motor.h"
#include "ultrasonic.h"
#include "ir.h"

void v_blink_task(void*){
    init_wifi();
    for(;;){
        cyw43_arch_gpio_put(LED_PIN, true);
        vTaskDelay(DELAY);
        cyw43_arch_gpio_put(LED_PIN, false);
        vTaskDelay(DELAY);
    }
}



int main(){

    stdio_init_all();
    //init_wifi();
    printf("hello car-board\n");

    sleep_ms(10000);
    xTaskCreate(v_blink_task,"LED",256, nullptr,10, nullptr);

    //xTaskCreate(v_lcd_task,"LCD",128, nullptr,4, nullptr);
    //xTaskCreate(v_servo_task,"SERVO",128, nullptr,4, nullptr);
    //xTaskCreate(v_ws2812_task,"WS2812",128, nullptr,4, nullptr);
    //xTaskCreate(v_motor_task,"MOTOR",128, nullptr,4, nullptr);
    //xTaskCreate(v_ultrasonic_task,"DST",256, nullptr,1, nullptr);
    xTaskCreate(v_ir_task,"IR",256, nullptr,1, nullptr);

    vTaskStartScheduler();
    return 0;
}