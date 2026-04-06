#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    // Phase 0: Initialization
    // We now allocate the Queue manager struct on the heap.
    Queue *q = queue_create();
    
    if (q == NULL) {
        fprintf(stderr, "Failed to create queue. Exiting.\n");
        return EXIT_FAILURE;
    }

    printf("--- Phase 1: Underflow & Integrity ---\n");
    // We pass 'q' directly (it is already a pointer).
    printf("Initial Size: %d (Expected 0)\n", size(q));
    
    if (peek(q) == NULL) printf("Peek on empty: NULL (Correct)\n");
    if (dequeue(q) == NULL) printf("Dequeue on empty: NULL (Correct)\n");

    printf("\n--- Phase 2: Integer FIFO Stress Test ---\n");
    int vals[] = {10, 20, 30, 40, 50};
    printf("Enqueuing: 10, 20, 30, 40, 50\n");
    for (int i = 0; i < 5; i++) {
        enqueue(q, &vals[i]);
    }

    printf("Size after enqueue: %d (Expected 5)\n", size(q));
    printf("Front (peek): %d (Expected 10)\n", *(int*)peek(q));

    // Testing FIFO (First-In, First-Out) logic
    printf("Dequeued: %d\n", *(int*)dequeue(q)); // Should be 10
    printf("Dequeued: %d\n", *(int*)dequeue(q)); // Should be 20
    printf("New Front: %d (Expected 30)\n", *(int*)peek(q));

    printf("\n--- Phase 3: Generic Capability (Strings) ---\n");
    char *s1 = "Queue_Start";
    char *s2 = "Queue_End";
    enqueue(q, s1);
    enqueue(q, s2);

    printf("Total items in queue: %d\n", size(q));

    while (!isEmpty(q)) {
        void *data = dequeue(q);
        if (data == s1 || data == s2) {
            printf("Dequeued String: %s\n", (char*)data);
        } else {
            printf("Dequeued Int: %d\n", *(int*)data);
        }
    }

    printf("\n--- Phase 4: Final Destruction ---\n");
    // Verify re-usability
    int final_val = 999;
    enqueue(q, &final_val);
    printf("Final enqueue check, size: %d\n", size(q));
    
    // This frees all nodes AND the Queue manager struct.
    queue_destroy(q);
    printf("Queue structure and nodes destroyed successfully.\n");

    Queue *q1 = queue_create();
    
    char *names[] = {"Alice", "Bob", "Charlie", "Dave"};
    for (int i = 0; i < 4; i++) {
        enqueue(q1, names[i]);
    }

    printf("--- Phase 5: Queue Iterator Test ---\n");
    printf("Queue size before iteration: %d\n", size(q1));
    QueueIterator *it = queue_iterator_create(q1);
    if (it != NULL) {
        printf("Queue Order (Front to Rear): ");
        while (queue_iterator_has_next(it)) {
            char *name = (char*)queue_iterator_next(it);
            printf("[%s] ", name);
        }
        printf("\n");
        queue_iterator_destroy(it);
    }

    // Verification: The queue should still have all elements
    printf("Queue size after iteration: %d (Expected 4)\n", size(q1));
    printf("Next in line (peek): %s (Expected Alice)\n", (char*)peek(q1));

    queue_destroy(q1);
    printf("Second queue destroyed successfully.\n");
    return 0;
}