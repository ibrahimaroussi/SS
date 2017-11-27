#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	
int var,signal;


printf("\nDEBUT PERE\n");

var = fork();
if(var==0){
	printf("\nFILS\n");
}
else if(var==-1){
	printf("\nERREUR\n");
}
else{
	printf("FIN PERE\n");
	wait(&signal);
}


return EXIT_SUCCESS;
}
