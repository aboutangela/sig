#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    int f = open("a.txt", O_WRONLY | O_CREAT, 0766);
    write(f,"program exited from keyboard interrupt",40);
    printf("\nprogram exited from keyboard interrupt\n");
    close(f);
    exit(0);
  }
  if(signo == SIGUSR1){
    printf("%d \n", getppid());
  }
}

int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
  while(1){
    printf("%d \n", getpid());
    sleep(1);
  }
}
