#include <unistd.h>

#include "../utils_v1.h"

void child1(void * pipefd, void * cmd1){
    int *pipeFd = pipefd;
    char *argv1 = cmd1;

    sclose(pipeFd[0]);
    int res = dup2(pipeFd[1],1);
    checkNeg(res, "Child1 dup2 failed\n");

    execlp(argv1,argv1,NULL);
    perror("Exec 1 failed");
}

void child2(void * pipefd, void * cmd1){
    int *pipeFd = pipefd;
    char **argv1 = cmd1;

    sclose(pipeFd[1]);
    int res = dup2(pipeFd[0],0);
    checkNeg(res, "Child2 dup2 failed\n");

    execvp(argv1[0],argv1);
    perror("Exec 2 failed");

}

int main(int argc, char ** argv){
    int pipefd[2];
    spipe(pipefd);

    fork_and_run2(child1,pipefd,argv[1]);
    //ici on mets & car on a envie d'avoir
    //l'adresse de l'élément pour pouvoir parcourir le tableau
    fork_and_run2(child2,pipefd,&argv[2]);

    sclose(pipefd[0]);
    sclose(pipefd[1]);

    swait(NULL);
    swait(NULL);

}
