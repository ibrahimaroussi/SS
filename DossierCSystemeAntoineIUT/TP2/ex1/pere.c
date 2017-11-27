#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	
int var,signal;


var = fork();
if(var==0){
	sleep(30);
	printf("\nJE SUIS LE FILS - %d - %d\n",getpid(),getppid());
}
else if(var==-1){
	printf("\nERREUR\n");
}
else{
	//sleep(60);
	wait(&signal);
	if(WIFEXITED(signal)){
		printf("FIN DU FILS OK\n");
	}
	else if(WIFSIGNALED(signal)){
		printf("FIN CAUSEE PAR : %d\n",WTERMSIG(signal));
	}
	printf("JE SUIS LE PERE - %d\n",getpid());
}

exit(2);
}
