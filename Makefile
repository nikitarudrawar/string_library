project: test.o string.o
	cc string.o test.o -o project
string.o: string.c string.h
	cc -c string.c -Wall
test.o: test.c string.h
	cc -c test.c -Wall
