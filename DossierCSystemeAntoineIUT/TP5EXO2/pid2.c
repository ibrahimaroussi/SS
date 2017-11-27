/* PID 2 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

int main () {
    int memoire_ID,*memoire_partage, pid;
    int taille_memoire = (1 * sizeof(int));
     printf("\n 		Je suis le processus :  %d\n", getpid() );
    memoire_ID = shm_open(getlogin(),O_RDWR,(S_IRWXU | S_IRWXG));
    if(memoire_ID == -1){
	printf("open\n"); 
	exit(1);
    }
    memoire_partage = (int *)mmap(NULL, taille_memoire,(PROT_READ | PROT_WRITE), MAP_SHARED, memoire_ID, 0);
    if(*memoire_partage == -1){
	printf("mmap\n");
	 exit(1);
     }
     printf(" le PID que j'ai trouvé = %d\n",*memoire_partage);
     pid=*memoire_partage;
     kill(pid,SIGUSR1);
     if (shm_unlink(getlogin()) != 0) {
       	perror("shm_unlink");
       	exit(1);
    }
 return EXIT_SUCCESS;
}

