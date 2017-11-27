#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
  int val;
  val = getpid();
  printf("\nPID : %d\n",val);
  system("tp1pid");
  
  return EXIT_SUCCESS;

}
