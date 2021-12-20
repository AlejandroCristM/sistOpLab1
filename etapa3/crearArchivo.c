#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"crearEscribirArchivo.h"


int main(int argc, char *argv[]){

  char text[10];
  strcpy(text, argv[1]);

  if(isValidFlag(text)==1){
    printf("\n EEEentro \n");
    char textoetapa2[]="Cristian el \n ingen333ero en sistemas";
    char cris[]="1";
    printf("\n EEEentro \n");
    crearEscribirArc(*textoetapa2, argv);
  }else{
    printf("\n no entro \n");
  }

        return 0;
}
  









    // //texto de prueba, aca deberia ir el string de la etapa2
    // char textoetapa2[]="Cristian el \n ingen333ero en sistemas";

    // //instrucciones para poner el nombre correctamente | FORMATO: psinfo-report-[pids].info
    // char filename[20];
    // strcpy(filename, "psinfo-report-");
    // strcat(filename, argv[1]);
    // strcat(filename, ".info");

    // //Creo el archivo
    // FILE *pf;
    // pf=fopen(filename, "w");
    // fputs(textoetapa2, pf); //linea para agregar el texto al archivo creado

    // if (pf != NULL) {
    //     printf("El archivo se creo correctamente \n");
    //     exit(1);
    // }
    // if(pf==NULL){
    //     printf("Error al abrir el archivo \n");
    //     exit(1);
    // }

