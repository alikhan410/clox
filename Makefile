# Define the compiler
CC = gcc

# Define any compile-time flags
CFLAGS = -Wall -g -Wno-return-type

# Define your source files
SRC = main.c value.c memory.c 

# Define the output file
TARGET = main

# Default target to build the executable
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Clean up object and executable files
clean:
	rm -f $(TARGET)

# Rule to run the program with a hardcoded file argument
run: $(TARGET)
	./$(TARGET) ./code.txt
