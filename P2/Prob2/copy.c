#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BUF_LENGTH 256
int main(int argc, char *argv[]) 
{ 
  
   FILE *src, *dst; 
   char buf[BUF_LENGTH];
	double diff_t;
	time_t begin, end;
	
	begin = clock();

   if ( ( src = fopen( argv[1], "r" ) ) == NULL )  
   { 
    exit(1);  
   } 
   if ( ( dst = fopen( argv[2], "w" ) ) == NULL ) 
   { 
     exit(2);
   } 
   while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL ) 
   { 
     fputs( buf, dst ); 
   } 
   fclose( src ); 
   fclose( dst ); 
	end = clock();

	diff_t = (double)(end-begin) / CLOCKS_PER_SEC;

	printf("Com biblioteca de C demorou %f segundos\n", diff_t);

	
   exit(0);  // zero é geralmente indicativo de "sucesso" 
} 
