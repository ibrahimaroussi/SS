#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX 100

int main(int argc, char *argv[]){

    int message1[2];message2[2][2],message3[3][2];
    pid_t fils1,fils2,pid;
    int pereTOfils[2],filsTOfrere1[2],frereTOpere[2],i;

    pipe(pereTOfils);
    pipe(filsTOfrere);
    pipe(frereTOpere);


	pid = getpid();

    message1[0]=pid;
    message1[1]=atoi(argv[1]);

	fils1 = fork();

	if(fils1==0){
        close(pereTOfils[1]);
        read(pereTOfils[0],message1,MAX);
        printf("\nPID = %d - Entier = %d\n",message1[0],message1[1]);
        message2[0][0] = getpid();
        message2[0][1] = rand()%(message1[1]);
        message2[1][0] = message1[0];
        message2[1][1] = message1[1];
        close(filsTOfrere[0]);
        write(filsTOfrere[1],message2,MAX);

    }
    else if(fils1==-1){
        printf("\nERREUR\n");
    }
    else{
        close(pereTOfils[0]);
        write(pereTOfils[1],message1,MAX);
        fils2 = fork();
        if(fils2==0){
            close(filsTOfrere[1]);
            read(filsTOfrere[0],message2,MAX);
            printf("\nPID Frere = %d - EntierAleat = %d \n PID Pere = %d - Entier = %d\n",message2[0][0],message2[0][1],message2[1][0],message2[1][1]);
            message3[0][0] = getpid();
            message3[0][1] = message2[0][1]+message2[1][1];
            message3[1][0] = message2[0][0];
            message3[1][1] = message2[0][1];
            message3[2][0] = message2[1][0];
            message3[2][1] = message2[1][1];
            close(frereTOpere[0]);
            write(frereTOpere[1],message3,MAX);
        }
        else if(fils2==-1){
            printf("\nERREUR\n");
        }
        else{
            close(frereTOpere[1]);
            read(frereTOpere[0],message3,MAX);
            if((message3[0][0]==fils2)&&(message3[1][0]==fils1)&&(message3[2][0]==pid)&&(message3[0][1]==(message3[1][1]+message3[2][1]))){
                for(i=0;i<3;i++){
                     printf("\nPID = %d - Valeur = %d\n",message3[i][0],message3[i][1]);
                }
            }
            else{
                printf("\nERREUR\n");
            }
        }

    }

return EXIT_SUCCESS;
}
