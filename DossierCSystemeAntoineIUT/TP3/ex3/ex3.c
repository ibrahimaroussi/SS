#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
/*

La fonction signal est définie dans signal.h comme suit 
typedef void(*sighandler_t)(int); c'est un type fonction
sighandler_t signal(int signum, sighandler_t handler); // le 2° argument est de type fonction

*/

//La fonction attraper respecte le type sighandler_t défini dans signal.h
void attraper(int sig){
	printf("J'ai attrapé ton CTRL+C\n");
}
int main(void){
	int count;
	if(signal(SIGINT,attraper)==SIG_ERR){
		perror("Attraper");
		exit(1);
	}

	for(count=1;count<=100;count++){
		printf("PID = %d et compteur = %d \n",getpid(),count);
		sleep(1);
	}
return 0;
}
