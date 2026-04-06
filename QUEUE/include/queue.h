#ifndef QUEUE_H

#define QUEUE_H

// Queue structure
typedef struct QueueNode {
    void *value;
    struct QueueNode *next;
    struct QueueNode *previous;
} QueueNode;

// Main handler of the queue
typedef struct {
    QueueNode *first;
    // Optional (might not be available)
    QueueNode *last;
    int size;
} Queue;

// Funtion Prototypes
void queue_init (Queue *q);
int enqueue (Queue *q, void *value);
void* dequeue (Queue *q);
void* peek (const Queue *q);
void queue_clear (Queue *q);
/**
 * @returns the size of the queue.
 * @param q The queue to be checked.
 */
static inline int size (const Queue *q) {return q->size;};
/**
 * Checks if the queue is empty.
 * @param q The queue to be checked.
 * @returns 1 if the queue is empty, 0 otherwise.
 */
static inline int isEmpty (const Queue *q)  {return size (q) == 0;};
#endif // QUEUE_H

