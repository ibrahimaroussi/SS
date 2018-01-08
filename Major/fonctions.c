#include <stdio.h>


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