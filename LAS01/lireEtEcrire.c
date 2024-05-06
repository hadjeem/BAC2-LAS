#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#include "../utils_v1.h"

#define MAX 80

void checkUsage(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s file1 file2\n", argv[0]);
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char **argv){
    checkUsage(argc, argv);

    ssize_t nbr;
    char c;
    char bufRd[MAX+1];

    int fd, fd1, fd2;
    bool lnc = false;
    fd1 = sopen(argv[1],O_WRONLY | O_TRUNC | O_CREAT, 0644);
    fd2 = sopen(argv[2],O_WRONLY | O_TRUNC | O_CREAT, 0644);
    while((nbr= sread(0,bufRd,MAX+1))){
        if(bufRd[nbr-1]=='\n'){
            bufRd[nbr]='\0';
            if(isupper(bufRd[0]))
                fd=fd1;
            else if (islower(bufRd[0]))
                fd=fd2;
            else 
                lnc=true;
            if(!lnc)
                swrite(fd,bufRd,nbr);
        } else {
            while ((nbr=sread(0,&c,1)) && (c!='\n'));
        }
    }
    sclose(fd1);
    sclose(fd2);
}

/*
Pour c, qui est une variable simple de type char, vous utilisez l'opérateur
d'adresse & pour obtenir l'adresse mémoire où stocker le caractère
lu à chaque itération de la boucle. 

Pour bufRd, il s'agit d'un tableau de caractères, et en C, un tableau est déjà une
référence à sa propre adresse mémoire.
*/