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

//------------------------------------ Queue Iterator ------------------------------------

// Iterator structure
struct QueueIterator {
    const Queue *queue;
    QueueNode *current;
};

/**
 * Creates an iterator for the given queue
 * @param q The queue to be iterated over
 * @returns A pointer to the created iterator, or NULL if memory allocation fails
 * @warning The iterator should be destroyed using queue_iterator_destroy to free allocated memory
 * @exitCode {1: unsuccessful memory allocation; 0: successful exit}
 */
QueueIterator* queue_iterator_create (const Queue *q)
{
    QueueIterator *it = malloc(sizeof(QueueIterator));
    if (it == NULL) return NULL;
    
    it->queue = q;
    it->current = q->first;
    return it;
}

/**
 * Checks if the iterator has more elements to iterate over
 * @param it The iterator to be checked
 * @returns 1 if there are more elements, 0 otherwise
 */
int queue_iterator_has_next (const QueueIterator *it)
{
    return (it != NULL && it->current != NULL);
}

/**
 * Returns the next element in the iteration and advances the iterator
 * @param it The iterator to be advanced
 * @returns A pointer to the next element, or NULL if there are no more elements
 * @warning The caller is responsible for ensuring that the iterator is valid and has more elements before calling this function
 */
void* queue_iterator_next (QueueIterator *it)
{
    if (it == NULL || it->current == NULL) return NULL; 
    
    void *value = it->current->value;
    it->current = it->current->next;
    return value;
}

/**
 * Destroys the iterator and frees allocated memory
 * @param it The iterator to be destroyed
 * @warning After calling this function, the iterator pointer should not be used anymore
 */
void queue_iterator_destroy (QueueIterator *it)
{
    if (it == NULL) return;
    free(it);
}