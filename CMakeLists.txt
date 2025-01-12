cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(project_name car_board)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)
include(lib/pico-sdk/pico_sdk_init.cmake)
include(lib/FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(${project_name} C CXX ASM)
pico_sdk_init()

execute_process(COMMAND git describe --tags --always OUTPUT_STRIP_TRAILING_WHITESPACE
        OUTPUT_VARIABLE GIT_REPO_VERSION)
configure_file("src/car-board-version.h.in" "car-board-version.h")

add_executable(
        ${project_name}
        src/main.cpp
        src/wifi.cpp
        src/servo.cpp
        src/lcd.cpp
        src/ws2812.cpp
        src/motor.cpp
        src/ultrasonic.cpp
        src/timer.cpp
        src/ir.cpp
)

pico_generate_pio_header(${project_name} ${CMAKE_CURRENT_LIST_DIR}/src/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)
pico_generate_pio_header(${project_name} ${CMAKE_CURRENT_LIST_DIR}/src/ir_receive.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_include_directories(${project_name} PRIVATE port/FreeRTOS-Kernel)
target_include_directories(${project_name} PRIVATE port/lwip)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/pico-libfixmath)
target_include_directories(${PROJECT_NAME} PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR}/lib/pico-libfixmath/include)

target_include_directories (${project_name} PRIVATE ${CMAKE_BINARY_DIR})

if((DEFINED WIFI_SSID) AND (DEFINED WIFI_PASSWORD))
    target_compile_definitions(${project_name} PRIVATE
            WIFI_SSID=\"${WIFI_SSID}\"
            WIFI_PASSWORD=\"${WIFI_PASSWORD}\"
    )
else()
    message(FATAL_ERROR
            "WIFI Credentials not defined. Add -DWIFI_SSID=<YOUR_SSID> and -DWIFI_PASSWORD=<YOUR_PASSWORD> to CMAKE Args")
endif ()

target_link_libraries(${project_name}
        pico_stdlib
        pico_cyw43_arch_lwip_sys_freertos
        pico_lwip_mqtt
        FreeRTOS-Kernel-Heap4
        hardware_i2c
        hardware_adc
        hardware_pwm
        fixmath
)

pico_enable_stdio_uart(${project_name} 0)
pico_enable_stdio_usb(${project_name} 1)
pico_add_extra_outputs(${project_name})