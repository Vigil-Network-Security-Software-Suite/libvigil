all: libvigil clean
CC=gcc
CFLAGS=-Wall
decode.o:
	$(CC $(CFLAGS) -c decode.c

libvigil: decode.o
	$(CC) $(CFLAGS) -o libvigil.o -shared $^


clean:
	rm *.o