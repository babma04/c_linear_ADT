#ifndef STACK_H

#define STACK_H

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
void stack_clear(Stack *s);
/**
 * @returns the number of elements in the stack
 * @param s pointer to the stack
 */
static inline int size (const Stack *s) {return s->size;};
/**
 * Checks if the stack is empty
 * @param s pointer to the stack
 * @returns 1 if the stack is empty, 0 otherwise
 */
static inline int isEmpty(const Stack *s) {return size(s) == 0;};
#endif // STACK_H
