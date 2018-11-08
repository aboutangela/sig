#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("program exited from SIGINT \n");
    exit(0);
  }
  if(signo == SIGUSR1){

  }
}

int main(){

}
