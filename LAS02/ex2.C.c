#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "../utils_v1.h"

#define MAX_CHAR 21
#define BUFSIZE 256

static void exec_ls(void *arg){
  char *scriptName = arg;
  printf("\nls -l %s:\n", scriptName);
  //pour savoir ou se trouve ls on peut faire "whiwh ls" dans le terminal
  //il faut toujours terminer par NULL
  sexecl("/bin/ls", "ls", "-l", scriptName, NULL);
}

static void exec_cat(void *arg){
  char *scriptName = arg;
  printf("\n cat %s:\n", scriptName);
  sexecl("/bin/cat", "cat", scriptName, NULL);
}

int main(int argc, char ** argv){
    printf("entrez un nom de script de max %d charactere\n",MAX_CHAR-1);
    char bufRd[MAX_CHAR];
    int nbrChar = sread(0,bufRd,MAX_CHAR);
    //Attention ne pas oublier de remplace le /n par un /0 pour pouvoir utiliser %s
    //read ne mets pas le /0 !!
    bufRd[nbrChar-1]=0;

    int fd = sopen(bufRd, O_WRONLY | O_CREAT | O_TRUNC, 0700);

    int childPid = fork_and_run1(exec_ls, bufRd);
    swaitpid(childPid,NULL,0);

    /* Ecriture du shebang dans le script */
    char* shebang = "#!/bin/bash\n";
    int szShebang = strlen(shebang);
    nwrite(fd, shebang, szShebang);

    /* Saisie du contenu du script */
    printf("\nSaisie du contenu de votre script (ctrl-d pour terminer).\n");
    char readBuffer[BUFSIZE];    
    int nbrRead;
    while ((nbrRead = sread(0, readBuffer, BUFSIZE)) != 0) {
        nwrite(fd, readBuffer, nbrRead);
    }

    /* Libérer les ressources ! */
    sclose(fd);
    
    int c2 = fork_and_run1(exec_cat, bufRd);
    swaitpid(c2, NULL, 0);

    /* Exécution du script enregistré */
    printf("\n./%s:\n", bufRd);
    sexecl(bufRd, bufRd, NULL);
}