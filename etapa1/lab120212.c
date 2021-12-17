#include "methods.h"

int main(int argc, char *argv[]){
    char filename[20];
    strcpy(filename, "/proc/");
    strcat(filename, argv[1]);
    strcat(filename, "/status");
    
    FILE *iF = open_file(filename); 

    print_information(iF);
    
    fclose(iF);
    exit(0);

}

