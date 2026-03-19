# c_DT: A Collection of Generic Data Types in C
## Author: João Carrilho Louro 

This repository is a personal library of highly reusable, generic, and memory-safe Data Types (DT) written in C. Each structure is implemented as an Abstract Data Type (ADT) using `void *` to ensure compatibility with any data format.

## 📂 Project Structure

Each data structure is contained within its own modular implementation:

* **[Stack](./Stack)**: A LIFO (Last-In, First-Out) implementation using a dynamic linked-list.
* **[Queue](./Queue)**: A FIFO (First-In, First-Out) implementation using a doubly-linked lest for $O(1)$ performance.
* *(Upcoming)* **/LinkedList**: A doubly-linked list for flexible data manipulation.

## 🚀 Design Principles

1.  **Generic Storage**: All structures use `void *` pointers to store data, allowing the library to handle `int`, `char*`, or custom `struct` types without modification.
2.  **Encapsulation**: Internal logic is hidden in `.c` files; users interact only through defined `.h` interfaces.
3.  **Memory Safety**: Every structure includes size tracking and NULL-guards to prevent segmentation faults.
4.  **O(1) Performance**: Core operations (Push/Pop/Enqueue/Dequeue) are optimized for constant time complexity.

## 🛠️ How to Use

### 1. Inclusion
Copy the desired `.h` and `.c` files into your project and include the header:
```c
#include "stack.h"
#include "queue.h"
```
### 2. Compilation
Each sub-folder contains a standalone `Makefile`. You can compile individual tests by navigating to the folder:
```c
cd STACK && make

cd QUEUE && make
```

## 🧪 Memory Verification

To ensure the integrity of the "Backbone," all structures are verified using Valgrind:
```c
valgrind --leak-check=full ./stack_test

valgrind --leak-check=full ./queue_test
```
## 
Developed for the Data Structures and Algorithms curriculum by João Carrilho Louro @FCUL.

