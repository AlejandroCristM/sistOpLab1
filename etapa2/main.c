#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<stdbool.h>

#include "validationQuery.h"

void consumirNuevaLinea(void){
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
}

int main(){

    int opcion, validate;
    char query[300];
    bool controller=false;

    printf( "\n   Bienvenido al menu de la práctica de Sist Op y Lab 2021-2");

    do{
      opcion=0;
      printf( "\n   1. Ingresar su petición psinfo");
      printf( "\n   2. Finalizar programa." );
      printf( "\n\n   Introduzca opcion (1-2): ");
      scanf( "%i", &opcion);
      consumirNuevaLinea();

      switch (opcion){
          case 1:
            printf( "\n\n   Introduzca su peticion: ");
            fgets(query, 300, stdin);
            controller = validateQuery(query);
            printf("%s", controller?"true":"false");
            if(controller){
              printf( "\n\n La petición es válida");
            } else{
              printf( "\n\n La petición no es válida");
            }
            printf("\n\n");
            break;

          case 2:
            return 0;
            
          default:
            printf( "\nOpcion no válida\n\n");
            break;
          }

    } while ( opcion != 2 );
    
    return 0;
}