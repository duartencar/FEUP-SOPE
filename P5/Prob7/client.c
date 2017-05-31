#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>

int readline(int fd, char *str)
{
  int n;

  do
  {
    n = read(fd, str, 1);
  } while (n > 0 && *str++ != '\0');

  return (n > 0);
}

int main()
{
  int fdW, fdR;

  int numbers[2];

  char str[100];

  if((fdW = open("/tmp/req", O_WRONLY)) == -1)
  {
    printf("FIFO '/tmp/req' not available!\n");

    exit(1);
  }

  if((fdR = open("/tmp/ans", O_RDONLY)) == -1)
  {
    printf("FIFO '/tmp/ans' not available!\n");

    exit(1);
  }

  while((mkfifo("/tmp/req", 0660) < 0) && (errno == EEXIST))
  {
    printf("x y?\n");

    scanf("%d %d", &numbers[0], &numbers[1]);

    sprintf(str, "%d %d", numbers[0], numbers[1]);

    write(fdW, str, strlen(str) + 1);

    memset(str, 0, 100);

    read(fdR, str, 100);

    printf("%d + %d = %d\n", numbers[0], numbers[1], atoi(str));
  }

  return 0;
}
