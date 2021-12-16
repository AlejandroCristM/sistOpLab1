#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearEscribirArc(char infoProc[],char pids[]){

    //instrucciones para poner el nombre correctamente | FORMATO: psinfo-report-[pids].info
    char filename[100];
    strcpy(filename, "psinfo-report-");
    strcat(filename, pids);
    strcat(filename, ".info");

    //Creo el archivo
    FILE *pf;
    pf=fopen(filename, "w");
    fputs(infoProc, pf); //linea para agregar el texto al archivo creado

    if (pf != NULL) {
        printf("El archivo se creo correctamente \n");
        exit(1);
    }
    if(pf==NULL){
        printf("Error al abrir el archivo \n");
        exit(1);
    }
    
}
