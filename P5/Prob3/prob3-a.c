#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


#define READ 0
#define WRITE 1
#define MAX_STR_LEN 256

int main (int argc, char* argv[])
{
  if(argc != 2)
  {
    printf("Insira o nome dum ficheiro\n");

    return 1;
  }

  int fd[2], status;

  pid_t pid;

  pipe(fd);

  pid = fork();

  if(pid > 0)
  {
    char str[MAX_STR_LEN];

    sprintf(str, "sort %s", argv[1]);

    printf("Parent\n");

    close(fd[0]); //close READ

    if(dup2(fd[1], STDOUT_FILENO) == -1)//redirect output
      printf("ERROR redirecting\n");

    system(str);

    close(fd[1]); //close WRITE
  }
  else if(pid == 0)
  {
    char str[MAX_STR_LEN];

    close(fd[1]); //close WRITE

    printf("CHILD - sorted names\n");

    while(read(fd[READ], str, MAX_STR_LEN * sizeof(char)) != 0)
      printf("%s\n", str);

    close(fd[0]); //close READ

    printf("ENDED\n");
  }
  else
  {
    printf("ERROR creating process!\n");

    return 1;
  }

  return 0;
}
