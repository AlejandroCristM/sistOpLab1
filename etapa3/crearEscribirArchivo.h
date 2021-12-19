#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearEscribirArc(char infoProc,char **pids){
     printf("entro");
    
    //instrucciones para poner el nombre correctamente | FORMATO: psinfo-report-[pids].inf
    int tama=0;
    for(int j=2; pids[j] != NULL; j++){
		tama=tama+1;
	}
    char charValue = tama+'0';
    char filename2[50];
    if(tama>1){
        strcpy(filename2, "psinfo-report-");
        strcat(filename2, pids[2]);
    for (int i = 3; i <= tama; i++){
        strcat(filename2, "-");
        strcat(filename2, pids[i]);
    }
    strcat(filename2, ".info");
    strcat(filename2, "\0");
    }

    //Creo el archivo
    FILE *pf;
    pf=fopen(filename2, "w");
    fputs(infoProc, pf);
    if (pf != NULL) {
        printf("El archivo se creo correctamente \n");
        exit(1);
    }
    if(pf==NULL){
        printf("Error al abrir el archivo \n");
        exit(1);
}
