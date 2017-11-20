/** ********************************************************************* 
 * @file pid1.c
 * @brief programme qui partage une mémoire 
 * En utilisant  les fonctions POSIX
 * 
 * Author: Prof Systeme 2° année DUT Informatique 
 * 
 *********************************************************************
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <errno.h>  /* pour l'affichage des erreurs */
#include <sys/types.h>
#include <signal.h>

#include <sys/mman.h>        /* pour le mapage de la mémoire */
#include <sys/stat.h>        /* pour les constantes mod */
#include <fcntl.h>           /* pour les constantes O_XXXX */

/*********************************************************************** 
*  \fn  void handler (int sig, siginfo_t *siginfo, void *context)
* @brief : fonction handler qui interceptera un signal
* \param  sig numéro du signal
* \param  siginfo information suplémentaire sur le signal reçu
* \param  context  du processus lors de la reception du signal
*/
void handler (int sig, siginfo_t *siginfo, void *context) {
  printf("\n c'est la fin de :  %d\n", getpid() );
  printf ("J'ai reçu un signal du processus  : %ld, lancé par l'utilisateur %ld\n",
                        (long)siginfo->si_pid, (long)siginfo->si_uid);
}

int main (void) {

	int memoireID,*memoire_partage, pid;
	struct sigaction new_action ;
	int taille_memoire = (1 * sizeof(int));

	  printf("\n Je suis le processus :  %d\n", getpid() );

	// Ouvertur du pseudo fichier avec le login comme nom
	// Il sera ouvert en création et lecture/écriture et autorisation en RWX pour l'utilisateur et le groupe
	memoireID = shm_open(getlogin(),(O_CREAT|O_RDWR),(S_IRWXU | S_IRWXG));
	if (memoireID < 0) {
	        perror("de shm_open()");
        	exit(EXIT_FAILURE);
    	}

	ftruncate(memoireID, taille_memoire);   // je n'ai besoin exactement de taille_memoire octets
	// projection de la mémoire partagée dans l'espace du processus (fonction mmap)
	memoire_partage = (int *)mmap(NULL, taille_memoire, (PROT_READ | PROT_WRITE), MAP_SHARED, memoireID, 0);
	// je débute la projection au début (NULL), en prenant 'taille_memoire' octets
	// Cette zone aura les protections "autorisation en lecture et écriture", elle est "partagée" et identifier par "memoireID".
	if (memoire_partage == NULL) {  // mmap peut échouer 
	        perror("dans mmap()");
        	exit(EXIT_FAILURE);
    }
    /* copie du PID de ce processus dans la mémoire partégée */
    pid = getpid();
    *memoire_partage = pid; // ou plus simplement  *memoire_partage =getpid();
  /* positionnement du handler pour le signal SIGUSER1 */
	new_action.sa_sigaction = &handler; // nom de la fonction
	sigemptyset (&new_action.sa_mask);           // ne rien masqué
	new_action.sa_flags = SA_SIGINFO;	 // type de handler 
	sigaction (SIGUSR1, &new_action, NULL); // association du signal et du handler
  pause(); // simulation d'un travail très-très long ....
  
/* retour de la fonction handler */
  printf("On m'a reveillé \n");
  return EXIT_SUCCESS;
}

