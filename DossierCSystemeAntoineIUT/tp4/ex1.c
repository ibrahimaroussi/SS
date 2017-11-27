#include <signal.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <sys/time.h>

#define TEMPO 1

int sigFlag; 
// variable globale qui permet de savoir si le processus est passé par la fonction ' reveil' 
// Positionné à 0 par le programme, la fonction réveil la mettra à 1 

void reveil( int sig , siginfo_t *siginfo, void *context) { 
	sigFlag=1; 
	// la fonction reveil ne fait que dire qu'on est passé par elle !
} 

int main( int argc, char *argv[] ) { 
	
	long long int count; // un compteur 
	
	struct sigaction mon_reveil;
	struct itimerval temps;
		
	mon_reveil.sa_sigaction= &reveil;
	mon_reveil.sa_flags= SA_SIGINFO ;
	
	sigaction(SIGALRM,&mon_reveil,NULL); // on déroute le signal SIGALRM vers la fonction reveil
	
	while(1){ // boucle infinie 
		sigFlag=0; // On n'est pas passé par le reveil
		getitimer(ITIMER_REAL,&temps); // man getitimer
		temps.it_value.tv_usec=+500000;
		temps.it_value.tv_sec=+1;
		setitimer(ITIMER_REAL,&temps,NULL);
		// on arme le réveil à une seconde : Le système enverra un signal SIGALRM après TEMPO secondes
		
		for(count=0; sigFlag==0; count++ ){
			// on compte et on regarde si on est passé par la fonction 'reveil'
			// il n'y a rien dans le corps de la boucle 
		} 

		printf("pid : %d - compteur :  %lld\n",getpid(),count); // le type de count est un très long entier (d'où le %lld)
	} 

	return EXIT_SUCCESS; 
}
