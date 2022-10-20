CC=cc
CFLAGS=-Wall

all: a.out

ssc.o: ssc.c ssc.h
	$(CC) $< -c

a.out: main.c ssc.o
	$(CC) $(CFLAGS) $^

clean:
	rm -f *.o a.out
