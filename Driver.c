//
//  Driver.c
//  
//
//  Created by Nicholas Romano on 10/14/18.
//


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "RDP.h"

int main(){
    
    //Expression Storage
    char expression[100];
    //Menu Readout
    
    printf("173 Project 1 by Nicholas Romano\n");
    while(1) {
        printf("Recursive Decent Parser for Arithmetic Expressions\n");
        printf("--------------------------------------------------\n");
        printf("Enter an Arithmetic Expression with no spaces (quit) to move on: \n ");
        scanf("%s", expression);
        if(strcmp(expression,"quit") == 0) {
            break;
        }
        look_ahead = expression;
        parseTree = categoryE();
        printf("Parsing on: %s \n", expression);
        if(parseTree == NULL) {
            printf("Invalid input\n");
        } else {
            printf("----------------------|Tree|----------------------\n");
            Tree_print(parseTree,1,0);
            printf("\n");
        }

        
    }


}

