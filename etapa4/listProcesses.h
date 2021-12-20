#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void listProcessesInfo(int argc, char *argv[]){
    char filename[20];
    for (int i = 2; i < argc; i++){
        printf("\nProceso con PID: %s\n", argv[i]);
        strcpy(filename, "/proc/");
        strcat(filename, argv[i]);
        strcat(filename, "/status");
            
        FILE *iF = open_file(filename, argv[i]); 
        print_information(iF);
        fclose(iF);
    } 
}