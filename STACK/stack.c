#include "stack.h"
#include <stdlib.h>

/**
 * Initializes the elements of the Stack structure
 */
void stack_init (Stack *s)
{
    s->top = NULL;
    s->size = 0;
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
 * Clears the entire stack
 */ 
void stack_clear (Stack *s)
{   
    while (!isEmpty(s))
    {
        pop(s);
    }
}

