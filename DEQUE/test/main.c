#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main() {
    Deque d;
    deque_init(&d);

    printf("--- Phase 1: Underflow & Integrity ---\n");
    printf("Initial Size: %d (Expected 0)\n", size(&d));
    if (peekFirst(&d) == NULL && peekLast(&d) == NULL) {
        printf("Peek on empty: NULL (Correct)\n");
    }
    if (removeFirst(&d) == NULL && removeLast(&d) == NULL) {
        printf("Remove on empty: NULL (Correct)\n");
    }

    printf("\n--- Phase 2: The 'Double-Ended' Stress Test ---\n");
    int v1 = 10, v2 = 20, v3 = 30, v4 = 40;
    
    // Building: [30, 10, 20, 40]
    addFirst(&d, &v1); // [10]
    addLast(&d, &v2);  // [10, 20]
    addFirst(&d, &v3); // [30, 10, 20]
    addLast(&d, &v4);  // [30, 10, 20, 40]

    printf("Size after adds: %d (Expected 4)\n", size(&d));
    printf("Front: %d (Expected 30)\n", *(int*)peekFirst(&d));
    printf("Back: %d (Expected 40)\n", *(int*)peekLast(&d));

    // Cross-removal: Remove from back, then front, then back
    printf("Removed from Last: %d (Expected 40)\n", *(int*)removeLast(&d));
    printf("Removed from First: %d (Expected 30)\n", *(int*)removeFirst(&d));
    printf("Removed from Last: %d (Expected 20)\n", *(int*)removeLast(&d));
    
    printf("Final remaining: %d (Expected 10)\n", *(int*)peekFirst(&d));
    printf("Current Size: %d (Expected 1)\n", size(&d));

    printf("\n--- Phase 3: Generic Type Mixing ---\n");
    char *s1 = "Alpha";
    char *s2 = "Omega";

    addFirst(&d, s1); // [Alpha, 10]
    addLast(&d, s2);  // [Alpha, 10, Omega]

    while (!isEmpty(&d)) {
        void *val = removeFirst(&d);
        if (val == s1 || val == s2) {
            printf("Dequeued String: %s\n", (char*)val);
        } else {
            printf("Dequeued Int: %d\n", *(int*)val);
        }
    }

    printf("\n--- Phase 4: Reusability & Memory Clear ---\n");
    // Ensure we can use it again after it was empty
    int retest = 99;
    addLast(&d, &retest);
    printf("Size after re-add: %d\n", size(&d));
    
    deque_clear(&d);
    printf("Final size after clear: %d\n", size(&d));
    if (isEmpty(&d)) printf("Deque successfully reset.\n");

    return 0;
}