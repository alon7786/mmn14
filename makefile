assembler: assembler.c assembler.h utils.h parse.o directives.o clist.o
	gcc -g -ansi -Wall -pedantic assembler.c parse.o directives.o clist.o -o assembler

parse.o: parse.c parse.h utils.h directives.o
	gcc -c -ansi -Wall -pedantic parse.c -o parse.o

directives.o: directives.c directives.h utils.h clist.o
	gcc -c -ansi -Wall -pedantic directives.c clist.o -o directives.o

clist.o: clist.c clist.h
	gcc -c -ansi -Wall -pedantic clist.c -o clist.o

clear:
	rm assembler