#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 100

typedef char mot[MAX];

int main(int argc, char *argv[]){

mot var=argv[1];

mkfifo (var,0777);

exit(2);
}
