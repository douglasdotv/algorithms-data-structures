//
// Created by Douglas on 3/30/2023.
//

#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "stack.h"
#include "hp_queue.h"

void do_queue_stack_operations(void);

int main(void) {
    return 0;
}

void do_queue_stack_operations(void) {
    Queue q;
    init_queue(&q);
    Stack s;
    init_stack(&s);

    enqueue(&q, 4);
    enqueue(&q, 7);
    push(&s, 3);
    push(&s, 2);

    while (!queue_is_empty(q)) {
        push(&s, dequeue(&q));
    }
    while (!stack_is_empty(s)) {
        enqueue(&q, pop(&s));
    }
    while (!queue_is_empty(q)) {
        printf("%d ", dequeue(&q));
    }
}

void hospital(void) {
    HospitalQueue h_queue;
    patient patient;
    init_queue_h(&h_queue);

    int option;

    char name[50];
    int priority;

    do {
        printf("Welcome to the hospital?\n");
        printf("1. Add patient\n");
        printf("2. Get next patient from priority queue\n");
        printf("3. Show list size\n");
        printf("0. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter patient name: ");
                scanf("%s", name);
                printf("Enter patient priority (1-5): ");
                scanf("%d", &priority);
                if (priority < 1 || priority > 5) {
                    printf("Please enter a number between 1 and 5.\n");
                    break;
                }

                patient.priority = priority;
                strcpy(patient.name, name);

                enqueue_h(&h_queue, patient);
                printf("%s has been added to the waiting list.\n\n", name);

                break;

            case 2:
                patient = dequeue_h(&h_queue);
                if (strcmp(patient.name, "") == 0) {
                    printf("No patients in the waiting list.\n\n");
                } else {
                    printf("Next patient for surgery:\n");
                    printf("Name: %s\n", patient.name);
                    printf("\n");
                }
                break;

            case 3:
                printf("List size: %d\n\n", h_queue.size);
                break;

            case 0:
                printf("Exiting…\n");
                break;

            default:
                printf("Invalid option. Please enter a valid option.\n");
                break;
        }
    } while (option != 0);
}