#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	
int v,var,signal;


printf("\nDEBUT GPERE - %d\n",getpid());

var = fork();
if(var==0){
	printf("\nFILS/PERE - %d - PPID : %d\n",getpid(),getppid());
	v = fork();
	if(v==0){
		printf("PETIT-FILS - PID : %d - PPID : %d\n",getpid(),getppid());
	}
	else if(v==-1){
		printf("Erreur");
	}
	else{
		wait(&signal);
		printf("FIN FILS/PERE\n");
	}
}
else if(var==-1){
	printf("\nERREUR\n");
}
else{
	wait(&signal);
	printf("FIN GPERE - %d\n",getpid());
}


return EXIT_SUCCESS;
}
