#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "../utils_v1.h"

int main () {
    int a = 5;
    pid_t childPid = sfork();
    printf("pid de l'enfant : %d \n",childPid);
    if (childPid!=0){
        int b = a*5;
        printf("a pere: %d \n", a);
        printf("b pere: %d \n", b);
    }
    else {
        int b = a *2;
        printf("a : %d \n", a);
        printf("b : %d \n", b);
    }
}