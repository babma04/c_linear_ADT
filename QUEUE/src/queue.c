#include "../include/queue.h"
#include <stdlib.h>

// Queue structure
typedef struct QueueNode {
    void *value;
    struct QueueNode *next;
    struct QueueNode *previous;
} QueueNode;

// Main handler of the queue
struct Queue {
    QueueNode *first;
    // Optional (might not be available)
    QueueNode *last;
    int size;
};

/**
 * Initializes the queue
 * @exitCode {1: unsuccessful memory allocation; 0: successful exit}
 * @warning This function must be called before any other operation on the queue
 */
Queue* queue_create()
{
    Queue *q = malloc(sizeof(Queue));
    // Memory allocation verification
    if (q == NULL) return NULL;

    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    return q;
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
 * @returns the size of the queue.
 * @param q The queue to be checked.
 */
int size (const Queue *q) {return q->size;};

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

/**
 * Destroys the queue and frees all allocated memory
 * @param q The queue to be destroyed
 * @warning After calling this function, the queue pointer should not be used anymore
 */
void queue_destroy (Queue *q)
{
    // Null pointer verification
    if (q == NULL) return;
    // Clear the queue and free the memory allocated for the queue structure
    queue_clear(q);
    free(q);
}