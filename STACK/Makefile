# Variables for compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# The final executable name
TARGET = stack_app

# The object files (compiled versions of your .c files)
OBJS = main.o stack.o

# Rule to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.c
main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

# Rule to compile stack.c
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

# Clean rule to remove compiled files
clean:
	rm -f $(OBJS) $(TARGET)
