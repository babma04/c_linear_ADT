# Generic Queue ADT in C
## Author: João Carrilho Louro

A professional-grade, thread-agnostic Queue implementation using a linked list and `void *` for universal data storage.

## Features
- **Generic**: Stores any data type (int, char, structs) using void pointers.
- **Dynamic**: Grows and shrinks in memory as needed using a linked structure.
- **O(1) Operations**: Constant time for Enqueue, Dequeue, and Peek.
- **Memory Safe**: Includes a built-in size tracker, NULL-safety guards, and a dedicated clearing function.

## Files
- `queue.h`: Header file with the ADT interface and structure definitions.
- `queue.c`: Implementation of the queue logic (FIFO).
- `Makefile`: Automation for compilation.

## USEFUL COMMANDS FOR THIS LIB

- `make` (compiles everything and creates an executable `queue_test`)
- `make run` (compiles everyting and runs `./queue_test`)
- `./queue_test` (after 'make' to run the executable)
- `make clean` (deletes all .o files and the executable `queue_test`)
- `valgrind --leak-check=full ./test/queue_test` (Verifies memory leaks)

## Usage example
```c
Queue *q = queue_create();
int val = 42;
enqueue(q, &val);
int *result = (int*)dequeue(q);
queue_destroy(q);

```

## How to Compile
- Run the following command in your terminal:
```
make 
```
