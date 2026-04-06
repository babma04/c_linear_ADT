#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main() {
    Queue q;
    queue_init(&q);

    printf("--- Phase 1: Integrity & Empty State ---\n");
    printf("Initial Size: %d (Expected 0)\n", size(&q));
    if (peek(&q) == NULL) printf("Peek on empty: NULL (Correct)\n");
    if (dequeue(&q) == NULL) printf("Dequeue on empty: NULL (Correct)\n");

    printf("\n--- Phase 2: Integer Stress Test (FIFO) ---\n");
    int vals[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        enqueue(&q, &vals[i]);
    }
    printf("Size after 5 enqueues: %d\n", size(&q));
    printf("Front is: %d (Expected 10)\n", *(int*)peek(&q));

    // Dequeue a few to check mid-state
    printf("Dequeued: %d\n", *(int*)dequeue(&q));
    printf("Dequeued: %d\n", *(int*)dequeue(&q));
    printf("New Front: %d (Expected 30)\n", *(int*)peek(&q));
    printf("New Size: %d (Expected 3)\n", size(&q));

    printf("\n--- Phase 3: Generic Capability (Strings) ---\n");
    // Interleaving types - the power of void*
    char *msg1 = "Backbone";
    char *msg2 = "Library";
    enqueue(&q, msg1);
    enqueue(&q, msg2);

    printf("Total items in queue: %d\n", size(&q));

    // Clear remaining items and verify types
    while (!isEmpty(&q)) {
        void *data = dequeue(&q);
        // Basic logic to print based on what we know is in there
        if (size(&q) >= 2) { 
            printf("Dequeued Int: %d\n", *(int*)data);
        } else {
            printf("Dequeued String: %s\n", (char*)data);
        }
    }

    printf("\n--- Phase 4: Re-initialization & Clear ---\n");
    // Ensure the queue can be reused after being emptied
    int re_test = 999;
    enqueue(&q, &re_test);
    printf("Re-test size: %d\n", size(&q));
    
    queue_clear(&q);
    printf("Final size after clear: %d\n", size(&q));
    if (isEmpty(&q)) printf("Queue is successfully reset.\n");

    return 0;
}