#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
//#include "getProcInfo.h"
 

int main(){
    char str[3];
    //printf("%s", str);
    char conca[]="/proc/";
    char conca2[]="/status";
   // printf("%s",conca);
   // printf("%s","    ");
    fgets(str, 3, stdin);
    strcat(conca,str);
   // strcat(conca,conca2);
    strcat(conca,conca2);
    //printf("%s",conca);

    char str1[80];
    strcpy(str1, "/proc/");
    strcat(str1, str);
    strcat(str1, "/status");
    printf("%s",str1);
    // char filename[] = conca;
    // char line[201];
    // int numLinea = 1;
    // FILE *iF;  
    // iF = fopen(filename,"r");
    // if (iF == NULL) {
    // printf("Error al abrir el archivo %s\n", filename);
    // exit(-1);
    // }
    // while(fgets(line, 201, iF)!=NULL) {
    // printf("%-5d",numLinea++);
    // printf("%s",line);
    // } 
    // fclose(iF);
    // exit(0);
    // }

    
}