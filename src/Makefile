tokenize: tokenizer.o uimain.o

	gcc -o tokenize tokenizer.o uimain.o


tokenizer.o: tokenizer.h tokenizer.c

uimain.o: uimain.c

run:
	./tokenize

clean:
	rm -f *.o tokenize
