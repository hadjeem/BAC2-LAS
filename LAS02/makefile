CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS= ex2.a.a

ALL: $(PROGS)

ex2.a.a: ex2.a.a.o utils_v1.o
	gcc $(CFLAGS) -o ex2.a.a ex2.a.a.o utils_v1.o

ex2.a.a.o: ex2.a.a.c ../utils_v1.c
	gcc $(CFLAGS) -c ex2.a.a.c
    
utils_v1.o: ../utils_v1.h ../utils_v1.c
	gcc $(CFLAGS) -c ../utils_v1.c

clean:
	rm -f *.o
	rm -f $(PROGS)
