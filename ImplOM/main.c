#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[])
{

    if(strcmp(argv[1],"-h") == 0){
        printf("ProgramPath <Number of process> <IP> <Leader (1 or 0)> <Traitor (1 or 0)>\n");
    }else{
        //Acquisition du nombre de processus
        int nbr=atoi(argv[1]);
        printf("Le nombre de process est : %d \n",nbr);

        //Acquisition de l'adresse IP
        printf("L'adresse IP est : %s\n",argv[2]);
        //Leader ?

        if(atoi(argv[3])==0){
            printf("You are not a leader\n");
        }else{
            printf("You are a leader\n");
        }

        //Traitre ?
        if(atoi(argv[4])==0){
            printf("You are not a traitor\n");
        }else{
            printf("You are a traitor\n");
        }

    }

    printf("Bien reçu !\n");
    return 0;
}
