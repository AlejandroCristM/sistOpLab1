#include "process.h"

int print_stack(pds_t *process, char **pids){
	 char titulo[100];
	strcpy(titulo, "-- Informacion recolectada!!!\n");
	int tama=0;
    for(int j=2; pids[j] != NULL; j++){
		tama=tama+1;
	}
    char charValue = tama+'0';
    char filename2[50];
    if(tama>1){
        strcpy(filename2, "psinfo-report-");
        strcat(filename2, pids[2]);
    for (int i = 3; i <= tama+1; i++){
        strcat(filename2, "-");
        strcat(filename2, pids[i]);
    }
    strcat(filename2, ".info");
    //strcat(filename2, "\0");
    }

    //Creo el archivo
    FILE *pf;
    pf=fopen(filename2, "a");
    fputs(titulo, pf);
		//Apartado del id
	char pid[50];
	strcpy(pid, "Pid: ");
	int id=process->id;
	char *idChar=_itoa(*pid);
	strcat(pid, idChar);
	fputs(pid, pf);

		//Apartado del nombre
	char nombre[50];
	char nombreChar[50];
	strcpy(nombreChar, process->name_process);
	strcpy(nombre, "\nNombre del proceso: ");
	strcat(nombre, nombreChar);
	fputs(nombre, pf);
		//guiones
	char guiones[50];
	strcpy(guiones, "\n...\n");
	fputs(guiones, pf);

	//fputs("Nombre del proceso: %s", process->name_process, pf);
	//printf("Pid: %d\n", process->id);
	//printf("Nombre del proceso: %s", process->name_process);
	//printf("\n...\n");
	return 0;
}