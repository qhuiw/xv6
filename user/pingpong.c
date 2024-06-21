#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
  int fds[2];
  if(pipe(fds) < 0){
    printf("pingpong: pipe failed\n");
    exit(1);
  }
  char buf[100];

  int pid = fork();

  if(pid==0) {
    // child process
    read(fds[0], buf, 4);
    printf("%l: received %s\n", getpid(), buf);
    write(fds[1], "ping", 4);

  } else if (pid < 0) {
    printf("pingpong: fork failed\n");
    exit(1);
  } else {
    // parent process
    write(fds[1], "ping", 4);

    read(fds[0], buf, 4);
    printf("%l: received %s\n", getpid(), buf);
  }

  

  // if (p) exit(-1);



}