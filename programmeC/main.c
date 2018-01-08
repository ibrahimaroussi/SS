#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "../Communication/fonctionsComm.h"
#include "./checkArgs/verifyArgs.h"
#include "../Major/fonctions.h"

int main(int argc, char * argv[])
{
    verifyArgs(argv);
    
    //Acquisition de la valeur à transmettre
    int val=atoi(argv[5]);
    printf("La valeur est : %d \n",val);

    //Acquisition du nombre de processus
    int nbr=atoi(argv[1]);
    printf("Le nombre de process est : %d \n",nbr);

    // Generation du nombre m de traitre : 
    int nbr_traitor=(nbr-1)/3;
    printf("le nombre m de traitre est : %d\n",nbr_traitor);
    
    //Acquisition de l'adresse IP
    printf("L'adresse IP est : %s\n",argv[2]);

    //Leader
    if(atoi(argv[3])==0)
    {
        printf("You are not a leader\n");
    }
    else
    {
        printf("You are a leader\n");
    }
    //Traitre 
    if(atoi(argv[4])==0)
    {
        printf("vous n'êtes pas un traitre\n");
    }
    else
    {
        printf("vous êtes un traitre\n");   
    }

    
    
    //Init Tab IP
    char * tab_IP[nbr-1];
    //Generation d'un tableau contenant toutes les adresses IP
    generateTab(nbr,argv[2],tab_IP);
    printf("-------------------------\n");
    printf("affichage du tableau d'adresse IP \n");
    printf("-------------------------\n");
    afficherTab(tab_IP,nbr);

    
    printf("Bien recu !\n");
    return 0;
}


///////////////////////////////


void generateTab(int taille, char * ip, char ** newTab){

char * ip_res=NULL;
ip_res=malloc(sizeof(char)*15);
char * ip_tmp=NULL;
ip_tmp=malloc(sizeof(char)*15);

strcpy(ip_tmp,ip);
char * ip_split= strtok(ip_tmp,".");


strcpy(ip_res,ip_split);
strcat(ip_res,".");

ip_split= strtok(NULL,".");
strcat(ip_res,ip_split);
strcat(ip_res,".");

ip_split= strtok(NULL,".");
strcat(ip_res,ip_split);
strcat(ip_res,".");

ip_split= strtok(NULL,".");

int indicVal=0;

for (int i=0;i<taille;i++){
    
    char * valeur=NULL;
    valeur=malloc(sizeof(char)*4);
    sprintf(valeur, "%d", (i+1)); 
    if(atoi(valeur)==atoi(ip_split)){
        indicVal=1;
    }else{
        char * ip_tmpFor=NULL;
        ip_tmpFor=malloc(sizeof(char)*15);
        strcpy(ip_tmpFor,ip_res);
        strcat(ip_tmpFor,valeur);
        
        if(indicVal==0){
            newTab[i]=ip_tmpFor;
        }else{
            newTab[i-1]=ip_tmpFor;
        }
        
    }
}

}
