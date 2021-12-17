#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "methods.h"
 

int main(int argc, char *argv[]){
    char filename[20];
    strcpy(filename, "/proc/");
    strcat(filename, argv[1]);
    strcat(filename, "/status");
    
    FILE *iF = openFile(filename); 

    printInformation(iF);
    
    fclose(iF);
    exit(0);

}

