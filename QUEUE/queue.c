#include "queue.h"
#include <stdlib.h>

/**
 * Initializes the elements of the Queue structure
 */
void queue_init (Queue *q)
{
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
}

/**
 * Adds an element to the end of the queue
 * @exitCode {1: unsuccessful memory allocation; 0: successful exit}
 */
int enqueue (Queue *q, void *value)
{
    QueueNode *new_node = malloc(sizeof(QueueNode));
    // Memory allocation verification
    if (new_node == NULL) return 1;

    new_node->value = value;
    new_node->previous = q->last;
    if (q->first == NULL) q->first = new_node;
    if (q->last != NULL) (q->last)->next = new_node;
    q->last = new_node;
    q->size++;
    return 0;
}

/**
 * Removes the first element of the queue and returns it's pointer
 * @requires isEmpty(q) == 0
 * @warning returns NULL if the queue is empty
 */
void* dequeue (Queue *q)
{
    // Emptiness verification
    if (q->first == NULL) return NULL;
    
    QueueNode *tmp = q->first;
    void *val = tmp->value;

    q->first = tmp->next;
    
    // Verifies emptiness status
    if (q->first == NULL) q->last = NULL;
    // Only re-attributes the previous section if first is not NULL
    else (q->first)->previous = NULL;

    free(tmp);
    q->size--;
    
    return val;
}

/**
 * Verifies if the given Queue is empty
 */
int isEmpty (const Queue *q)
{
    return q->size == 0;
}

/**
 * Returns the first value of the queue
 * @requires isEmpty(q) == 0
 * @warning returns NULL if the queue is empty
 */
void* peek (const Queue *q)
{
    if (q->first == NULL) return NULL;
    return (q->first)->value;
}

/**
 * Clears the entire queue
 */
void queue_clear (Queue *q)
{
    while (!isEmpty(q))
    {
        dequeue(q);
    }
}
