#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "validateQuery.h"
#include "methods.h"
#include "listProcesses.h"
#include "crearEscribirArchivo.h"

int main(int argc, char *argv[]){
    int ansValidation = validateQuery(argc, argv);
    char filename[20];
    switch (ansValidation){
    
        case 0:
            strcpy(filename, "/proc/");
            strcat(filename, argv[1]);
            strcat(filename, "/status");
            
            FILE *iF = open_file(filename, argv[1]); 
            print_information(iF);
            fclose(iF);
            break;
    
        case 1:
            listProcessesInfo(argc, argv);            
            break;
    
        case 2:
            crearEscribirArchi(argc, argv);
            break;

    }
}