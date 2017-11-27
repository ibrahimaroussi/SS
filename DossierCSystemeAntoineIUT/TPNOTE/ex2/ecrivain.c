#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 100

typedef char mot[MAX];

int main(int argc, char *argv[]){

mot tube=argv[1];

int ecrire;
float reel=0.0;

ecrire = open(var,O_WRONLY);
while(reel>=0){
    printf("\nEntrer un nombre : ");
    scanf("%f",&reel);
    write(ecrire,reel,MAX);
}
exit(2);
}


