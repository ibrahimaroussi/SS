#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 10

int main(){

char mot[1];

int var;

int pipe1[2],pipe2[2];

pipe(pipe1);
pipe(pipe2);


int i,j;

var = fork();
if(var==0){
	for(i=1;i<10;i=i+2){
		close(pipe1[1]);
		read(pipe1[0],mot,1);
      	 	printf("\n%d\n",i);
		close(pipe2[0]);
		write(pipe2[1],"k",1);
	}

}
else if(var==-1){
	printf("\nERREUR\n");
}
else{
	printf("\n%d\n",0);
	for(j=2;j<9;j=j+2){
		close(pipe1[0]);
		write(pipe1[1],"o",1);
		close(pipe2[1]);
		read(pipe2[0],mot,1);
		printf("\n%d\n",j);
	}
}

exit(2);
}
