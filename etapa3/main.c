#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "validateQuery.h"
#include "methods.h"
#include "listProcesses.h"
#include"crearEscribirArchivo.h"
 

int main(int argc, char *argv[]){
    char processesInfo[50];
    char filename[20];
    char text[10];
    strcpy(text, argv[1]);
    int state;

    if(isNumber(text)){
        strcpy(filename, "/proc/");
        strcat(filename, argv[1]);
        strcat(filename, "/status");
            
        FILE *iF = open_file(filename, argv[1]); 
        print_information(iF);
        fclose(iF);

    }
    else{

        state=isValidFlag(text);

        switch (state){
            case 0:
                printf("Ingreso inválido");
                break;

            case 1:
                listProcessesInfo(argc, argv);
                break;

            case 2: //etapa3
               // char processesInfo[] = getListProcessesInfo(argc, argv);
                crearEscribirArchi(argc, argv);
                break;
        }
    }
}