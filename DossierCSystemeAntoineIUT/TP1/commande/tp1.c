#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char chaine[51];

int main(){

  chaine commande;
  chaine stop = "logout";
  int res;
  int ret;
  printf("Entrer votre commande : ");
  scanf("%s",commande);
  while(strcmp(stop,commande)!=0){
    res = system(commande);
    if(res==(-1)){
      ret = 0;
    }
    else{
      ret = 1;
    }  
    printf("Entrer votre commande : ");
    scanf("%s",commande);
  }
  return ret;
}

