CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS= ex1

ALL: $(PROGS)

ex1: ex1.o 
	gcc $(CFLAGS) -o ex1 ex1.o

ex1.o: ex1.c
	gcc $(CFLAGS) -c ex1.c
  
    
utils_v1.o: ../../utils_v1.h ../../utils_v1.c
	gcc $(CFLAGS) -c ../../utils_v1.c

clean:
	rm -f *.o
	rm -f $(PROGS)
	rm -f *.bin
