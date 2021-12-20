#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


char *remove_word(char *str, const char *sub) { // mueve el apuntador de la línea (str) hasta que no esté el parámetro (sub).
    int len = strlen(sub);
    char *q;
    if (len > 0) {
        char *p = str;
        q = p + len + 1;
    }
    return q;
}

char *concatenate_filename(char *processId){
    char filename2[20], *p;
    strcpy(filename2, "/proc/");
    strcat(filename2, processId);
    strcat(filename2, "/status");
    p = filename2;
    return p;
}

FILE *open_file(char *filename){
    FILE *iF = fopen(filename,"r");
    if (iF == NULL) {
      printf("Error al abrir el archivo %s\n", filename);
      exit(-1);
    }
    return iF;
}

void print_information(FILE *iF){
    char line[201];
    char *result, *resultVmData, *resultVmStk;
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
            printf("\tTamaño de la memoria en la región DATA:%s", resultVmData);
        } else if (strstr(line, "VmStk")){
            resultVmStk = remove_word(line, "VmStk");
            printf("\tTamaño de la memoria en la región STACK:%s", resultVmStk);
        } else if (strstr(line, "VmExe")){
            result = remove_word(line, "VmExe");
            printf("\tTamaño de la memoria en la región TEXT:%s", result);
        } else if (strstr(line, "voluntary_ctxt_switches") && !strstr(line, "nonvoluntary_ctxt_switches")){
            result = remove_word(line, "voluntary_ctxt_switches");
            printf("Número de cambios de contexto realizados (voluntarios - no voluntarios): %s -", result);
        } else if (strstr(line, "nonvoluntary_ctxt_switches")){
            result = remove_word(line, "nonvoluntary_ctxt_switches");
            printf("%s", result);
      }
    }
}