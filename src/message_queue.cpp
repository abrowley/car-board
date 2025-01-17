#include <pico/cyw43_arch.h>
#include "message_queue.h"


MSG_QUEUE_T *message_queue_init() {
    auto *msg_queue = static_cast<MSG_QUEUE_T *>(calloc(1, sizeof(MSG_QUEUE_T)));
    printf("message queue initialised\n");
    if (!msg_queue) {
        printf("failed to allocate queue\n");
        return nullptr;
    }
    msg_queue->input_queue = xQueueCreate(QUEUE_SIZE,sizeof (char[MESSAGE_SIZE]));
    msg_queue->output_queue = xQueueCreate(QUEUE_SIZE,sizeof (char[MESSAGE_SIZE]));
    return msg_queue;
}