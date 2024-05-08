#include <stdio.h>

int main (int argc,char ** argv){
    int a = 5;
    int *p = &a;
    printf("%p \n",(void *)p);
}