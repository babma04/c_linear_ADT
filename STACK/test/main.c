#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    // Phase 0: Dynamic Allocation
    // The user no longer knows the size of 'Stack', so we must use the creator.
    Stack *s = stack_create();
    
    if (s == NULL) {
        fprintf(stderr, "Failed to initialize stack. Exiting.\n");
        return EXIT_FAILURE;
    }

    printf("--- Phase 1: Integrity & Underflow Guard ---\n");
    // Notice: We pass 's' directly now.
    printf("Initial Size: %d (Expected 0)\n", size(s));
    
    if (peek(s) == NULL) printf("Peek on empty: NULL (Correct)\n");
    if (pop(s) == NULL) printf("Pop on empty: NULL (Correct)\n");

    printf("\n--- Phase 2: Integer LIFO Stress Test ---\n");
    int vals[] = {10, 20, 30, 40, 50};
    printf("Pushing: 10, 20, 30, 40, 50\n");
    for (int i = 0; i < 5; i++) {
        push(s, &vals[i]);
    }

    printf("Size after push: %d\n", size(s));
    printf("Top (peek): %d (Expected 50)\n", *(int*)peek(s));

    // Testing LIFO (Last-In, First-Out)
    printf("Popped: %d\n", *(int*)pop(s)); // Should be 50
    printf("Popped: %d\n", *(int*)pop(s)); // Should be 40
    printf("New Top: %d (Expected 30)\n", *(int*)peek(s));

    printf("\n--- Phase 3: Generic Capability (Strings) ---\n");
    char *msg1 = "Stack_Bottom";
    char *msg2 = "Stack_Top";
    push(s, msg1);
    push(s, msg2);

    printf("Total items in stack: %d\n", size(s));

    while (!isEmpty(s)) {
        void *data = pop(s);
        if (data == msg1 || data == msg2) {
            printf("Popped String: %s\n", (char*)data);
        } else {
            printf("Popped Int: %d\n", *(int*)data);
        }
    }

    printf("\n--- Phase 4: Destruction ---\n");
    // Verify re-usability before final destruction
    int final_val = 999;
    push(s, &final_val);
    printf("Stack size before final destroy: %d\n", size(s));
    
    // Total memory cleanup: frees all nodes AND the Stack manager struct
    stack_destroy(s);
    printf("Stack destroyed memory-safely.\n");

    Stack *s2 = stack_create();
    
    int v01 = 10, v02 = 20, v03 = 30;
    push(s2, &v01);
    push(s2, &v02);
    push(s2, &v03); // Stack is now [30 (top), 20, 10]

    printf("--- Phase 5: Stack Iterator Test ---\n");
    printf("Stack size before iteration: %d\n", size(s2));

    StackIterator *it = stack_iterator_create(s2);
    if (it != NULL) {
        printf("Stack contents (Top to Bottom): ");
        while (stack_iterator_has_next(it)) {
            int *val = (int*)stack_iterator_next(it);
            printf("[%d] ", *val);
        }
        printf("\n");
        stack_iterator_destroy(it);
    }

    // Validation: Check if the stack is still full
    printf("Stack size after iteration: %d (Expected 3)\n", size(s2));
    printf("Top still exists: %d (Expected 30)\n", *(int*)peek(s2));

    stack_destroy(s2);
    printf("Second stack destroyed successfully.\n");
    return 0;
}