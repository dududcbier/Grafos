CC=gcc
CFLAGS=-pedantic -Wall

all: RNG listTest matrixTest

RNG: DIGRAPHlists.o RNG.o
	$(CC) -o RNG RNG.o DIGRAPHlists.o

listTest: DIGRAPHlists.o listTest.o
	$(CC) -o listTest listTest.o DIGRAPHlists.o

matrixTest: DIGRAPHmatrix.o matrixTest.o
	$(CC) -o matrixTest matrixTest.o DIGRAPHmatrix.o

RNG.o: DIGRAPHlists.o RNG.c
	$(CC) $(CFLAGS) -c RNG.c

listTest.o: listTest.c DIGRAPHlists.h
	$(CC) $(CFLAGS) -c listTest.c

DIGRAPHlists.o: DIGRAPHlists.c DIGRAPHlists.h
	$(CC) $(CFLAGS) -c DIGRAPHlists.c

matrixTest.o: matrixTest.c DIGRAPHmatrix.h
	$(CC) $(CFLAGS) -c matrixTest.c

DIGRAPHmatrix.o: DIGRAPHmatrix.c DIGRAPHmatrix.h
	$(CC) $(CFLAGS) -c DIGRAPHmatrix.c

clean:
	rm *o listTest matrixTest RNG
