#include "../include/deque.h"
#include <stdlib.h>

// Deque structure
typedef struct DequeNode {
    void *value;
    struct DequeNode *next;
    struct DequeNode *previous;
} DequeNode;

struct Deque {
    DequeNode *first;
    DequeNode *last;
    int size;
};

/**
 * Initializes the Deque structure
 * @returns a pointer to the created Deque, or NULL if memory allocation fails
 * @exitCodes {NULL: unsuccessful memory allocation; pointer to Deque: successful exit}
 */
Deque* deque_create ()
{
    Deque *d = malloc(sizeof(Deque));
    // Memory allocation verification
    if (d == NULL) return NULL;

    d->first = NULL;
    d->last = NULL;
    d->size = 0;
    return d;
}


/**
 * Adds an element to the head of the deque
 * @exitCodes {-1: invalid NULL value passed as argumment; 1: unsucessful memory allocation; 0: sucessful exit}
 */ 
int addFirst (Deque *d, void *value)
{
    if (value == NULL) return -1;

    DequeNode *new_node = malloc(sizeof(DequeNode));

    // Memory allocation verification
    if (new_node == NULL) return 1;

    new_node->value = value;
    new_node->next = d->first;
    new_node->previous = NULL;
    if (!isEmpty(d)) d->first->previous = new_node;
    else d->last = new_node;
    d->first = new_node;
    d->size++;
    return 0;
}

/**
 * Adds an element to the end of the deque
 * @exitCodes {-1: invalid NULL value passed as argumment; 1: unsuccessful memory allocation; 0: sucessful exit}
 */
int addLast (Deque *d, void *value)
{
    if (value == NULL) return -1;

    DequeNode *new_node = malloc(sizeof(DequeNode));

    if (new_node == NULL) return 1;

    new_node->value = value;
    new_node->previous = d->last;
    new_node->next = NULL;
    if (!isEmpty(d)) d->last->next = new_node;
    else d->first = new_node;
    d->last = new_node;
    d->size++;
    return 0;
}

/**
 * Removes the first element on the deque and returns its value
 * @requires isEmpty(d) == 0 
 * @warning returns NULL if the deque is empty
 */
void* removeFirst (Deque *d) 
{
    if (isEmpty(d)) return NULL;

    DequeNode *tmp = d->first;
    void *val = tmp->value;
    d->first = tmp->next;
    d->size--;

    if (d->first != NULL) d->first->previous = NULL;
    else d->last = NULL;
    
    free(tmp);
    return val;
}

/**
 * Removes the last element on the deque and returns its value
 * @requires isEmtpy(d) == 0
 * @warning returns NULL if the deque is empty
 */
void* removeLast (Deque *d)
{
    if (isEmpty(d)) return NULL;

    DequeNode * tmp = d->last;
    void *val = tmp->value;
    d->last = tmp->previous;
    d->size--;

    if (d->last != NULL) d->last->next = NULL;
    else d->first = NULL;

    free(tmp);    
    return val;
}

/**
 * Returns the first value on the deque
 * @requires isEmpty (d) == 0
 * @warning returns NULL if the deque is empty
 */
void* peekFirst (const Deque *d)
{
    // Safety check for an empty deque
    if (isEmpty(d)) return NULL;
    return d->first->value;
}

/**
 * Returns the last value on the deque
 * @requires isEmtpy (d) == 0
 * @warning returns NULL if the deque is empty
 */
void* peekLast (const Deque *d)
{
    // Safety check for an empty deque
    if (isEmpty(d)) return NULL;
    return d->last->value;
}

/**
 * @returns the number of elements in the deque
 * @param d the deque to check
 */
int size (const Deque *d) {return d->size;};

/**
 * Clears the entire deque
 */
void deque_clear (Deque *d)
{
    while (!isEmpty(d))
    {
        removeFirst(d);
    }
}

/**
 * Destroys the deque and frees all associated memory
 * @param d the deque to destroy
 * @warning This function should be called when the deque is no longer needed to prevent memory leaks. It frees all nodes and the Deque structure itself.
 */
void deque_destroy (Deque *d)
{
    // Safety check for NULL pointer
    if (d == NULL) return;
    deque_clear(d);
    free(d); // Free the Deque structure itself
}
