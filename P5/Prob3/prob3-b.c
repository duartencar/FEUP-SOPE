#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


#define READ 0
#define WRITE 1
#define MAX_STR_LEN 256

int main (int argc, char* argv[])
{
  int fd[2], status;

  pid_t pid;

  pipe(fd);

  pid = fork();

  if(pid > 0)
  {
    printf("Parent\n");

    close(fd[0]); //close READ
  }
  else if( pid == 0)
  {

  }
  else
  {

  }

  return 0;
}
