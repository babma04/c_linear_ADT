#include "deque.h"
#include <stdlib.h>

/**
 * Initializes the Deque structure
 */
void deque_init (Deque *d)
{
    d->first = NULL;
    d->last = NULL;
    d->size = 0;
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
 * Clears the entire deque
 */
void deque_clear (Deque *d)
{
    while (!isEmpty(d))
    {
        removeFirst(d);
    }
}
