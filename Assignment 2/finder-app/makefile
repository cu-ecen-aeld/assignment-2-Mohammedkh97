# Define cross compiler prefix
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -g

# Source files
SRCS = writer.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output binary name
TARGET = writer

# Default target: build the program
all: $(TARGET)

# Rule to link object files into the target
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)   # Ensure this line starts with a tab

# Rule to compile the source file into an object file
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)   # Ensure this line starts with a tab

# Clean target: remove object files and binary
clean:
	rm -f $(OBJS) $(TARGET)   # Ensure this line starts with a tab

# Phony targets
.PHONY: all clean

