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
#endif // QUEUE_H

