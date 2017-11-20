/*LECTEUR*/
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define LONGUEUR_SEGMENT 512 

int main(int argc, char *argv[]){

	key_t clef;
	int memoirePartagee;
	char *Partage;
	
	clef=ftok(getlogin(),getuid());
	if(clef==-1){
		perror("Erreur de cle");
		exit(EXIT_FAILURE);
	}

	if((memoirePartagee=shmget(clef,LONGUEUR_SEGMENT, IPC_CREAT|0666))==-1){
		perror("Impossible de creer le segment de memoire partagee");
		exit(EXIT_FAILURE);
	}	
	
	Partage=shmat(memoirePartagee,NULL,0);
	if(Partage==(char*)-1){
		perror("Impossible d'attacher la mémoire");
		exit(EXIT_FAILURE);
	}
	printf("======>%s\n",Partage);
	shmdt(Partage);
	printf("FIN");
	return EXIT_SUCCESS;
}
