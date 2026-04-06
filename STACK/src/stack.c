#include "../include/stack.h"
#include <stdlib.h>

// Stack structure
typedef struct StackNode {
    void *value;
    struct StackNode *next;
} StackNode;

// Main Handler of the stack
struct Stack {
    StackNode *top;
    int size;
};


/**
 * Initializes the stack 
 * @param s pointer to the stack
 * @returns pointer to the initialized stack, or NULL if memory allocation fails
 * @errorCodes {NULL: memory allocation failure; valid pointer: successful initialization}
 */
Stack* stack_create() {
    Stack *s = malloc(sizeof(Stack));
    // Memory allocation safety fallback
    if (s == NULL) return NULL;

    s->top = NULL;
    s->size = 0;
    return s;
}

/**
 * Pushes an element to the top of the stack
 * @exitCodes {-1: invalid NULL value passed as argumment; 1: unsucessful memory allocation; 0: sucessful exit}
 */
int push (Stack *s, void *value)
{
    if (value == NULL) return -1;

    StackNode *new_node = malloc(sizeof(StackNode));

    // Memory allocation safety fallback
    if (new_node == NULL) return 1;

    new_node->value = value;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
    return 0;
}

/**
 * Removes the top element from the stack
 * @requires isEmpty(s) == 0 
 * @warning returns NULL if the stack is empty
*/
void* pop (Stack *s)
{
    // Emptiness verification
    if (s->top == NULL) return NULL;

    StackNode *tmp = s->top;
    void *val = tmp->value;

    s->top = tmp->next;
    free(tmp);
    s->size--;

    return val;
}

/**
 * @returns the top value in the stack
 * @requires isEmpty(s) == 0
 * @warning returns NULL if the stack is empty
 */
void* peek (const Stack *s)
{
    // Safety check for an empty stack
    if (s->top == NULL) return NULL;
    return s->top->value;
}

/**
 * @returns the number of elements in the stack
 * @param s pointer to the stack
 */
int size(const Stack *s) {return s->size;};

/**
 * Clears the entire stack
 */ 
void stack_clear (Stack *s)
{   
    while (!isEmpty(s))
    {
        pop(s);
    }
}

/**
 * Destroys the stack and frees all associated memory
 * @warning stack_clear(s) should be called before this function to avoid memory leaks
 */
void stack_destroy (Stack *s)
{
    // Safety check for NULL pointer
    if (s == NULL) return;
    // Safety check for already empty stack
    stack_clear(s); 
    free(s); 
}

//----------------------------------- Stack Iterator -------------------------------------

// Iterator structure
struct StackIterator {
    Stack *stack;
    StackNode *current;
};

/**
 * Creates an iterator for the given stack
 * @param s pointer to the stack
 * @returns pointer to the created iterator, or NULL if memory allocation fails
 * @errorCodes {NULL: memory allocation failure; valid pointer: successful creation}
 */
StackIterator* stack_iterator_create(const Stack *s) 
{
    StackIterator *it = malloc(sizeof(StackIterator));
    if (it == NULL) return NULL;

    it->stack = (Stack *)s; // Cast away const-ness for internal use
    it->current = s->top;
    return it;
}

/**
 * Checks if there are more elements to iterate over
 * @param it pointer to the stack iterator
 * @returns 1 if there are more elements, 0 otherwise
 */
int stack_iterator_has_next(const StackIterator *it) 
{
    return (it != NULL && it->current != NULL);
}

/**
 * Returns the next element in the iteration
 * @param it pointer to the stack iterator
 * @returns pointer to the next element, or NULL if there are no more elements
 */
void* stack_iterator_next(StackIterator *it)
{
    if (it == NULL || it->current == NULL) return NULL;

    void *value = it->current->value;
    it->current = it->current->next;
    return value;
}

/**
 * Destroys the stack iterator and frees all associated memory
 * @param it pointer to the stack iterator
 */void stack_iterator_destroy(StackIterator *it) 
{
    if (it == NULL) return;
    free(it);
}