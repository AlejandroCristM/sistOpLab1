#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
//#include "getProcInfo.h"
 
char *remove_word(char *str, const char *sub) {
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

    char line[201];
    char *result, *resultVmData, *resultVmStk;
    FILE *iF;  
    iF = fopen(filename,"r");
    if (iF == NULL) {
      printf("Error al abrir el archivo %s\n", filename);
      exit(-1);
    }
    while(fgets(line, 201, iF)!=NULL) {
      if (strstr(line, "Name")) {
        result = remove_word(line, "Name");
        printf("Nombre del proceso:%s", result);
      } else if (strstr(line, "State")){
        result = remove_word(line, "State");
        printf("Estado:%s", result);
      } else if (strstr(line, "VmSize")){
        result = remove_word(line, "VmSize");
        printf("Tamaño total de la imagen en memoria:%s", result);
      } else if (strstr(line, "VmData")){
        resultVmData = remove_word(line, "VmData");
      } else if (strstr(line, "VmStk")){
        resultVmStk = remove_word(line, "VmStk");
      } else if (strstr(line, "VmExe")){
        result = remove_word(line, "VmExe");
        printf("\tTamaño de la memoria en la región TEXT:%s", result);
        printf("\tTamaño de la memoria en la región DATA:%s", resultVmData);
        printf("\tTamaño de la memoria en la región STACK:%s", resultVmStk);
      } else if (strstr(line, "voluntary_ctxt_switches") && !strstr(line, "nonvoluntary_ctxt_switches")){
        result = remove_word(line, "voluntary_ctxt_switches");
        printf("Número de cambios de contexto realizados (voluntarios - no voluntarios): %s -", result);
      } else if (strstr(line, "nonvoluntary_ctxt_switches")){
        result = remove_word(line, "nonvoluntary_ctxt_switches");
        printf("%s", result);
      }
    } 
    
    fclose(iF);
    exit(0);
    

    
}

