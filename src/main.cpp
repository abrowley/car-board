#include "FreeRTOS.h"
#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>
#include "task.h"
#include "car-board-version.h"
#include "car-board.h"
#include "wifi.h"



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
    sleep_ms(10000);
    stdio_init_all();
    //init_wifi();

    xTaskCreate(v_blink_task,"LED",256, nullptr,1, nullptr);

    vTaskStartScheduler();
    return 0;
}