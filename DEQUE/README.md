# Generic Queue ADT in C
## Author: João Carrilho Louro

A professional-grade, thread-agnostic Deque implementation using a doubly linked list and `void *` for universal data storage.

## Features
- **Generic**: Stores any data type (int, char, structs) using void pointers.
- **Dynamic**: Grows and shrinks in memory as needed using a doubly linked structure.
- **O(1) Operations**: Constant time for addFirst, addLast, removeFirst, removeLast, peekFirst and peekLast.
- **Memory Safe**: Includes a built-in size tracker, NULL-safety guards, and a dedicated clearing function.

## Files
- `deque.h`: Header file with the ADT interface and structure definitions.
- `deque.c`: Implementation of the deque logic (FIFO & FILO).
- `Makefile`: Automation for compilation.

## USEFUL COMMANDS FOR THIS LIB

- `make` (compiles everything and creates an executable `deque_test`)
- `./deque_test` (after 'make' to run the executable)
- `make clean` (deletes all .o files and the executable `deque_test`)
- `valgrind --leak-check=full ./deque_test` (Verifies memory leaks)

## Usage example
```c
Deque d;
deque_init(&q);
int val = 42;
addFirst(&q, &val);
int *result = (int*)removeFirst(&q);
```

## How to Compile
- Run the following command in your terminal:
```
make 
```

