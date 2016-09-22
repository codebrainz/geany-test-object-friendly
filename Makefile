CFLAGS = -g -std=c99 -pedantic -Wall -Wextra -fPIC $(shell pkg-config --cflags geany)
LDFLAGS = $(shell pkg-config --libs geany)

all: helloplugin.so

clean:
	$(RM) *.o *.so

helloplugin.so: helloplugin.o plugin.c
	$(CC) -shared $(CFLAGS) -o $@ $^ $(LDFLAGS)

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: all clean
