#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main() {

  char filename[] = "/proc/2/status";
  char line[201];
  int numLinea = 1;
  FILE *iF;  
  iF = fopen(filename,"r");
  if (iF == NULL) {
    printf("Error al abrir el archivo %s\n", filename);
    exit(-1);
  }
  while(fgets(line, 201, iF)!=NULL) {
    printf("%-5d",numLinea++);
    printf("%s",line);
  } 
  fclose(iF);
  exit(0);

  //aaaaaaaaaaaaaaaaaaaaaaaaaa


    
}