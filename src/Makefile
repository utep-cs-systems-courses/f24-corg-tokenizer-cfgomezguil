CFLAGS=-g



all: tokenize



uimain.o: uimain.c




tokenize: uimain.o

	cc -o $@ $^ $(CFLAGS)

clean:

	rm -f *.o tokenize



run:tokenize

	./tokenize
