//
//  RDP.c
//  
//
//  Created by Nicholas Romano on 10/12/18.
//

#include "RDP.h"


Tree categoryE() {
    Tree t;
    Tree a;
    t = categoryT();
    if (t != NULL) {
        a = categoryA();
        if(as != NULL) {
            return newTree_two('E', t, a);
        } else {
            return NULL
        }
    } else {
        return NULL;
    }
}

Tree categoryA() {
    Tree t;
    Tree a;
    if(*look_ahead == '+') { // Production #1
        look_ahead++;
        t = categoryT()
        if(t != NULL) {
            a = categoryA()
            if(a != NULL) {
                return newTree_three('A', newTree_zero('+'), t, a)
            } else {
                return NULL;
            }
        } else {
            return NULL
        }
    } else if(*look_ahead == '-') { // Production #2
        look_ahead++;
        t = categoryT();
        if(t != NULL) {
            a = categoryA();
            if(a != NULL) {
                return newTree_three('A', newTree_zero('-'), t, a);
            } else {
                return NULL;
            }
        } else {
            return NULL;
        }
    } else {
        return newTree_one('A', newTree_zero('e'));
    }
}

Tree categoryT() {
    Tree f;
    Tree m;
    f = categoryF();
    if (categoryF != NULL) {
        m = categoryM();
        if (md != NULL) {
            return newTree_two('T', f, m);
        }
    }
}

Tree categoryM();

Tree categoryF();

Tree categoryN();

Tree categoryP() {
    
}

Tree categoryD() {
    switch (*look_ahead) {
        case '0':
            look_ahead++;
            return newTree_one('D', newTree_zero('0'));
            break;
        case '1':
            look_ahead++;
            return newTree_one('D', newTree_zero('1'));
            break;
        case '2':
            look_ahead++;
            return newTree_one('D', newTree_zero('2'));
            break;
        case '3':
            look_ahead++;
            return newTree_one('D', newTree_zero('3'));
            break;
        case '4':
            look_ahead++;
            return newTree_one('D', newTree_zero('4'));
            break;
        case '5':
            look_ahead++;
            return newTree_one('D', newTree_zero('5'));
            break;
        case '6':
            look_ahead++;
            return newTree_one('D', newTree_zero('6'));
            break;
        case '7':
            look_ahead++;
            return newTree_one('D', newTree_zero('7'));
            break;
        case '8':
            look_ahead++;
            return newTree_one('D', newTree_zero('5'));
            break;
        case '9':
            look_ahead++;
            return newTree_one('D', newTree_zero('6'));
            break;
        default:
            return NULL;
            break;
    }
}

Tree newTree_zero(char x);

Tree newTree_one(char x,Tree tree);

Tree newTree_two(char x,Tree tree1, Tree tree2);

Tree newTree_three(char x, Tree tree1, Tree tree2, Tree tree3);

void Tree_print(Tree tree, int i, int currentSpacing) {
    if (tree == NULL && i == 1) {
    } else {
        printf("\n");
        for (int i = 0; i < currentSpacing; i++) {
            printf("  ");
        }
        printf("(%c", tree->label);
        if (tree->LMC != NULL) {
            Tree_print(tree->LMC, 0, currentSpacing+1);
        }
        if (tree->RS != NULL) {
            Tree_print(tree->RS, 0, currentSpacing);
        }
    }
}
