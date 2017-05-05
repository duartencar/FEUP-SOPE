#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

#define READ 0
#define WRITE 1

typedef struct
{
  int x,y;
} nums;

int main (void)
{
  int fd[2];

  pid_t pid;

  pipe(fd);

  pid = fork();

  if(pid > 0)
  {
    nums a;
    printf("PARENT:\n");
    printf("x y ? ");
    scanf("%d %d", &a.x, &a.y);
    close(fd[READ]);
    write(fd[WRITE], &a, sizeof(nums));
    close(fd[WRITE]);
  }
  else if(pid == 0)
  {
    nums b;
    read(fd[READ], &b, sizeof(nums));
    printf("SON:\n");
    printf("x + y = %d\n", b.x + b.y);
    close(fd[READ]);
  }
  else
  {
    printf("ERROR creating process!\n");
    return 1;
  }

  return 0;
}
