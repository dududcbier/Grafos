CC=gcc
CFLAGS=-pedantic -Wall

all: grafoDistancia

grafoDistancia: DIGRAPHlists.o grafoDistancia.o
	$(CC) -o grafoDistancia grafoDistancia.o DIGRAPHlists.o

grafoDistancia.o: DIGRAPHlists.o grafoDistancia.c grafoDistancia.h
	$(CC) $(CFLAGS) -c grafoDistancia.c

# list: DIGRAPHlists.o
# 	$(CC) -o list DIGRAPHlists.o 

DIGRAPHlists.o: DIGRAPHlists.c DIGRAPHlists.h
	$(CC) $(CFLAGS) -c DIGRAPHlists.c

# matrix: DIGRAPHmatrix.o
# 	$(CC) -o matrix DIGRAPHmatrix.o 

DIGRAPHmatrix.o: DIGRAPHmatrix.c DIGRAPHmatrix.h
	$(CC) $(CFLAGS) -c DIGRAPHmatrix.c

clean:
	rm *o list matrix grafoDistancia
