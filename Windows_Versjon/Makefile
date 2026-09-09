# program executable name
TARGET = currentProg

# compiler
CC = gcc

# compiler flags
CFLAGS = -g -Wall -std=gnu11

# linker flags
LDFLAGS = -g

# list of sources
SOURCES = $(shell find . -type f -name "*.c")

# define object files
OBJECTS = $(SOURCES:.c=.o)

# default rule, compile everything
all: $(TARGET)

# link program
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

# compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# cleaning
clean:
	rm -f $(TARGET) $(OBJECTS)