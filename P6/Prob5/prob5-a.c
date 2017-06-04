#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
  float x;

  float y;

  char op;
}inter;

void *operating(void *elements)
{
  inter *b = (inter *)elements;

  switch (b->op)
  {
    case '+':
      printf("%f + %f = %f\n", b->x, b->y, b->x + b->y);
      pthread_exit(NULL);
    case '-':
      printf("%f - %f = %f\n", b->x, b->y, b->x - b->y);
      pthread_exit(NULL);
    case '*':
      printf("%f * %f = %f\n", b->x, b->y, b->x * b->y);
      pthread_exit(NULL);
    case '/':
      if(b->y != 0)
      {
        printf("%f / %f = %f\n", b->x, b->y, b->x / b->y);
        pthread_exit(NULL);
      }
      else
      {
        printf("Division by 0 not allowed\n");
        pthread_exit(NULL);
      }
    default:
      pthread_exit(NULL);
  }
}

int main ()
{
  inter a;

  printf("x y?");

  pthread_t operations[4];

  scanf("%f %f", &a.x, &a.y);

  a.op = '+';

  pthread_create(&operations[0], NULL, operating, (void *) &a);

  pthread_join(operations[0], NULL);

  a.op = '-';

  pthread_create(&operations[1], NULL, operating, (void *) &a);

  pthread_join(operations[1], NULL);

  a.op = '*';

  pthread_create(&operations[2], NULL, operating, (void *) &a);

  pthread_join(operations[2], NULL);

  a.op = '/';

  pthread_create(&operations[3], NULL, operating, (void *) &a);

  pthread_join(operations[3], NULL);

  pthread_exit(0);
}
