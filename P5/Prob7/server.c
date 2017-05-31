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

void fifoCreator(char *fifoName, mode_t permission)
{
  if(mkfifo(fifoName, permission) < 0)
  {
    if(errno == EEXIST)
      printf("FIFO '%s' already exists\n", fifoName);
    else
      printf("Cant create FIFO\n");
  }
  else
    printf("FIFO '%s' created sucessfully created\n", fifoName);
}

void fifoDestroy(char *fifoName)
{
  if(unlink(fifoName) < 0)
    printf("Error when destroying FIFO '%s'\n", fifoName);
  else
    printf("FIFO '%s' has been destroyed\n", fifoName);
}

int main()
{
  int Rfd, Afd, x, y;

  int answer;

  char str[100];

  fifoCreator("/tmp/req", 0660);

  fifoCreator("/tmp/ans", 0660);

  Rfd = open("/tmp/req", O_RDONLY);

  Afd = open("/tmp/ans", O_WRONLY);

  while(readline(Rfd, str) > 0)
  {
    sscanf(str, "%d %d", &x, &y);

    if(x == 0 && y == 0)
    {
      fifoDestroy("/tmp/req");

      fifoDestroy("/tmp/ans");

      break;
    }
    else
    {
      printf("RECEIVED: %d %d\n", x, y);

      sprintf(str, "%d", x + y);

      printf("SENDING: %s\n", str);

      write(Afd, &str, strlen(str)*sizeof(char) + 1);
    }
  }

  fifoDestroy("/tmp/req");

  fifoDestroy("/tmp/ans");

  return 0;
}
