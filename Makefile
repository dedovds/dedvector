CC=gcc

CFLAGS=-c -Wall -fprofile-arcs -ftest-coverage

all: tests

tests.o: tests.c
	${CC} -c tests.c -o tests.o ${CFLAGS}
vector.o: vector.c
	${CC} -c vector.c -o vector.o ${CFLAGS}
tests: tests.o vector.o 
	${CC} vector.o tests.o -o tests ${CFLAGS}
clean:
	rm -rf *.o tests
