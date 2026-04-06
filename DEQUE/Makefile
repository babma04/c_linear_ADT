# Variables for compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# The final executable name
TARGET = deque_test

# The object files (compiled versions of .c files)
OBJS = main.o deque.o

# Rule to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile deque.c
deque.o: deque.c deque.h
	$(CC) $(CFLAGS) -c deque.c

# Rule to compile main.c
main.o: main.c deque.h
	$(CC) $(CFLAGS) -c main.c

# Clean up binaries
clean:
	rm -f $(OBJS) $(TARGET)
