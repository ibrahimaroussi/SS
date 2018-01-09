#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Communication/fonctionsComm.h"
#include <net/if.h>
#include <net/route.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include "fonctions.h"

/*
 --------------------
 Algorithme de consensus
 
 
 
 --------------------
 */
int OM(int m,char * leader,int val, char ** listeProc,char * addrLocale){
    int tab[25];
    int index=0;
    struct hostent *serveur_host;
    if(m>0){
        if(strcmp(leader,addrLocale)){
            char * message;
            message=malloc(sizeof(leader)*2);
            sprintf(message, "%d", val); 
            strcat(message,":");
            strcat(message,addrLocale);
            for(int i=0;i<(sizeof(listeProc)/8);i++){
                if(strcmp(listeProc[i],leader)){
                    delElement(listeProc,leader);
                }else{
                    envoi(serveur_host,message,addrLocale,10000);
                }
            }
            return val;
        }else{
            char * reponse;
            int port = 10100;
            //Timeout d'environ 1 minute, ceci est dû au temps de lancement que l'on aura en réseau
            int timeout; 
            timeout= 60000;
            reponse= reception(port,timeout);
            if(reponse!=NULL){
                strtok(reponse,":");
                tab[index]=atoi(reponse);
                index++;
                strtok(reponse,":");
                delElement(listeProc,reponse);
                //role de leader
                int newValue;
                newValue=OM(m-1,addrLocale,tab[index-1],listeProc,addrLocale);
                tab[index]=newValue;
                index++;
                //TODO Fork
                int valueFork;
                valueFork=OM(m-1,leader,val,listeProc,addrLocale);
                tab[index]=valueFork;
                index++;
                
            }
            return rendreMajoritaire(tab,(index+1));              
        }
    }else{
        if(strcmp(leader,addrLocale)){
            char * message;
            message=malloc(sizeof(leader)*2);
            sprintf(message, "%d", val); 
            strcat(message,":");
            strcat(message,addrLocale);
            for(int i=0;i<(sizeof(listeProc)/8);i++){
                if(strcmp(listeProc[i],leader)){
                    delElement(listeProc,leader);
                }else{
                    envoi(serveur_host,message,addrLocale,10000);
                }
            }
            return val;
        }else{
            char * reponse;
            int port = 10100;
            //Timeout d'environ 1 minute, ceci est dû au temps de lancement que l'on aura en réseau
            int timeout = 60000;
            reponse = reception(port,timeout);
            if(reponse!=NULL){
                strtok(reponse,":");
                tab[index]=atoi(reponse);
                index++;
                strtok(reponse,":");
                delElement(listeProc,reponse);                              
            }
            return rendreMajoritaire(tab,(index+1));
        }
        
    }
}

int rendreMajoritaire(int t[], int N){

                int vmax  ;
                int c = 0 ;

                for(int i=0; i < N ; i++){

                     int in = 0 ;
                        for(int j=0; j < N ; j++){
                       //          printf("i = %d ET j = %d \n \t", i,j);
                            if (t[i] == t[j]){
                            in=in+1;
                      //      printf("i = %d j= %d in = %d ET  c = %d ET vmax = %d \n", i,j , in, c ,vmax) ;

                                if(in>c){
                                   //     printf("in > c donc c recoit = %d ", c)
                                c=in ;
                                vmax = t[i] ;
                                }
                            }
                        }
                }

printf("la valeur majoritaire est : %d", vmax);
     return vmax ;
}

void afficherTab(char ** tab,int taille){
    for(int i=0;i<taille-1;i++){
        printf("%s\n",tab[i]);
    }
}

 void getIpAddr(char IPAddr[16]){
    
    int socketd;
    struct ifreq ifr;
 
    socketd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketd <= 0)
    {
        perror("socket");
    }
     
    IPAddr[0]=0;

    strcpy(ifr.ifr_name, "en0");
 
    if (0 == ioctl(socketd, SIOCGIFADDR, &ifr))
    {   
        strcpy(IPAddr,(char*) inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
    }
    close(socketd);

}
    
void delElement(char ** tab,char * element);
