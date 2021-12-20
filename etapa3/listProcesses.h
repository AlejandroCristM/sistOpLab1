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

char getListProcessesInfo(int argc, char *argv[], FILE *pf){
    char filename[20];
    char informa[1000];
    fputs(informa, pf);
    for (int i = 2; i < argc; i++){
        strcpy(informa, "\nProceso con PID: ");
        strcat(informa, argv[i]);
        fputs(informa, pf);
        strcpy(filename, "/proc/");
        strcat(filename, argv[i]);
        strcat(filename, "/status");
            
        FILE *iF = open_file3(filename, argv[i], pf); 
        print_informationWrite(iF, pf, filename);
        fclose(iF);
    } 
}