# Generic Stack ADT in C
## Author: João Carrilho Louro

A professional-grade, thread-agnostic Stack implementation using `void *` for universal data storage.

## Features
- **Generic**: Stores any data type (int, char, structs) using void pointers.
- **Dynamic**: Grows and shrinks in memory as needed.
- **O(1) Operations**: Constant time for Push, Pop, and Peek.
- **Memory Safe**: Includes a built-in size tracker and NULL guards.

## Files
- `stack.h`: Header file with the ADT interface.
- `stack.c`: Implementation of the stack logic.
- `Makefile`: Automation for compilation.

## USEFULL COMMANDS FOR THIS LIB
- `make` (compiles everything and creates an executable `stack_test`)
- `make run` (compiles everything and runs `./stack_test`)
- `./stack_test` (after `make` to run the executable)
- `make clean` (deletes all .o files and the executable `stack_test`)
- `valgrind --leak-check=full ./test/stack_test `(Verifies memory leaks)

## Usage example
```c
Stack *s = stack_create();
int val = 42;
push(&s, &val);
int *result = (int*)pop(&s);
stack_destroy(s); 
``` 

## How to Compile 
- Run the following command in your terminal:
```
make
```

