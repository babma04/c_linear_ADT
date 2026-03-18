#include <stdio.h>
#include "stack.h"

int main() {
    // 1. Initialize the stack
    Stack myStack;
    stack_init(&myStack);

    printf("--- Testing Integers ---\n");
    int a = 10, b = 20, c = 30;
    push(&myStack, &a);
    push(&myStack, &b);
    push(&myStack, &c);

    printf("Stack size: %d\n", myStack.size);
    printf("Top element (peek): %d\n", *(int*)peek(&myStack));

    while (!isEmpty(&myStack)) {
        int *val = (int*)pop(&myStack);
        printf("Popped: %d\n", *val);
    }

    printf("\n--- Testing Strings ---\n");
    char *word1 = "Hello";
    char *word2 = "World";
    push(&myStack, word1);
    push(&myStack, word2);

    while (!isEmpty(&myStack)) {
        printf("Popped: %s\n", (char*)pop(&myStack));
    }

    // 2. Clean up (good habit, even if empty)
    stack_clear(&myStack);
    printf("\nStack cleared. Final size: %d\n", myStack.size);

    return 0;
}
