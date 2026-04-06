#ifndef STACK_H

#define STACK_H

// Structure prototype
typedef struct Stack Stack;

// Function Prototypes
Stack* stack_create();
int push(Stack *s, void *value);
void* pop(Stack *s);
void* peek(const Stack *s);
int size(const Stack *s);
void stack_clear(Stack *s);
void stack_destroy(Stack *s);
/**
 * Checks if the stack is empty
 * @param s pointer to the stack
 * @returns 1 if the stack is empty, 0 otherwise
 */
static inline int isEmpty(const Stack *s) {return size(s) == 0;};
#endif // STACK_H
