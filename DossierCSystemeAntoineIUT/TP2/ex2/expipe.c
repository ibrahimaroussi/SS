#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 10

int main(){
	
char mot[1];

int var,signal;

int pipefd[2];
pipe(pipefd);
char val[10];
var = fork();
if(var==0){
	close(pipefd[1]);
	read(pipefd[0],mot,10);	
	printf("\nJE SUIS LE FILS - PID : %d -  PPID :%d\n",getpid(),getppid());
        printf("\nJ'ai recu : %s\n\n",mot);	
}
else if(var==-1){
	printf("\nERREUR\n");
}
else{
	printf("\n\nPERE PID : %d\n",getpid());
	close(pipefd[0]);
	printf("Entrer une valeur à transmettre au fils : ");
	scanf("%s",val);
	write(pipefd[1],val,10);
	wait(&signal);
	if(WIFEXITED(signal)){
		printf("FIN DU FILS OK\n");
	}
	else if(WIFSIGNALED(signal)){
		printf("FIN CAUSEE PAR : %d\n",WTERMSIG(signal));
	}
}

exit(2);
}
