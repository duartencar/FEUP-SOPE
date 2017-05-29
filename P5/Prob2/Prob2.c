#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>


#define READ 0
#define WRITE 1

int main(void)
{
  int fd[2], status;

  pid_t pid;

  pipe(fd);

  pid = fork();

  if(pid > 0)
  {
    int a[2];

    int res;

    printf("PARENT:\n");

    printf("x y ? ");

    scanf("%d %d", &a[0], &a[1]);

    write(fd[WRITE], a, 2 * sizeof(int));

    close(fd[WRITE]);

    wait(&status);

    read(fd[READ], &res, sizeof(int));

    close(fd[READ]);

    printf("RESULTADO = %d\n", res);
  }
  else if(pid == 0) //filho
  {
    int b[2];

    int resultado;

    read(fd[READ],b,2*sizeof(int));

    close(fd[READ]);

    resultado = b[0] + b[1];

    write(fd[WRITE], &resultado, sizeof(int));

    close(fd[WRITE]);
  }
  else
  {
    printf("ERROR creating process!\n");

    return 1;
  }

  return 0;
}
