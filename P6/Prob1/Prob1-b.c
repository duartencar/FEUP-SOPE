// PROGRAMA p01.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 10000

void * thrfunc(void * arg)
{
  int i;
  char msg[3];

  fprintf(stderr, "Starting thread %2d\n", *(int *) arg);

  for (i = 1; i <= NUMITER; i++)
  {
    sprintf(msg, "%d", *(int *)arg);

    write(STDERR, msg, 3 * sizeof(char));
  }

  return NULL;
}

int main()
{
  pthread_t ta, tb;

  int i = 1;

  pthread_create(&ta, NULL, thrfunc, (void *)&i);

  pthread_create(&tb, NULL, thrfunc, (void *)&i);

  pthread_join(ta, NULL);

  pthread_join(tb, NULL);

  return 0;
}
