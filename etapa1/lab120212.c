#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
//#include "getProcInfo.h"
 
char *strremove(char *str, const char *sub) {
    int len = strlen(sub);
    char *q;
    if (len > 0) {
        char *p = str;
        q = p + len + 1;
    }
    return q;
}



int main(int argc, char *argv[]){
    char filename[20];
    strcpy(filename, "/proc/");
    strcat(filename, argv[1]);
    strcat(filename, "/status");
    printf("%s",filename);
    printf("\n");

    char line[201];
    char *result;
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
      if (strstr(line, "VmData")) {
        

        result = remove_word(line, "VmData");
        printf("Nombre del proceso:");
        printf("%s", result);
      }

    } 
    
    fclose(iF);
    exit(0);
    

    
}

