CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

ALL= pipe

all: $(ALL) 

pipe: pipe.o utils_v1.o
	gcc $(CFLAGS) -o pipe pipe.o utils_v1.o

pipe.o: pipe.c ../utils_v1.h
	gcc $(CFLAGS) -c pipe.c
	
utils_v1.o: ../utils_v1.c ../utils_v1.h
	gcc $(CFLAGS) -c ../utils_v1.c 

# for dev purpose
clear:
	clear

clean:
	rm -f *.o
	rm -f $(ALL)

dev: clear all
	valgrind ./pipe ls grep "\.c$$"