                 /* fichier dijkstra.h */

/*     Implementation des semaphores de Dijkstra a l'aide des semaphores
 *     de SystemV.
 *
 *     sem_create(): creation et initialisation d'un semaphore 
 * 		sem_ident() : récupere l'identité système d'un sémaphore
 *     P()         : realisation de l'operation P (puis-je) sur un semaphore
 *     V()         : realisation de l'operation V (vas-y) sur un semaphore
 *     sem_delete() : suppression d'un semaphore
 */ 
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>


int sem_create(char * NomSem , int initval)  /* creation d'un semaphore relie a cle */
											/* de valeur initiale initval          */								
	 
{
     int semid ;
     key_t clef;
     // La description de la fonction smctl oblige de definir cette structure "union"
     union semun {
               int              val;    /* Valeur pour SETVAL */
               struct semid_ds *buf;    /* Tampon pour IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Tableau pour GETALL, SETALL */
               struct seminfo  *__buf;  /* Tampon pour IPC_INFO
                                           (spécifique à Linux) */
           } arg_ctl ;
	
	
	 clef=ftok(NomSem,getuid());

	if(clef == -1) { 
        perror("clef pas bonne");
        exit(EXIT_FAILURE);
        }
	
     semid = semget(clef,1,IPC_CREAT|IPC_EXCL|0666) ; //  création de '1' sémaphore  car on a IPC_CREAT et IPC_EXCL en même temps 
     if (semid == -1) {  // si le sémaphore exist déjà alors : 
	  semid = semget(clef,1, 0666) ; // on le prendre 
	  if (semid == -1) {
               perror("Erreur semget()") ;
               exit(1) ;
          }
     }
     if(initval >= 0) {
		arg_ctl.val = initval ;
		if (semctl(semid,0,SETVAL,arg_ctl) == -1) {
			perror("Erreur initialisation semaphore") ;
			exit(1) ;
		}
	}
     return(semid) ;
}


int sem_ident(char * NomSem) { // si le séémaphore est créer alors on peut avoir son identité 
	return  semget(ftok(NomSem,getuid()),1, 0666) ; 
	/*
	 * A l'identique on peut avoir 
	 * return sem_create(NomSem,cle, -1);
	 * **********************************
	 */
}

void P(int semid) {
     struct sembuf sempar ;

     sempar.sem_num = 0 ;	// 1° champs
     sempar.sem_op = -1 ;	// opération de soustraction de 1 
     sempar.sem_flg = 0 ;	
     if (semop(semid, &sempar, 1) == -1)
          perror("Erreur operation P") ;
}

void V(int semid) {
     struct sembuf sempar ;

     sempar.sem_num = 0 ; // 1° champs
     sempar.sem_op =  1 ; // opération d'addition de 1
     sempar.sem_flg = 0 ;
     if (semop(semid, &sempar, 1) == -1)
          perror("Erreur operation V") ;
}

void sem_delete(int semid) {
     if (semctl(semid,0,IPC_RMID,0) == -1) {
          perror("Erreur dans destruction semaphore") ;
     }
}
