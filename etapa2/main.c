#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "validateQuery.h"
#include "methods.h"
#include "listProcesses.h"
 

int main(int argc, char *argv[]){
    char filename[20];
    char text[10];

    strcpy(text, argv[1]);
    if(isValidFlag(text)){
        listProcessesInfo(argc, argv);
    }    
    else if(isNumber(text)){
        strcpy(filename, "/proc/");
        strcat(filename, argv[1]);
        strcat(filename, "/status");
            
        FILE *iF = open_file(filename, argv[1]); 
        print_information(iF);
        fclose(iF);
    }
}