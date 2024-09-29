CC = gcc
CFLAGS = -Wall -Wno-builtin-declaration-mismatch
OBJ = $(patsubst src/%,bin/%.o,$(wildcard src/*.asm src/*.c))
BIN = bin/server

all: $(BIN)

clean:
	rm bin/*

run: all
	./$(BIN)

bin/%.asm.o: src/%.asm
	nasm -f elf64 -o $@ $^

bin/%.c.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

bin/server: $(OBJ)
	$(CC) -o $@ $^ -nostdlib
