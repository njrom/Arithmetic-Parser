//
//  RDP.h
//  
//
//  Created by Nicholas Romano on 10/12/18.
//

#ifndef RDP_h
#define RDP_h

typedef struct Node* Tree;

struct Node{
    char label;
    Tree LMC;
    Tree RS;
}

char *look_ahead;

Tree parseTree;

// Functions that return subtrees

Tree categoryE();

Tree categoryAS();

Tree categoryT();

Tree categoryMD();

Tree categoryF();

Tree categoryN();

Tree categoryPN();

Tree categoryD();

Tree newTree_zero(char x);

Tree newTree_one(char x,Tree tree);

Tree newTree_two(char x,Tree tree1, Tree tree2);

Tree newTree_three(char x, Tree tree1, Tree tree2, Tree tree3);
 void Tree_print(Tree treeToPrint, int start, int numIndented);//int start is a boolean val of if on the root node
#endif /* RDP_h */
