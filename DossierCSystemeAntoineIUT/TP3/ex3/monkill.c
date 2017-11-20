#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

typedef int (*fonction)(int);

// déclaration d'un type fonction

int monkill(int argument){

	kill(argument,SIGTERM);
	return 0;
}

int main(int argc, char *argv[]){

	fonction dead;	
	dead = monkill;
	int arg;
	arg = atoi(argv[1]);	
	dead(arg);

return EXIT_SUCCESS;
}
