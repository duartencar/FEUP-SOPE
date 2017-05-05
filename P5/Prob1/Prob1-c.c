#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define READ 0
#define WRITE 1

int main()
{
  int fd[2];

  pid_t pid;

  pipe(fd);

  pid = fork();

  if (pid > 0) //pai
  {
    char resp1 [100];
    
    char resp2[100];
    
    printf("PARENT:\n");
    
    printf("x y ? ");

    scanf("%s %s", resp1, resp2);

    close(fd[READ]);

    write(fd[WRITE], resp1, 100*sizeof(char));

    write(fd[WRITE], resp2, 100*sizeof(char));
    
    close(fd[WRITE]);
  }
  else if(pid == 0) //filho
  {
    char resp1[100];

    char resp2[100];

    close(fd[WRITE]);

    read(fd[READ],resp1,100*sizeof(char));

    read(fd[READ],resp2,100*sizeof(char));

    printf("SON:\n");

    printf("x + y = %d\n", atoi(resp1) + atoi(resp2));

    close(fd[READ]);
  }
  else
  {
    printf("ERROR creating process!\n");
    
    return 1;
  }

  return 0;
}