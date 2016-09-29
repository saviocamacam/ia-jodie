all:
	gcc -c puzzle8.c
	gcc main.c puzzle8.o
	./a.out
