#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main() {
    // Phase 0: Allocation
    // With Opaque Pointers, the struct must be allocated on the heap via your creator
    Deque *d = deque_create();
    
    if (d == NULL) {
        fprintf(stderr, "Failed to create deque. Exiting.\n");
        return EXIT_FAILURE;
    }

    printf("--- Phase 1: Underflow & Integrity ---\n");
    // We pass 'd' directly because it is already a pointer (Deque*)
    printf("Initial Size: %d (Expected 0)\n", size(d));
    
    if (peekFirst(d) == NULL && peekLast(d) == NULL) {
        printf("Peek on empty: NULL (Correct)\n");
    }
    if (removeFirst(d) == NULL && removeLast(d) == NULL) {
        printf("Remove on empty: NULL (Correct)\n");
    }

    printf("\n--- Phase 2: The 'Double-Ended' Stress Test ---\n");
    int v1 = 10, v2 = 20, v3 = 30, v4 = 40;
    
    // Building: [30, 10, 20, 40]
    addFirst(d, &v1); 
    addLast(d, &v2);  
    addFirst(d, &v3); 
    addLast(d, &v4);  

    printf("Size after adds: %d (Expected 4)\n", size(d));
    printf("Front: %d (Expected 30)\n", *(int*)peekFirst(d));
    printf("Back: %d (Expected 40)\n", *(int*)peekLast(d));

    // Cross-removal
    printf("Removed from Last: %d (Expected 40)\n", *(int*)removeLast(d));
    printf("Removed from First: %d (Expected 30)\n", *(int*)removeFirst(d));
    printf("Removed from Last: %d (Expected 20)\n", *(int*)removeLast(d));
    
    printf("Final remaining: %d (Expected 10)\n", *(int*)peekFirst(d));
    printf("Current Size: %d (Expected 1)\n", size(d));

    printf("\n--- Phase 3: Generic Type Mixing ---\n");
    char *s1 = "Alpha";
    char *s2 = "Omega";

    addFirst(d, s1); 
    addLast(d, s2);  

    while (!isEmpty(d)) {
        void *val = removeFirst(d);
        if (val == s1 || val == s2) {
            printf("Dequeued String: %s\n", (char*)val);
        } else {
            printf("Dequeued Int: %d\n", *(int*)val);
        }
    }

    printf("\n--- Phase 4: Final Cleanup ---\n");
    // 1. Clear all nodes to free DequeNode memory
    deque_clear(d);
    
    // 2. Manual free of the manager struct since deque_destroy isn't implemented
    // This is critical because deque_create() used malloc() internally.
    free(d); 
    
    printf("Deque cleared and manager memory freed.\n");

    return 0;
}