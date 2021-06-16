CC=gcc
CFLAGS=-Isrc
DEPS= LCG.h

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CMJ: CMJ.o LCG.o 
	$(CC) -o CMJ CMJ.o LCG.o
