# Compiler settings
CC = gcc
CFLAGS = -Wall -O2
# LDFLAGS =

# Directories
SRC_DIR = .
EXAMPLES_DIR = examples
BUILD_DIR = build

# Source files (automatically find all .c files)
SRCS = $(wildcard $(SRC_DIR)/*.c)
EXAMPLE_SRCS = $(wildcard $(EXAMPLES_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
EXAMPLE_OBJS = $(EXAMPLE_SRCS:$(EXAMPLES_DIR)/%.c=$(BUILD_DIR)/%.o)

# Include directories
INCLUDES = -I$(SRC_DIR) -I$(EXAMPLES_DIR)

# Target executable
TARGET = $(BUILD_DIR)/runProgram

# Default target
all: $(BUILD_DIR) $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile example files
$(BUILD_DIR)/%.o: $(EXAMPLES_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link
$(TARGET): $(OBJS) $(EXAMPLE_OBJS)
	$(CC) $(OBJS) $(EXAMPLE_OBJS) -o $(TARGET) $(LDFLAGS) -lm

# Clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
