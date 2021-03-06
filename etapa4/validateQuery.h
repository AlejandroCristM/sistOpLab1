/*
    Validate query es la validación de la petición realizada por el usuario
    <#PID> Para traer la info del proceso relacionado al valor numérico ingresado
    -l <PID's> Para traer la info de los procesos relacionados al valor numérico ingresado
    -r <PID's> Para traer la info de los procesos relacionados al valor numérico ingresado y ponerlo en un archivo
    se retornará 0 para un solo proceso
    se retornará 1 para una lista de procesos
    se retornará 2 para una lista procesos en archivo

    Errores al bash
    101 por error en arg inválido
    102 por valor de bandera inválido
    103 opción inválida

    200 por falta de información

    300 resultado válido {Proceso inexistente o información encontrada}
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void showResume(){
    printf("\nUsage\n");
    printf("    psinfo [options] <processPID>\n\n");
    printf("options:\n");
    printf("    <processPID>     PID (process id) show process information, if one process does not exist, program will stop but will show the processes information before this\n");
    printf("    -l <pids>        pids (process id list >=1) show process(es) information\n");
    printf("    -r <pids>        pids (process id List >=1) save process(es) information in psinfo-report-[pids].info.\n\n");
}

bool isNumber(char arg[]){
    for (int i = 0; i < strlen(arg); i++){
        if(!isdigit(arg[i])){
            return false;
        }
    }
    return true;
}

int isValidFlag(char arg[]){
    if(arg[0]=='-'){
        if(arg[1]=='l') return 1;
        if(arg[1]=='r') return 2;
        return 3;
    }
    return 0;
}


int validateQuery(int argc, char *argv[]){
    bool sw;
    char text[10];
    int state;

    if(argc<2) {
        printf("Psinfo: usage error:  Process PID required \n");
        showResume();
        exit(200);
    } else if(argc==2){
        strcpy(text, argv[1]);
        sw = isNumber(text);
        if(sw){
            return 0; //0 => only 1 process
        }else{
            state= isValidFlag(text);
            if(state==1 || state==2){
                printf("Psinfo: valid flag but PID process required after:  --> '%s'\n", text);
                showResume();
                exit(200);
            } else if(state==3){
                printf("Psinfo: invalid flag:  --> '%s'\n", text);
                showResume();
                exit(102);
            }else{ //state=0
                printf("Psinfo: invalid option:  --> '%s'\n", text);
                showResume();
                exit(103);
            }
        }
    } else{ //si es mayor a 2 significa que viene un un -l o -r y luego la lista
        
        strcpy(text, argv[1]);
        sw = isNumber(text);

        if(sw){
            strcpy(text, argv[2]);
            printf("Psinfo: invalid argument:  --> '%s'\n", text);
            showResume();
            exit(101);
        }else{
            state = isValidFlag(text);
            switch (state){
                case 0:
                    printf("Psinfo: invalid option:  --> '%s'\n", text);
                    showResume();
                    exit(103);
                    break;

                case 1:
                    for (int i = 2; i < argc; i++){
                        strcpy(text, argv[i]);
                        if(!isNumber(text)){
                            printf("Psinfo: invalid argument:  --> '%s'\n", text);
                            showResume();
                            exit(101);
                        }
                    }  
                    return 1; //1 => list
                    break;

                case 2:
                    for (int i = 2; i < argc; i++){
                        strcpy(text, argv[i]);
                        if(!isNumber(text)){
                            printf("Psinfo: invalid argument:  --> '%s'\n", text);
                            showResume();
                            exit(101);
                        }
                    }  
                    return 2; //2 => file
                    break;

                case 3:
                    printf("Psinfo: invalid flag:  --> '%s'\n", text);
                    showResume();
                    exit(102);
                    break;
            }
        }
    }

}


        // Mostrar los arg de argv
        // for (int i = 0; i < argc; i++){
        //     printf("argv[%d] = %s\n", i, argv[i]);
        // } 