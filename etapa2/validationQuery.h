#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Retornar si la petición está bien escrita
//En caso de que si establecer si hay una bandera -r -l o no
//Establecer un arreglo de PIDs si es el caso [1...muchos]

void showError(char errorDesc[]){
    printf("\n");
    printf("%s", errorDesc);
    printf("\n");
}

bool validateQuery(char query[]){
    int lengthQuery = strlen(query), state=1;
    char errorMsg[50]= "Error: petición psinfo inválida";

    for (int i = 0; i < lengthQuery; i++){
        
        if(i<=lengthQuery-2){
            
            switch (state){
                case 1:
                    if(query[i]==' '){ 
                        state=1;
                    }else if(query[i]=='p'){ 
                        state=2;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 2:
                    if(query[i]=='s'){ 
                        state=3;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 3:
                    if(query[i]=='i'){ 
                        state=4;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 4:
                    if(query[i]=='n'){ 
                        state=5;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 5:
                    if(query[i]=='f'){ 
                        state=6;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 6:
                    if(query[i]=='o'){ 
                        state=7;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 7:
                    if(query[i]==' '){ 
                        state=8;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 8:
                    if(query[i]==' '){ 
                        state=8;
                    }else if(query[i]=='-'){
                        state=9;
                    }else if(isdigit(query[i])){ //is a number?
                        state=13;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 9:
                    if(query[i]=='l'){ 
                        state=10;
                    }else if(query[i]=='r'){
                        state=11;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 10:
                    if(query[i]==' '){ 
                        state=16;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 11:
                    if(query[i]==' '){ 
                        state=16;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;

                case 12:
                    if(query[i]==' ' || (isdigit(query[i]))){ 
                        state=12;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;
                
                case 13:
                    if(query[i]==' '){ 
                        state=15;
                    }else if(isdigit(query[i])){
                        state=13;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;
                
                case 14:
                    return false;
                    break;
                
                case 15:
                    if(query[i]==' '){ 
                        state=15;
                    }else{
                        showError(errorMsg);
                        state=14; 
                    }
                    break;

                case 16:
                    if(query[i]==' '){ 
                        state=16;
                    }else if(isdigit(query[i])){
                        state=12;
                    }else{
                        showError(errorMsg);
                        state=14;
                    }
                    break;
                    
            }
            
        }else{

            if(state==12 || state==13 || state==15){
                return(true);
            }else{
                return false;
            }
        }
        
    }
}