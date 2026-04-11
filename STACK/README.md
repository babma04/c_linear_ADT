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
- `./stack_test` (after any `make` command to run the executable)
- `make clean` (deletes all .o files and the executable `stack_test`)
- `valgrind --leak-check=full ./test/stack_test `(Verifies memory leaks)

## API

### Stack operations:
- **Stack* stack_create**: Creates a new Stack struct and hands out its pointer;
- **int push**: Adds an element to the top of the stack;
- **void* pop**: Removes an element from the top of the stack and returns the pointer to its value in memory;
- **void* peek**: Returns a pointer to the value in the front position of the queue in memory;
- **void* peek**: Returns a pointer to the value in the top position of the stack in memory;
- **int size**: Returns the current size of the stack;
- **void stack_clear**: Removes all values from the stack;
- **void stack_destroy**: Removes all values from the stack and destroys the structure holding it;
- **int isEmpty**: Verifies if the stack is empty or not;

### Iterator related operations:
- **StackIterator* stack_iterator_create**: Creates a new StackIterator struct and hands out its pointer;
- **void* stack_iterator_next**: Verifies if there's a next element in the iterator cicle;
- **int stack_iterator_has_next**: Returns a pointer for the value in memory of the next value and moves the iterator to it;
- **void stack_iterator_destroy**: Destroys the iterator structure;

## Usage example
### Stack:
```c
Stack *s = stack_create();
int val = 42;
push(&s, &val);
int *result = (int*)pop(&s);
stack_destroy(s); 
``` 

### Stack iterator:
```c
Stack *s = stack_create();
int v1 = 1, v2 = 2, v3 = 3;
push (s, &v1);
push (s, &v2);
push (s, &v3);

StackIterator *it = stack_iterator_create();
while (stack_iterator_has_next(it))
{
    int *val = (int*) stack_iterator_next(it);
}
stack_iterator_destroy(it);
```


## How to Compile 
- Run the following command in your terminal:
```
make
```

