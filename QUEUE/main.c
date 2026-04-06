#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    queue_init(&q);

    // 1. Test with Integers
    int vals[] = {10, 20, 30};
    printf("Enqueuing integers: 10, 20, 30\n");
    for (int i = 0; i < 3; i++) enqueue(&q, &vals[i]);

    printf("Front of queue: %d\n", *(int*)peek(&q));

    // 2. Test FIFO order
    while (!isEmpty(&q)) {
        int *data = (int*)dequeue(&q);
        printf("Dequeued: %d\n", *data);
    }

    // 3. Test with Strings (Generics in action!)
    printf("\nEnqueuing strings: 'Alpha', 'Beta'\n");
    enqueue(&q, "Alpha");
    enqueue(&q, "Beta");

    while (!isEmpty(&q)) {
        printf("Dequeued: %s\n", (char*)dequeue(&q));
    }

    queue_clear(&q);
    return 0;
}
