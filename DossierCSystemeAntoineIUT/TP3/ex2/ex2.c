#include <stdio.h>
#include <stdlib.h>
typedef float (*fonction)(float);
// déclaration d'un type fonction
float lafonction(float argument){
printf(" je suis la vraie fonction \n");
return argument/2.0;
}
int main(){
fonction variable_fonction;
float test;
float arg=3.14;
variable_fonction=lafonction;
printf("lancement d'une fonction\n");
test=(variable_fonction)(arg);
printf("la fonction a retourné %d\n",test);
return EXIT_SUCCESS;
}
