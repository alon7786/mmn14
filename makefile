assembler: assembler.c assembler.h clist.c clist.h parse.c parse.h directives.c directives.h
	gcc -g -ansi -Wall -pedantic assembler.c clist.c parse.c directives.c -o assembler

clear:
	rm assembler