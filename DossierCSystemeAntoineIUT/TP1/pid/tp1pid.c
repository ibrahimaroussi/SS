#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
  int val;
  val = getpid();
  printf("\nPID : %d\n",val);
  val = getppid();
  printf("\nPPID : %d\n",val);
  return EXIT_SUCCESS;
}




