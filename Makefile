# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

# Find all component .c files (Stack, Queue, Deque)
# This looks into each subfolder in src/
SRCS = $(wildcard $(SRC_DIR)/STACK/*.c) \
       $(wildcard $(SRC_DIR)/QUEUE/*.c) \
       $(wildcard $(SRC_DIR)/DEQUE/*.c) \
       $(SRC_DIR)/main.c

# Convert source files to object files in an 'obj' directory
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Final Executable Name
TARGET = $(BIN_DIR)/master_test

# --- Rules ---

all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $(TARGET)
	@echo "Build successful: $(TARGET)"

# Compile each .c file into a .o file
# This handles the subfolder structure automatically
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the master test
run: all
	./$(TARGET)

# Memory check with Valgrind (Since we are using Heap memory now!)
valgrind: all
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleanup complete."

.PHONY: all clean run valgrind