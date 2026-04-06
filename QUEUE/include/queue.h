#ifndef QUEUE_H

#define QUEUE_H

// Structure prototypes
typedef struct Queue Queue;

// Funtion Prototypes
Queue* queue_create();
int enqueue (Queue *q, void *value);
void* dequeue (Queue *q);
void* peek (const Queue *q);
int size (const Queue *q);
void queue_clear (Queue *q);
void queue_destroy (Queue *q);
/**
 * Checks if the queue is empty.
 * @param q The queue to be checked.
 * @returns 1 if the queue is empty, 0 otherwise.
 */
static inline int isEmpty (const Queue *q)  {return size (q) == 0;};

// Iterator structure and functions
typedef struct QueueIterator QueueIterator;
QueueIterator* queue_iterator_create (const Queue *q);
int queue_iterator_has_next (const QueueIterator *it);
void* queue_iterator_next (QueueIterator *it);
void queue_iterator_destroy (QueueIterator *it);
#endif // QUEUE_H

