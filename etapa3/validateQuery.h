#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
    }
    return 0;
}