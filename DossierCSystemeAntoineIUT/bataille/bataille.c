#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

void joueur(int num,int tube[2]);
void transmettre(int tube[2],int nbjoueur, int tab[]);


int main(int argc, char *argv[]){

	int nbj = atoi(argv[1]);
	int t_fork[nbj];
	int i;
	int tabtubes[nbj][2];

	for(i=0;i<nbj;i++){
		pipe(tabtubes[i]);
		t_fork[i]=fork();
		if(t_fork[i]==0){
			joueur(i,tabtubes[i]);
		}
	}
	for(i=0;i<nbj;i++){
		transmettre(tabtubes[i],nbj,t_fork);	
	}

return EXIT_SUCCESS;
}

void joueur(int num,int tube[2]){
	
	int etat,i,nbj,pid,attaque;
	
	close(tube[1]);	
	read(tube[0],&nbj,sizeof(int));
	
	int tab[nbj];
	int liste[nbj];

	for(i=0;i<nbj;i++){
		liste[i]=0;
	}
	
	read(tube[0],tab,nbj*sizeof(int));
	
	attaque = rand()%5;
	pid = rand()%nbj;
	
	
	if(attaque==0){
		etat=kill(tab[pid],SIGINT);
		if(etat==-1){
			liste[pid]=1;
		}
	}
	else if(attaque==1){
		etat=kill(tab[pid],SIGQUIT);
	}
	else if(attaque==2){
		etat=kill(tab[pid],SIGTERM);
	}
	else if(attaque==3){
		etat=kill(tab[pid],SIGUSR1);
	}
	else{
		kill(tab[pid],SIGUSR2);
	}
	exit(0);
}

void transmettre(int tube[2],int nbjoueur,int tab[]){
	close(tube[0]);
	write(tube[1],&nbjoueur,sizeof(int));
	write(tube[1],tab,nbjoueur*sizeof(int));
	close(tube[1]);
}


