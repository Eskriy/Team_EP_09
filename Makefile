CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

main: main.c team.c teamvec.c team.h teamvec.h
	$(CC) $(CFLAGS) main.c team.c teamvec.c -o main

clean:
	rm -f main

.PHONY: clean
