                 /* fichier semposix.c */

/*     Implementation des semaphores de Dijkstra a l'aide des sémaphores
 *     de POSIX
 *  Effectuez l'édition des liens avec l'option    -pthread.

 *     sem_create(): creation et initialisation d'un sémaphore 
 * 		sem_ident() : récupérer l'identité système d'un sémaphore
 *     P()         : realisation de l'operation P (puis-je) sur un semaphore
 *     V()         : realisation de l'operation V (vas-y) sur un semaphore
 *     sem_delete() : suppression d'un semaphore
 */ 
#include <errno.h>
 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include <fcntl.h>           /* Pour les constantes O_* */
#include <sys/stat.h>        /* Pour les constantes des modes */
#include <semaphore.h>


sem_t * sem_create(const char *path, int initval)  /* creation d'un semaphore relie a un nom */
                       	              /* de valeur initiale initval          */
     //attention : path doit être un nom de fichier qui existe dans le répertoire  
	 
{
     sem_t *semid ;
     // La description de la fonction smctl oblige de definir cette structure "union"
	 semid = sem_open(name, O_CREAT, (S_IRWXU | S_IRWXG)  , initval); // attention : si le sémaphore existe alors il n'est pas réinitialisé à initval.
     return(semid) ;
}

sem_t *sem_ident(const char *name)
{
	 sem_t *semid ;
     // La description de la fonction smctl oblige de definir cette structure "union"
	 semid = sem_open(name, O_RDWR ); 
     return(semid) ;
}

void P(sem_t *sem) {
        sem_wait(sem);
}

void V(sem_t *sem) {
	sem_post(sem);
}

void sem_delete(sem_t *sem) {
     // int sem_unlink(const char *name);
     sem_unlink(getlogin());
	 sem_close(sem);
}
