CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS= ex1 lireEtEcrire

ALL: $(PROGS)

ex1: ex1.o 
	gcc $(CFLAGS) -o ex1 ex1.o

ex1.o: ex1.c
	gcc $(CFLAGS) -c ex1.c
  
lireEtEcrire: lireEtEcrire.o utils_v1.o
	gcc $(CFLAGS) -o lireEtEcrire lireEtEcrire.o utils_v1.o

lireEtEcrire.o: lireEtEcrire.c ../utils_v1.h
	gcc $(CFLAGS) -c lireEtEcrire.c
    
utils_v1.o: ../utils_v1.h ../utils_v1.c
	gcc $(CFLAGS) -c ../utils_v1.c

clean:
	rm -f *.o
	rm -f $(PROGS)
	rm -f *.bin
