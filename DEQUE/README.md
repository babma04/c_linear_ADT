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
- `make run` (compiles everything and runs the `./deque_test`)
- `./deque_test` (after any `make` command to run the executable)
- `make clean` (deletes all .o files and the executable `deque_test`)
- `valgrind --leak-check=full ./test/deque_test` (Verifies memory leaks)

## API

### Deque operations:
- **Deque* deque_create**: Creates a new Deque struct and hands out its pointer;
- **int addFirst / addLast**: Adds an element to the start/end of the deque;
- **void* removeFirst / removeLast**: Removes an element from the front / end of the deque and hands out a pointer to its value in memory;
- **void* peekFirst / peekLast**: Hands out a pointer to the value in the front / end position of the deque in memory;
- **int size**: Returns the current size of the deque;
- **void deque_clear**: Removes all values from the deque;
- **void deque_destroy**: Removes all values from the deque and destroys the structure holding it;
- **int isEmpty**: Verifies if the deque is empty or not;

### Iterator related operations:
- **DequeIterator* deque_iterator_create**: Creates a new DequeIterator struct and hands out its pointer;
- **void* deque_iterator_next**: Verifies if there's a next element in the iterator cicle;
- **int deque_iterator_has_next**: Returns a pointer for the value in memory of the next value and moves the iterator to it;
- **void deque_iterator_destroy**: Destroys the iterator structure;

## Usage example
### Deque:
```c
Deque *d = deque_create();
int val = 42;
addFirst(d, &val);
int *result = (int*)removeFirst(d);
deque_destroy(d);
```

### Deque iterator:
```c
Deque *d = deque_create();
int v1 = 100, v2 = 200;
addLast (d, &v1);
addLast(d, &v2);

DequeIterator *it = deque_iterator_create();
if (it == NULL) printf("Fail");

int counter = 0;
while (deque_iterator_has_next(it))
{
    void *data = deque_iterator_next(it);
    counter++;
}
deque_iterator_destroy(it);
```

## How to Compile
- Run the following command in your terminal:
```
make 
```

