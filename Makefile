CC=gcc
LDFLAGS=-lncurses -lrt
PROGNAME=matrix
DIRNAME=matrix

.PHONY: all
matrix: main.o ncurapi.o matrix.o
	$(CC) $(LDFLAGS) -o $(PROGNAME) main.o ncurapi.o matrix.o

main.o: main.c ncurapi.h matrix.h
	$(CC) -c main.c -o main.o

ncurapi.o: ncurapi.c ncurapi.h
	$(CC) -c ncurapi.c -o ncurapi.o

matrix.o: matrix.c matrix.h
	$(CC) -c matrix.c -o matrix.o

.PHONY: clean
clean:
	rm -f *.o $(PROGNAME)

.PHONY: tar
tar:
	tar -cf $(DIRNAME).tar ../$(DIRNAME)
