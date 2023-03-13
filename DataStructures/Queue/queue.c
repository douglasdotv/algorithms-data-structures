//
// Created by Douglas on 3/30/2023.
//

#include <stdio.h>
#include "queue.h"

void init_queue(Queue *q) {
    q->rear = q->front = q->size = 0;
}

void enqueue(Queue *q, queue_info val) {
    if (queue_is_full(*q)) {
        printf("full\n");
        return;
    }
    q->items[q->rear] = val;
    q->rear = (q->rear + 1) % MAX;
    q->size++;
}

queue_info dequeue(Queue *q) {
    if (queue_is_empty(*q)) {
        printf("empty\n");
        return -1;
    }
    queue_info val = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return val;
}

queue_info peek_queue(Queue *q) {
    if (queue_is_empty(*q)) {
        printf("empty\n");
        return -1;
    }
    return q->items[q->front];
}

bool queue_is_full(Queue q) {
    return q.size == MAX;
}


bool queue_is_empty(Queue q) {
    return q.front == q.rear;
}

void print_queue(Queue *q) {
    if (queue_is_empty(*q)) {
        printf("empty\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->items[i]);
}

void queue_fura_fila(Queue *q, queue_info val) {
    if (queue_is_full(*q)) {
        printf("full\n");
        return;
    }
    q->front = (q->front - 1 + MAX) % MAX;
    q->items[q->front] = val;
    q->size++;
}

