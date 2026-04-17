# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g -IInc

# Target executable
TARGET = student_performance_monitoring

# Source and object files
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, %.o, $(SRCS))

.PHONY: all clean

# Default rule
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files inside build/
%.o: src/%.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@echo "Cleaning up..."
	@rm -f $(OBJS) $(TARGET)
