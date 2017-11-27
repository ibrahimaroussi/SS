                 /* fichier dijkstra.h */
#ifndef  _DIJKSTRA_H_
#define  _DIJKSTRA_H_
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>

int sem_ident(char * NomSem ) ;
int sem_create(char * NomSem ,int initval) ;
void P(int semid) ; 
void V(int semid) ;
void sem_delete(int semid);
#endif

