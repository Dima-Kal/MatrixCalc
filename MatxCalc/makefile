
run : main.o mat.o
	gcc main.o mat.o -o run

main.o : main.c mat.h
	gcc -c -g -Wall -ansi -pedantic main.c

mat.o: mat.c mat.h
	gcc -c -g -Wall -ansi -pedantic mat.c
