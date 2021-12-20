#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearEscribirArchi(int argc,char *argv[]){
    //instrucciones para poner el nombre correctamente | FORMATO: psinfo-report-[argv].inf
    char titulo[100];
    printf("rrrrrrrrrrr55555rrrrrrrrr");
	strcpy(titulo, "-- Informacion recolectada!!!\n");
	int tama=0;
    for(int j=2; argv[j]!= NULL; j++){
		tama=tama+1;
	}
    char charValue = tama+'0';
    char filename2[50];
    if(tama>0){
        strcpy(filename2, "psinfo-report-");
        strcat(filename2, argv[2]);
    for (int i = 3; i <= tama+1; i++){
        strcat(filename2, "-");
        strcat(filename2, argv[i]);
    }
    strcat(filename2, ".info");
    strcat(filename2, "\0");
    }

    //Creo el archivo
    FILE *pf;
    pf=fopen(filename2, "w");
    fputs(titulo, pf);

    
    if (pf != NULL) {
        char salida[100];
        strcpy(salida, "\nArchivo de salida generado: ");
        strcat(salida, filename2);
        printf("%s\n",salida);
        getListProcessesInfo(argc, argv, pf);
        exit(1);
    }
    if(pf==NULL){
        printf("Error al abrir el archivo \n");
        exit(1);
    }


}
