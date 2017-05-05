#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])  
{ 
  
  int i = 0;
  int j = 0;
  for(j=0; j < atoi(argv[argc - 1]); j++)
  {
     for(i = 1; i< argc - 1; i++)
     {
	   printf("Hello ");
	   printf("%s ", argv[i]);
     }  
     printf("\n");
}
  return 1; 
}
