#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *func(void *order)
{
  sleep(1);

  printf("My TID: %ld\t ORDER: %3d\n", (long int)pthread_self(), *(int *)order);

  pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
  if(argc != 2)
  {
      printf("Wrong number of args...\n");

      exit(0);
  }

  printf("argv %d\n", atoi(argv[1]));

  pthread_t x[atoi(argv[1])];

  int i;

  for(i = 0; i < atoi(argv[1]); i++)
    pthread_create(&x[i], NULL, func, (void *)&i);

  pthread_exit(0);
}
