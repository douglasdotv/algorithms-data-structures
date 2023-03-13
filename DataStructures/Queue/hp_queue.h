//
// Created by Douglas on 3/30/2023.
//

#ifndef E_HOSPITAL_QUEUE_H
#define E_HOSPITAL_QUEUE_H

#include <stdbool.h>

#define MAX 10

typedef int priority;

typedef struct {
    char name[50];
    priority priority;
} patient;

typedef struct {
    patient items[MAX];
    int rear, front, size;
} HospitalQueue;

void init_queue_h(HospitalQueue *q);

void enqueue_h(HospitalQueue *q, patient p);

patient dequeue_h(HospitalQueue *q);

patient peek_queue_h(HospitalQueue *q);

bool queue_is_full_h(HospitalQueue q);

bool queue_is_empty_h(HospitalQueue q);

void print_queue_h(HospitalQueue *q);

#endif //E_HOSPITAL_QUEUE_H
