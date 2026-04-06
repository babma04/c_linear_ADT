#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    Stack s;
    stack_init(&s);

    printf("--- Phase 1: Integrity & Underflow Guard ---\n");
    printf("Initial Size: %d (Expected 0)\n", size(&s));
    
    // Testing safety on empty stack
    if (peek(&s) == NULL) printf("Peek on empty: NULL (Correct)\n");
    if (pop(&s) == NULL) printf("Pop on empty: NULL (Correct)\n");

    printf("\n--- Phase 2: Integer LIFO Stress Test ---\n");
    int vals[] = {10, 20, 30, 40, 50};
    printf("Pushing: 10, 20, 30, 40, 50\n");
    for (int i = 0; i < 5; i++) {
        push(&s, &vals[i]);
    }

    printf("Size after push: %d\n", size(&s));
    printf("Top (peek): %d (Expected 50)\n", *(int*)peek(&s));

    // Partial pop to check mid-stack behavior
    printf("Popped: %d\n", *(int*)pop(&s)); // Should be 50
    printf("Popped: %d\n", *(int*)pop(&s)); // Should be 40
    printf("New Top: %d (Expected 30)\n", *(int*)peek(&s));

    printf("\n--- Phase 3: Generic Capability (Strings) ---\n");
    char *msg1 = "First";
    char *msg2 = "Second";
    push(&s, msg1);
    push(&s, msg2);

    printf("Total items in stack: %d\n", size(&s));

    // Clear and verify LIFO order (Should see 'Second' then 'First')
    while (!isEmpty(&s)) {
        void *data = pop(&s);
        // Checking if it's one of our strings or one of our remaining ints
        if (data == msg1 || data == msg2) {
            printf("Popped String: %s\n", (char*)data);
        } else {
            printf("Popped Int: %d\n", *(int*)data);
        }
    }

    printf("\n--- Phase 4: Final Re-init & Clear ---\n");
    // Ensure we can use the stack again after it was empty
    int final_val = 999;
    push(&s, &final_val);
    printf("Stack size: %d\n", size(&s));
    
    stack_clear(&s);
    printf("Final size after stack_clear: %d\n", size(&s));
    if (isEmpty(&s)) printf("Stack successfully reset.\n");

    return 0;
}