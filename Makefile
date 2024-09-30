CC=gcc
CFLAGS = -g -Wall -I./include

SRC = src
BUILD = build

SOURCES = $(SRC)/main.c $(SRC)/flags.c $(SRC)/error.c $(SRC)/search.c
OBJECTS = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SOURCES))
TARGET = $(BUILD)/assembler

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

test:
	./build/assembler tests/compileme.ass
