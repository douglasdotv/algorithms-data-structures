//
// Created by Douglas on 3/29/2023.
//

#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "list.h"

void print_remaining_chars(void);

void infix_to_postfix(const char *infix, char *postfix);

bool is_operator(char c);

bool is_digit(char c);

int get_precedence(char op);

void reverse_list_with_stack(List *l);

void transfer(Stack *s1, Stack *s2);

bool is_palindrome(const char *str);

void print_decreasing(List *l);

int main(void) {
    return 0;
}

void print_remaining_chars(void) {
    Stack s;
    init_stack(&s);
    const char* exp = "LA*STI*N*FIR*ST**OU*T******";

    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '*') {
            pop(&s);
        } else {
            push(&s, exp[i]);
        }
    }

    while (s.top != -1) {
        printf("%c", pop(&s));
    }
}

void infix_to_postfix(const char *infix, char *postfix) {
    Stack s;
    init_stack(&s);

    int postfix_index = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        // Makes the code more readable
        char c = infix[i];

        if (is_digit(c)) {
            // Operand, add to output string
            postfix[postfix_index++] = c;
        } else if (c == '(') {
            // Left parenthesis, push onto s
            push((&s), c);
        } else if (c == ')') {
            // Right parenthesis, pop operators from s and add to output string
            while (!is_empty((&s)) && peek((&s)) != '(') {
                postfix[postfix_index++] = pop((&s));
            }
            pop((&s)); // Discard left parenthesis
        } else if (is_operator(c)) {
            // Operator, pop operators with higher or equal get_precedence from s and add to output string
            while (!is_empty((&s)) && peek((&s)) != '(' && get_precedence(peek((&s))) >= get_precedence(c)) {
                postfix[postfix_index++] = pop((&s));
            }
            push((&s), c);
        }
    }

    // Pop remaining operators from s and add to output string
    while (!is_empty((&s))) {
        postfix[postfix_index++] = pop((&s));
    }

    postfix[postfix_index] = '\0'; // Null-terminate output string
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int get_precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void reverse_list_with_stack(List *l) {
    Stack stack;
    init_stack(&stack);

    for (int i = 0; i < l->n; i++) {
        push(&stack, l->items[i]);
    }

    for (int i = 0; i < l->n; i++) {
        l->items[i] = pop(&stack);
    }
}

void transfer(Stack *s1, Stack *s2) {
    Stack s_temp;
    init_stack(&s_temp);

    while (!is_empty(s1)) {
        stack_info temp = pop(s1);
        while (!is_empty(&s_temp) && peek(&s_temp) > temp) {
            push(s1, pop(&s_temp));
        }
        push(&s_temp, temp);
    }

    while (!is_empty(&s_temp)) {
        push(s2, pop(&s_temp));
    }
}

bool is_palindrome(const char *word) {
    Stack stack;
    init_stack(&stack);

    unsigned long long word_length = strlen(word);

    for (int i = 0; i < word_length; i++) {
        push(&stack, word[i]);
    }

    for (int i = 0; i < word_length; i++) {
        if (word[i] != pop(&stack)) {
            return false;
        }
    }

    return true;
}

void print_decreasing(List *l) {
    Stack stack1, stack2;
    init_stack(&stack1);
    init_stack(&stack2);

    for (int i = 0; i < l->n; i++) {
        push(&stack1, l->items[i]);
    }

    while (!is_empty(&stack1)) {
        // char or int??
        char temp = pop(&stack1);
        while (!is_empty(&stack2) && peek(&stack2) < temp) {
            push(&stack1, pop(&stack2));
        }
        push(&stack2, temp);
    }

    print_stack(&stack2);
}
