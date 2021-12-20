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


FILE *open_file(char *filename, char process[10]){
    FILE *iF = fopen(filename,"r");
    if(iF == NULL) {
      //printf("Error al abrir el archivo %s\n", filename);
      printf("Proceso %s Inexistente\n\n", process);
      exit(300);
    }
    return iF; 
}

FILE *open_file3(char *filename, char process[10], FILE *pf){
    FILE *iF = fopen(filename,"r");
    char informa[1000];
    if(iF == NULL) {
      strcpy(informa, " es un proceso Inexistente \n");
      strcat(informa, process);
      fputs(informa, pf);
      exit(300);
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

void print_informationWrite(FILE *iF, FILE *pf, char *filename){
    char line[201];
    char *result, *resultVmData, *resultVmStk;
    char informa[1000];
    FILE *ip = fopen(filename,"r");
    if(ip == NULL) {
      strcpy(informa, "Proceso Inexistente\n");
     // strcat(informa, process);
      fputs(informa, pf);
    //  printf("Proceso %s Inexistente\n\n", process);
      exit(300);
    }else{
    while(fgets(line, 201, iF)!=NULL) {
        if (strstr(line, "Name")) {
            result = remove_word(line, "Name");
             strcpy(informa, "\nNombre del proceso: ");
             strcat(informa, result);
            // printf("Nombre del proceso:%s", result);
        } else if (strstr(line, "State")){
            result = remove_word(line, "State");
            strcat(informa, "\nEstado: ");
            strcat(informa, result);
           // printf("Estado:%s", result);
        } else if (strstr(line, "VmSize")){
            result = remove_word(line, "VmSize");
            strcat(informa, "\nTamaño total de la imagen en memoria: ");
            strcat(informa, result);
          //printf("Tamaño total de la imagen en memoria:%s", result);
        } else if (strstr(line, "VmData")){
            resultVmData = remove_word(line, "VmData");
            strcat(informa, "\n\tTamaño de la memoria en la región DATA: ") ;
            strcat(informa, resultVmData);

            //printf("\tTamaño de la memoria en la región DATA:%s", resultVmData);
        } else if (strstr(line, "VmStk")){
            resultVmStk = remove_word(line, "VmStk");
            strcat(informa, "\n\tTamaño de la memoria en la región STACK:");
            strcat(informa, resultVmStk);
            //printf("\tTamaño de la memoria en la región STACK:%s", resultVmStk);
        } else if (strstr(line, "VmExe")){
            result = remove_word(line, "VmExe");
            strcat(informa, "\n\tTamaño de la memoria en la región TEXT: ");
            strcat(informa, result);
            //printf("\tTamaño de la memoria en la región TEXT:%s", result);
        } else if (strstr(line, "voluntary_ctxt_switches") && !strstr(line, "nonvoluntary_ctxt_switches")){
            result = remove_word(line, "voluntary_ctxt_switches");
            strcat(informa, "\nNúmero de cambios de contexto realizados (voluntarios - no voluntarios): -");
            strcat(informa, result);
        
            //printf("Número de cambios de contexto realizados (voluntarios - no voluntarios): %s -", result);
        } else if (strstr(line, "nonvoluntary_ctxt_switches")){
            result = remove_word(line, "nonvoluntary_ctxt_switches");
            //strcat(informa, result);
            //printf("%s", result);
      }
    }
   // printf("%s", informa);
    fputs(informa, pf);
    }
}

