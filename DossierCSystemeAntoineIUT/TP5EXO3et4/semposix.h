#ifndef  _DIJKSTRA_H_
#define  _DIJKSTRA_H_
/*     Implementation des semaphores de Dijkstra a l'aide des semaphores
 *     de SystemV.
 *
 *     sem_create(): creation et initialisation d'un semaphore 
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


sem_t * sem_create(const char *name, int initval);  /* creation d'un semaphore relie a un nom */
                       	              /* de valeur initiale initval          */

sem_t *sem_ident(const char *name);

void P(sem_t *sem);

void V(sem_t *sem) ;

void sem_delete(sem_t *sem);

#endif
