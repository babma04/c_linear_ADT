# Variables for compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# The final executable name
TARGET = queue_test

# The object files (compiled versions of .c files)
OBJS = main.o queue.o

# Rule to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.c
main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c

# Rule to compile queue.c
queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

# Clean up binaries
clean:
	rm -f $(OBJS) $(TARGET)
