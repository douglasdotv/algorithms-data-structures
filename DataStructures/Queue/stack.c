//
// Created by Douglas on 3/29/2023.
//

#include <stdio.h>
#include "stack.h"

void init_stack(Stack *s) {
    s->top = -1;
}

bool stack_is_empty(Stack s) {
    return s.top == -1;
}

bool stack_is_full(Stack s) {
    return s.top == MAX_SIZE - 1;
}

void push(Stack *s, stack_info val) {
    if (stack_is_full(*s)) {
        printf("stack overflow\n");
        return;
    }
    s->items[++s->top] = val;
}

stack_info pop(Stack *s) {
    if (stack_is_empty(*s)) {
        printf("stack underflow\n");
        return -1;
    }
    stack_info val = s->items[s->top--];
    return val;
}

stack_info peek_stack(Stack *s) {
    if (stack_is_empty(*s)) {
        printf("the stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

void print_stack(Stack *stack) {
    if (stack_is_empty(*stack)) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d", stack->items[i]);
            if (i < stack->top) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}
