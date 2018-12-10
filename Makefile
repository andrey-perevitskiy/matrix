CC=gcc

CFLAGS=-c -Wall -Wextra
LDFLAGS=-lncurses -lrt

OBJS=main.o ncurapi.o matrix.o
DEPS=defs.h ncurapi.h matrix.h

PROG_NAME=matrix
DIR_NAME=matrix

all: $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG_NAME) $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(PROG_NAME) *.o

.PHONY: tar
tar:
	tar -cf $(DIR_NAME).tar ../$(DIR_NAME)
