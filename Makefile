CC = gcc
CFLAGS = -Wall -Wextra -lm

all: main

main: math_matrix.c functions.c functions.h
	$(CC) -o math_matrix math_matrix.c functions.c $(CFLAGS)

clean: 
	rm -f math_matrix