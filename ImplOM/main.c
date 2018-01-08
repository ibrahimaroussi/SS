#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

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


    //Leader ?
    if(atoi(argv[3])==0)
    {
        printf("You are not a leader\n");
    }
    else
    {
        printf("You are a leader\n");
    }

    //Traitre ?
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

void verifyArgs(char * tab[]){
    
    char * ip_tmp=NULL;
    ip_tmp=malloc(sizeof(char)*15);

    strcpy(ip_tmp,tab[2]);
    char * ip_split= strtok(ip_tmp,".");
    ip_split= strtok(NULL,".");
    ip_split= strtok(NULL,".");
    ip_split= strtok(NULL,".");

    if(strcmp(tab[1],"-h") == 0){
        printf("main.o <Number of process> <IP> <Leader (1 or 0)> <Traitor (1 or 0)> <Val seulement si vous êtes leader>\n");
        printf("Attention la valeur de la partie poste de l'adresse ip ne doit pas exceder celle du nombre de machine\n");
        printf("Mauvais exemple : main.o 5 192.168.1.6 1 0 15\n");
        printf("Bon exemple : main.o 5 192.168.1.5 1 0 15\n");
        printf("Ne rentrez une valeur que si vous êtes un leader\n");
        exit(EXIT_SUCCESS);
    }else{
        if(tab[4]==NULL){
            printf("Il n'y a pas assez d'argument, pour plus d'information utiliser '-h'.\n");
            exit(EXIT_FAILURE);
        }else if(!(tab[6]==NULL)){
            printf("Il y a trop d'argument, pour plus d'information utiliser '-h'.\n");
            exit(EXIT_FAILURE);
        }else if((!(tab[5]==NULL))&(atoi(tab[3])!=1)){
            printf("Il y a trop d'argument et vous n'êtes pas leader, pour plus d'information utiliser '-h'.\n");
            exit(EXIT_FAILURE);
        }else if(!(IsValidIp(tab[2])==1)){
            printf("L'adresse Ip n'est pas valide\n");
            exit(EXIT_FAILURE);
        }else if(atoi(ip_split)>atoi(tab[1])){
            printf("N'oubliez pas, la partie hote de l'adresse ip ne doit pas être supérieure au nombre de machine.");
            exit(EXIT_FAILURE);
        }
    }

}

//Verification validité adresse ip
//Fonction trouvee sur OpenclassRoom : https://openclassrooms.com/forum/sujet/saisir-une-adresse-ip-en-c-controle-de-la-saisie
int IsValidIp(char* szIP)
{
    int isValid;
    int i;
    int byte;
    int iIpLen;
    char dotCount;
    
    isValid = 1;
    iIpLen = strlen(szIP);
    dotCount = 0;

    // Si on nous donne une chaine de caractère vide ou bien que la chaine dépasse les 15 caractères ce n'est pas une bonne IP
    if(iIpLen == 0 || iIpLen > 15)
    {
        isValid = 0;
    }
    else
    {
        /* On récupère le premier octet */
        byte = atoi(szIP);

        /* S'il est plus grand que 255 alors ce n'est pas une IP valide */
        if(byte > 255)
        {
            isValid = 0;
        }

        /* on parcours la chaine */
        for(i = 0; i < iIpLen && isValid == 1; i++)
        {
            /* on check si on nous donne bien seulement des chiffres ou le point */
            if(!(szIP[i] >= '0' && szIP[i] <= '9') && szIP[i] != '.')
            {
                isValid = 0;
            }

            /* on compte le nb de point */
            if(szIP[i] == '.')
            {
                dotCount ++;
                /* puis on check si l'octet que l'on récupère est valide */
                byte = atoi(&szIP[i+1]);
                if(byte > 255)
                {
                    isValid = 0;
                }
            }
        }
        /* s'il n'y a pas trois points dans l'ip alors ce n'est pas une ip valide */
        if(dotCount != 3)
        {
            isValid = 0;
        }

    }
    return isValid;
}


void afficherTab(char ** tab,int taille){
    for(int i=0;i<taille-1;i++){
        printf("%s\n",tab[i]);
    }
}