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

  float *ret;

  ret = malloc(sizeof(float));

  switch (b->op)
  {
    case '+':
      *(float *)ret = b->x + b->y;
      pthread_exit(ret);
    case '-':
      *(float *)ret = b->x - b->y;
      pthread_exit(ret);
    case '*':
      *(float *)ret = b->x * b->y;
      pthread_exit(ret);
    case '/':
      if(b->y != 0)
      {
        *(float *)ret = b->x / b->y;
        pthread_exit(ret);
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

  void *resp;

  printf("x y?");

  pthread_t operations[4];

  scanf("%f %f", &a.x, &a.y);

  a.op = '+';

  pthread_create(&operations[0], NULL, operating, (void *) &a);

  pthread_join(operations[0], &resp);

  printf("%f %c %f = %f\n", a.x, a.op, a.y, *(float *)resp);

  a.op = '-';

  pthread_create(&operations[1], NULL, operating, (void *) &a);

  pthread_join(operations[1], &resp);

  printf("%f %c %f = %f\n", a.x, a.op, a.y, *(float *)resp);

  a.op = '*';

  pthread_create(&operations[2], NULL, operating, (void *) &a);

  pthread_join(operations[2], &resp);

  printf("%f %c %f = %f\n", a.x, a.op, a.y, *(float *)resp);

  if(a.y != 0)
  {
    a.op = '/';

    pthread_create(&operations[1], NULL, operating, (void *) &a);

    pthread_join(operations[1], &resp);

    printf("%f %c %f = %f\n", a.x, a.op, a.y, *(float *)resp);
  }
  else
    printf("Division by 0 not allowed\n");

  pthread_exit(0);
}
