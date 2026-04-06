#ifndef DEQUE_H

#define DEQUE_H

// Structure prototypes
typedef struct Deque Deque;

// Funtions Prototypes
Deque* deque_create ();
int addFirst (Deque *d, void *value);
int addLast (Deque *d, void *value);
void* removeFirst (Deque *d);
void* removeLast (Deque *d);
void* peekFirst (const Deque *d);
void* peekLast (const Deque *d);
int size (const Deque *d);
void deque_clear (Deque *d);
void deque_destroy (Deque *d);
/**
 * Checks if the deque is empty
 * @param d the deque to check
 * @returns 1 if the deque is empty, 0 otherwise
 */
static inline int isEmpty (const Deque *d) {return size(d) == 0;};
#endif // DEQUE_H
