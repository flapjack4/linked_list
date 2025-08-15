CC=gcc
CFLAGS=-Wall -g
TARGET = liblinkedlist.so
SRC = linkedlist.c
HDR = linkedlist.h
PREFIX = /usr/local/

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -shared -o $@ $^

install: $(TARGET) $(HDR)
	sudo cp $(TARGET) $(PREFIX)/lib/
	sudo cp $(HDR) $(PREFIX)/include/
	sudo ldconfig

uninstall:
	sudo rm -f $(PREFIX)/lib/$(TARGET)
	sudo rm -f $(PREFIX)/include/$(HDR)
	sudo lsconfig

test: tests/test.c
	$(CC) $(CFLAGS) -o test tests/test.c -llinkedlist

clean:
	rm -f test
	rm -f $(TARGET)
