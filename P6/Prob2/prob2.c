#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int n = 50000;

#define STDERR 2

void * thrfunc(void * arg)
{
  void *ret;

  int value = 0;

  fprintf(stderr, "\nStarting thread %s\n", (char *) arg);

  while(n > 0)
  {
    write(STDERR, arg, 1);

    n--;

    value++;
  }

  ret = malloc(sizeof(int));

  *(int *)ret = value;

  return ret;
}

int main()
{
  pthread_t ta, tb;

  void *x , *y;

  pthread_create(&ta, NULL, thrfunc, "1");

  pthread_create(&tb, NULL, thrfunc, "2");

  pthread_join(ta, &x);

  pthread_join(tb, &y);

  printf("\nThread 1 printed: %d\n", *(int *)x);

  printf("Thread 2 printed: %d\n", *(int *)y);

  return 0;
}
