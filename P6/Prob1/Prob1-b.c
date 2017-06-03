// PROGRAMA p01.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 10000

void * thrfunc(void * arg)
{
  int i;

  fprintf(stderr, "Starting thread %2d\n", (int) arg);

  for (i = 1; i <= NUMITER; i++)
    write(STDERR, arg, 4);

  return NULL;
}

int main()
{
  pthread_t ta, tb;

  int i = 0;

  pthread_create(&ta, NULL, thrfunc, (void *)i);

  pthread_create(&tb, NULL, thrfunc, (void *)++i);

  pthread_join(ta, NULL);

  pthread_join(tb, NULL);

  return 0;
}
