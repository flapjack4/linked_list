CC=gcc
CFLAGS=-Wall -g

test: test.c linked_list.h linked_list.c
	$(CC) $(CFLAGS) -o test test.c linked_list.c

clean:
	rm -f *.o test
