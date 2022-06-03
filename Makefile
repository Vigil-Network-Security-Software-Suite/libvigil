all: libvigil clean
CC=gcc
CFLAGS=-Wall
decode.o:
	$(CC) $(CFLAGS) -c src/decode.c
utils.o:
	$(CC) $(CFLAGS) -c src/utils.c -fPIC

eth_decode.o:
	$(CC) $(CFLAGS) -c src/eth_decode.c

libvigil: decode.o utils.o eth_decode.o
	$(CC) $(CFLAGS) -o libvigil.so   -shared $^


clean:
	rm *.o