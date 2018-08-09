CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=-lncurses -lrt
PROGNAME=matrix
DIRNAME=matrix
DEPS=defs.h ncurapi.h matrix.h
OBJ=main.o ncurapi.o matrix.o

.PHONY: all
$(PROGNAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f *.o $(PROGNAME)

.PHONY: tar
tar:
	tar -cf $(DIRNAME).tar ../$(DIRNAME)
