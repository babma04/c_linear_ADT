# Variables for compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Directory names
SRC_DIR = src
INC_DIR = include
TEST_DIR = test
OBJ_DIR = obj
BIN_DIR = bin

# The final executable name and path
TARGET = $(TEST_DIR)/deque_test

# The object files
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/deque.o

# Default rule
all: directories $(TARGET)

# Rule to create necessary directories
directories:
	@mkdir -p $(OBJ_DIR)

# Rule to create the final executable inside the test folder
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile deque.c into the obj folder
$(OBJ_DIR)/deque.o: $(SRC_DIR)/deque.c $(INC_DIR)/deque.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile main.c into the obj folder
$(OBJ_DIR)/main.o: $(TEST_DIR)/main.c $(INC_DIR)/deque.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up binaries and object files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "Cleaned up objects and the test executable."

# Shortcut to run the test
run: all
	./$(TARGET)

.PHONY: all directories clean run