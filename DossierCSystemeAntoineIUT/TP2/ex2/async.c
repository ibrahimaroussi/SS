#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
	
int var,i,j;
var = fork();
if(var==0){
	for(i=1;i<10;i=i+2){
		printf("\n%d\n",i);
	}
}
else if(var==-1){
	printf("\nERREUR\n");
}
else{
	for(j=0;j<9;j=j+2){
		printf("\n%d\n",j);
	}
}

exit(2);
}
