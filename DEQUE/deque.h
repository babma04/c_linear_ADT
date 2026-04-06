#ifndef DEQUE_H

#define DEQUE_H

// Deque structure
typedef struct DequeNode {
    void *value;
    struct DequeNode *next;
    struct DequeNode *previous;
} DequeNode;

typedef struct {
    DequeNode *first;
    DequeNode *last;
    int size;
} Deque;

// Funtions Prototypes
void deque_init (Deque *d);
int addFirst (Deque *d, void *value);
int addLast (Deque *d, void *value);
void* removeFirst (Deque *d);
void* removeLast (Deque *d);
void* peekFirst (const Deque *d);
void* peekLast (const Deque *d);
void deque_clear (Deque *d);
/**
 * @returns the number of elements in the deque
 * @param d the deque to check
 */
static inline int size (Deque *d) {return d->size;};
/**
 * Checks if the deque is empty
 * @param d the deque to check
 * @returns 1 if the deque is empty, 0 otherwise
 */
static inline int isEmpty (const Deque *d) {return d->size == 0;};
#endif // DEQUE_H
