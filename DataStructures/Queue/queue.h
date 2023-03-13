//
// Created by Douglas on 3/30/2023.
//

#ifndef E_QUEUE_H
#define E_QUEUE_H

#include <stdbool.h>

#define MAX 10

typedef int queue_info;

typedef struct {
    queue_info items[MAX];
    int rear, front, size;
} Queue;

void init_queue(Queue *q);

void enqueue(Queue *q, queue_info val);

queue_info dequeue(Queue *q);

queue_info peek_queue(Queue *q);

bool queue_is_full(Queue q);

bool queue_is_empty(Queue q);

void print_queue(Queue *q);

void queue_fura_fila(Queue *q, queue_info val);

#endif //E_QUEUE_H
