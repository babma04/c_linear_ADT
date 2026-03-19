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
int isEmpty (const Queue *q);
void queue_clear (Queue *q);

#endif

