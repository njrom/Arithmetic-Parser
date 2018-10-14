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
#define COUNT 10

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(Tree root, int space)
{
    // Base case
    if (root == NULL)
        return;
    
    // Increase distance between levels
    space += COUNT;
    
    // Process right child first
    print2DUtil(root->RS, space);
    
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->label);
    
    // Process left child
    print2DUtil(root->LMC, space);
}

// Wrapper over print2DUtil()
void print2D(Tree root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

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
    print2D(parseTree);
    printf("\n");

}



