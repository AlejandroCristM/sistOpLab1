#ifndef __GETPROCINFO_H_
#define __GETPROCINFO_H_
#include <stdio.h>

void statusPro(int procs){
    char procsNum = scanf("%d", &procs);
    char concaPN[]=procsNum;
    char conca[]="/proc/";
    conca[]=strcat( conca[],concaPN[]);
    char conca2[]="/status";
    conca[]=strcat( conca[],conca2[]);
    printf(conca);

    char filename[] = conca;
    char line[201];
    int numLinea = 1;
    FILE *iF;  
    iF = fopen(filename,"r");
    if (iF == NULL) {
    printf("Error al abrir el archivo %s\n", filename);
    exit(-1);
    }
    while(fgets(line, 201, iF)!=NULL) {
    printf("%-5d",numLinea++);
    printf("%s",line);
    } 
    fclose(iF);
    exit(0);
    }
}