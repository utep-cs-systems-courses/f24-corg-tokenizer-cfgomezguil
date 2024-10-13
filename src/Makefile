tokenize: tokenizer.o uimain.o history.o

	gcc -o tokenize tokenizer.o uimain.o history.o

history.o: history.h history.c

tokenizer.o: tokenizer.h tokenizer.c

uimain.o: uimain.c

run:
	./tokenize

clean:
	rm -f *.o tokenize
