#ifndef STACK_H

#define STACK_H

#include <stdint.h>
#include <stdbool.h>

// Stack structure
typedef struct StackNode {
    void *value;
    struct StackNode *next;
} StackNode;

// Main Handler of the stack
typedef struct {
    StackNode *top;
    int size;
} Stack;

// Function Prototypes
void stack_init(Stack *s);
int push(Stack *s, void *value);
void* pop(Stack *s);
void* peek(const Stack *s);
int isEmpty(const Stack *s);
void stack_clear(Stack *s);

#endif
