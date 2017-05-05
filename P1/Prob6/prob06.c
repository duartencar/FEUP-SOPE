// PROGRAMA p6a.c 
#include <stdio.h> 
#include <stdlib.h>

#define BUF_LENGTH 256 
int main(void) 
{ 
  FILE *src, *dst; 
  char buf[BUF_LENGTH]; 
  if ( ( src = fopen( "infile.txt", "r" ) ) == NULL )  
  { 
    perror("Não existe 'infile.txt'!");
    exit(1); 
  } 
  if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL ) 
  { 
    perror("Não existe 'outfile.txt'!");
    exit(2); 
  } 
/*Sistemas
Operativos
–
MIEIC
Jorge
Silva*/
  while( ( fgets( buf, BUF_LENGTH - 1 , src ) ) != NULL ) 
  { 
    fputs( buf, dst ); 
  } 
  fclose( src ); 
  fclose( dst ); 
  exit(0);  // zero é geralmente indicativo de "sucesso" 
} 
