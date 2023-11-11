CC=gcc
CFLAGS=-Iinclude
DEPS = $(wildcard include/*.h)
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)

TARGET=build/game

.PHONY: all run clean debug

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

build/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: all
	./$(TARGET)

clean:
	rm -f build/*

debug: all
	gdb ./$(TARGET)
