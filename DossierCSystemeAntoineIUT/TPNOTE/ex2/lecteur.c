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

int ecrire,i;
float reel=0.0;
float somme=0.0;
float moyenne=0.0;

ecrire = open(var,O_RDONLY);
int i=0;
while(reel>=0){
    read(ecrire,reel,MAX);
    if(reel>=0){
        i++;
        somme=reel+somme;
        printf("\nValeur = %f\n",reel)
    }
    else{
        moyenne=somme/i;
        printf("\nMoyenne : %f\n",moyenne);
    }
}

exit(2);
}
