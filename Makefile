CC=gcc
CFLAGS = -g -Wall -I./include

SRC = src
BUILD = build

SOURCES = $(SRC)/main.c $(SRC)/flags.c $(SRC)/log.c $(SRC)/search.c
OBJECTS = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SOURCES))
TARGET = $(BUILD)/assembler

TEST1 = ./build/assembler
TEST2 = ./build/assembler tests/compileme.ass

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

test:
	$(TEST1)
	$(TEST2)

