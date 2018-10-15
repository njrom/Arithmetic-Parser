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
    printf("Recursive Decent Parser for Arithmetic Expressions\n");
    printf("--------------------------------------------------\n");
    printf("Enter an Arithmetic Expression with no spaces: \n\n");
    scanf("%s", expression);
    printf("Parsing on: %s \n", expression);
    printf("--------------------------------------------------\n");
    printf("----------------------|Tree|----------------------\n");
    printf("--------------------------------------------------\n");
    
    look_ahead = expression;
    parseTree = categoryE();
    Tree_print(parseTree,1,0);

}

