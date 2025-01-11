//
// Created by alexr on 11/01/25.
//
#include "car-board.h"
#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>
#include "lwip/altcp_tcp.h"

void init_wifi() {
    if (cyw43_arch_init_with_country(CYW43_COUNTRY_UK)) {
        DEBUG_printf("failed to initialise\n");
    }
    cyw43_arch_enable_sta_mode();

    int retry_count = WIFI_RETRY;
    DEBUG_printf("Connecting to WiFi : %s...\n", WIFI_SSID);
    while (
            cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000)
            && retry_count > 0
            ) {
        DEBUG_printf("failed to  connect retrying, %i of %i attempts left\n", retry_count, WIFI_RETRY);
        retry_count--;
    }
    if (retry_count > 0) {
        DEBUG_printf("Connected.\n");
    } else {
        DEBUG_printf("Connect failed after %i retry attempts\n", WIFI_RETRY);
        exit(-1);
    }
}