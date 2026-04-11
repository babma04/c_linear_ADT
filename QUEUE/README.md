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
- `./queue_test` (after any `make` command to run the executable)
- `make clean` (deletes all .o files and the executable `queue_test`)
- `valgrind --leak-check=full ./test/queue_test` (Verifies memory leaks)

## API

### Queue operations:
- **Queue* queue_create**: Creates a new Queue struct and hands out its pointer;
- **int enqueue**: Adds an element to the end of the queue;
- **void* dequeue**: Removes an element from the front of the queue and returns the pointer to its value in memory;
- **void* peek**: Returns a pointer to the value in the front position of the queue in memory;
- **int size**: Returns the current size of the queue;
- **void queue_clear**: Removes all values from the queue;
- **void queue_destroy**: Removes all values from the queue and destroys the structure holding it;
- **int isEmpty**: Verifies if the queue is empty or not;

### Iterator related operations:
- **QueueIterator* queue_iterator_create**: Creates a new QueueIterator struct and hands out its pointer;
- **int queue_iterator_has_next**: Verifies if there's a next element in the iterator cicle;
- **void* queue_iterator_next**: Returns a pointer for the value in memory of the next value and moves the iterator to it;
- **void queue_iterator_destroy**: Destroys the iterator structure;


## Usage example
### Queue:
```c
Queue *q = queue_create();
int val = 42;
enqueue(q, &val);
int *result = (int*)dequeue(q);
queue_destroy(q);
```

### Queue iterator:
```c
Queue *q = queue_create();
int v1 = 1, v2 = 2, v3 = 3;
enqueue(q, &v1);
enqueue(q, &v2);
enqueue(q, &v3);

QueueIterator *it = queue_iterator_create();
int counter = 0;
while (queue_iterator_has_next(it))
{
    queue_iterator_next(it);
    counter++;
}
queue_iterator_destroy(it);
```

## How to Compile
- Run the following command in your terminal:
```
make 
```
