//
// Created by alexr on 12/01/25.
//

#ifndef CAR_BOARD_MESSAGE_QUEUE_H
#define CAR_BOARD_MESSAGE_QUEUE_H

#include "FreeRTOS.h"
#include "queue.h"

#define MESSAGE_SIZE 100
#define QUEUE_SIZE 10

typedef struct MSG_QUEUE_T_ {
    QueueHandle_t input_queue;
    QueueHandle_t output_queue;
} MSG_QUEUE_T;

MSG_QUEUE_T* message_queue_init();

#endif //CAR_BOARD_MESSAGE_QUEUE_H
