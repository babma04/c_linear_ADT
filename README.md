# c_linear_ADT: A Collection of Generic Data Types in C
## Author: João Carrilho Louro 

This repository is a personal library of highly reusable, generic, and memory-safe Data Types (DT) written in C. Each structure is implemented as an Abstract Data Type (ADT) using `void *` to ensure compatibility with any data format.

## Project Structure

Each data structure is contained within its own modular implementation:

* **[Stack](./STACK)**: A LIFO (Last-In, First-Out) implementation using a dynamic linked-list.
* **[Queue](./QUEUE)**: A FIFO (First-In, First-Out) implementation using a dynamic linked lists for $O(1)$ performance.
* **[Deque](./DEQUE)**: A Double-Ended Queue supporting $O(1)$ additions and removals at both ends implemented using dounly-linked lists.

## Design Principles

1.  **Generic Storage**: All structures use `void *` pointers to store data, allowing the library to handle `int`, `char*`, or custom `struct` types without modification.
2.  **Opaque pointers**: All ADT are defined through opaque pointers to hidden structures defined inside the .c files for maximum abstraction.
3.  **Encapsulation**: Internal logic is hidden; users interact only through defined headers in the `include/` directories.
4.  **Memory Safety**: Every structure includes size tracking and NULL-guards and dedicated `_clear` functions to prevent memory leaks and segmentation faults.
5.  **Performance**: Core operations (Push/Pop/Enqueue/Dequeue) are optimized for constant time complexity.
6.  **Iteration**: Each ADT has a costume iterator with specific methods for a simpler iteration over the base ADT.

## How to Use

### 1. Inclusion
Include the desired header in your project. Our Makefiles use the -Iinclude flag to simplify this:
```c
#include "stack.h"
#include "queue.h"
#include "deque.h"
```
### 2. Compilation
#### Individual compilations:
Each sub-folder contains a standalone `Makefile`. You can compile individual tests by navigating to the folder:
```bash
cd STACK && make

cd QUEUE && make

cd DEQUE && make
```
There are also more compilation related commands explained in each directory README

## Memory Verification

To ensure the integrity of the "Backbone," all structures are verified using Valgrind:
```bash
valgrind --leak-check=full ./Stack/test/stack_test
valgrind --leak-check=full ./Queue/test/queue_test
valgrind --leak-check=full ./Deque/test/deque_test
```

---

Developed for the Data Structures and Algorithms curriculum by João Carrilho Louro @FCUL.

