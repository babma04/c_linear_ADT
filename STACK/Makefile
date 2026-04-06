# Variables
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Directory names
SRC_DIR = src
INC_DIR = include
TEST_DIR = test
OBJ_DIR = obj

# Final binary in the test folder
TARGET = $(TEST_DIR)/stack_test

# Objects
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/stack.o

all: directories $(TARGET)

directories:
	@mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/stack.o: $(SRC_DIR)/stack.c $(INC_DIR)/stack.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: $(TEST_DIR)/main.c $(INC_DIR)/stack.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all directories clean run