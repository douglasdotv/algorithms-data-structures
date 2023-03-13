//
// Created by Douglas on 3/29/2023.
//

#ifndef E_STACK_H
#define E_STACK_H

#include <stdbool.h>

#define MAX_SIZE 100

typedef int stack_info;

typedef struct {
    stack_info items[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *s);

bool is_empty(Stack *s);

bool is_full(Stack *s);

void push(Stack *s, stack_info val);

stack_info pop(Stack *s);

stack_info peek(Stack *s);

void print_stack(Stack *s);

#endif //E_STACK_H
