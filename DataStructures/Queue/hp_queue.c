//
// Created by Douglas on 3/30/2023.
//

#include <stdio.h>
#include "hp_queue.h"

void init_queue_h(HospitalQueue *q) {
    q->rear = q->front = q->size = 0;
}

void enqueue_h(HospitalQueue *q, patient p) {
    if (queue_is_full_h(*q)) {
        printf("full\n");
        return;
    }
    q->items[q->rear] = p;
    q->rear = (q->rear + 1) % MAX;
    q->size++;
}

patient dequeue_h(HospitalQueue *q) {
    if (queue_is_empty_h(*q)) {
        printf("empty\n");
        patient empty_patient = {"", 0};
        return empty_patient;
    }

    int highest_priority_index = q->front;
    int i = (q->front + 1) % MAX;
    while (i != q->rear) {
        if (q->items[i].priority > q->items[highest_priority_index].priority) {
            highest_priority_index = i;
        }
        i = (i + 1) % MAX;
    }

    patient highest_priority_patient = q->items[highest_priority_index];
    q->size--;

    // shift
    i = highest_priority_index;
    while (i != q->rear) {
        q->items[i] = q->items[(i + 1) % MAX];
        i = (i + 1) % MAX;
    }
    q->rear = (q->rear - 1 + MAX) % MAX;

    return highest_priority_patient;
}

patient peek_queue_h(HospitalQueue *q) {
    if (queue_is_empty_h(*q)) {
        printf("empty\n");
        patient empty_patient = {"", 0};
        return empty_patient;
    }

    patient highest_priority_patient = q->items[q->front];

    int i = q->front;
    while (i != q->rear) {
        if (q->items[i].priority > highest_priority_patient.priority) {
            highest_priority_patient = q->items[i];
        }
        i = (i + 1) % MAX;
    }

    return highest_priority_patient;
}

bool queue_is_full_h(HospitalQueue q) {
    return q.size == MAX;
}

bool queue_is_empty_h(HospitalQueue q) {
    return q.front == q.rear;
}

void print_queue_h(HospitalQueue *q) {
    if (queue_is_empty_h(*q)) {
        printf("empty\n");
        return;
    }
    printf("queue:\n");
    int i = q->front;
    while (i != q->rear) {
        printf("%s, priority %d\n", q->items[i].name, q->items[i].priority);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
