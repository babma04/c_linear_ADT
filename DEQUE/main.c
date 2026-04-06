#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

int main() {
    Deque d;
    deque_init(&d);

    printf("--- Phase 1: Basic Deque Operations (Integers) ---\n");
    int v1 = 10, v2 = 20, v3 = 30;

    addFirst(&d, &v1); // Deque: [10]
    addLast(&d, &v2);  // Deque: [10, 20]
    addFirst(&d, &v3); // Deque: [30, 10, 20]

    printf("Size after adds: %d\n", size(&d));
    printf("Peek First: %d (Expected 30)\n", *(int*)peekFirst(&d));
    printf("Peek Last: %d (Expected 20)\n\n", *(int*)peekLast(&d));

    printf("--- Phase 2: Mixed Removal ---\n");
    printf("Removed from First: %d\n", *(int*)removeFirst(&d)); // Should be 30
    printf("Removed from Last: %d\n", *(int*)removeLast(&d));   // Should be 20
    printf("Remaining: %d (Expected 10)\n\n", *(int*)peekFirst(&d));

    printf("--- Phase 3: Generic Logic (Strings) ---\n");
    // Since it's a generic ADT, let's mix it up
    char *s1 = "Alpha";
    char *s2 = "Omega";

    addFirst(&d, s1); // [Alpha, 10]
    addLast(&d, s2);  // [Alpha, 10, Omega]

    printf("Current Size: %d\n", size(&d));
    
    // Emptying the Deque completely
    while (!isEmpty(&d)) {
        // Note: In a real app, you'd need to know the type, 
        // but for a test, we know the order.
        void *val = removeFirst(&d);
        if (val == s1 || val == s2) {
            printf("Dequeued String: %s\n", (char*)val);
        } else {
            printf("Dequeued Int: %d\n", *(int*)val);
        }
    }

    printf("\n--- Phase 4: Empty State Safety ---\n");
    if (removeFirst(&d) == NULL) {
        printf("Success: removeFirst on empty deque returned NULL.\n");
    }

    // Final cleanup
    deque_clear(&d);
    printf("Deque cleared. Final size: %d\n", size(&d));

    return 0;
}
