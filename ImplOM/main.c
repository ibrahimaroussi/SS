#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, char * argv[])
{
    verifyArgs(argv);

    //Acquisition du nombre de processus
    int nbr=atoi(argv[1]);
    printf("Le nombre de process est : %d \n",nbr);

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
        printf("You are not a traitor\n");
    }
    else
    {
        printf("You are a traitor\n");
    }

    //Init Tab IP
    printf("test avant \n");
    char * tab_IP[nbr];
    tab_IP[0]="coucou";
    printf("le premier element du tableau est : %s \n",tab_IP[0]);
    //Generation d'un tableau contenant toutes les adresses IP
    //generateTab(nbr,argv[2],tab_IP);



    printf("Bien reçu !\n");
    return 0;
}


///////////////////////////////


void generateTab(int taille, char * ip, char ** newTab){

newTab[0]="coucou";
printf("dans la fonction : %s\n",newTab[0]);
}

void verifyArgs(char * tab[]){

    if(strcmp(tab[1],"-h") == 0){
        printf("main.o <Number of process> <IP> <Leader (1 or 0)> <Traitor (1 or 0)>\n");
        exit(EXIT_SUCCESS);
    }else{
        if(tab[4]==NULL){
            printf("Il n'y a pas assez d'argument, pour plus d'information utiliser '-h'.\n");
            exit(EXIT_FAILURE);
        }else if(!(tab[5]==NULL)){
            printf("Il n'y a trop d'argument, pour plus d'information utiliser '-h'.\n");
            exit(EXIT_FAILURE);
        }else if(!(IsValidIp(tab[2])==1)){
            printf("L'adresse Ip n'est pas valide\n");
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
