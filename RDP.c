//
//  RDP.c
//  
//
//  Created by Nicholas Romano on 10/12/18.
//

#include "RDP.h"
#include <stdlib.h>
#include <stdio.h>

// Functions for each Syntatic Category
Tree categoryE() {
    Tree t;
    Tree a;
    t = categoryT();
    if (t != NULL) {
        a = categoryA();
        if(a != NULL) {
            return newTree_two('E', t, a);
        } else {
            return NULL;
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
        t = categoryT();
        if(t != NULL) {
            a = categoryA();
            if(a != NULL) {
                return newTree_three('A', newTree_zero('+'), t, a);
            } else {
                return NULL;
            }
        } else {
            return NULL;
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
    if (f != NULL) {
        m = categoryM();
        if (m != NULL) {
            return newTree_two('T', f, m);
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

Tree categoryM() {
    Tree f;
    Tree m;
    f = categoryF();
    if (*look_ahead == '*') {
        look_ahead++;
        if (f != NULL) {
            m = categoryM();
            if (m != NULL) {
                return newTree_three('M', newTree_zero('*'), f, m);
            } else {
                return NULL;
            }
        } else {
            return NULL;
        }
    } else if (*look_ahead == '/'){
        look_ahead++;
        if (f != NULL) {
            m = categoryM();
            if (m != NULL) {
                return newTree_three('M', newTree_zero('/'), f, m);
            } else {
                return NULL;
            }
        } else {
            return NULL;
        }
    } else {
        return newTree_one('M', newTree_zero('e'));
    }
}

Tree categoryF() {
    Tree e;
    Tree n;
    if (*look_ahead == '(') {
        look_ahead++;
        e = categoryE();
        if (e != NULL && *look_ahead == ')') {
            look_ahead++;
            return newTree_three('F', newTree_zero('('), e, newTree_zero(')'));
        } else {
            return NULL;
        }
    } else {
        n = categoryN();
        if(n != NULL) {
            return newTree_one('F', n);
        } else {
            return NULL;
        }
    }
}

Tree categoryN() {
    Tree d;
    Tree p;
    d = categoryD();
    if (d != NULL) {
        p = categoryP();
        if (p != NULL) {
            return newTree_two('N', d, p);
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

Tree categoryP() {
    Tree n;
    if (
        *look_ahead == '\0' || *look_ahead == '*' || *look_ahead == '/' || *look_ahead == ')' ||
        *look_ahead == '+' || *look_ahead == '-' || *look_ahead == '('
        ) {
        return newTree_one('n', newTree_zero('e'));
    } else {
        n = categoryN();
        if (n != NULL) {
            return newTree_one('N', n);
        } else {
            return NULL;
        }
    }
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

Tree newTree_zero(char x) {
    Tree root;
    root = (Tree)malloc(sizeof(struct Node));
    root->label = x;
    root->LMC = NULL;
    root->RS = NULL;
    return root;
}

Tree newTree_one(char x,Tree tree) {
    Tree root;
    root = newTree_zero(x);
    root->LMC = tree;
    return root;
}

Tree newTree_two(char x,Tree tree1, Tree tree2) {
    Tree root;
    root = newTree_one(x, tree1);
    tree1->RS = tree2;
    return root;
}

Tree newTree_three(char x, Tree tree1, Tree tree2, Tree tree3){
    Tree root;
    root = newTree_one(x,tree1);
    tree1->RS = tree2;
    tree2->RS = tree3;
    return root;
}

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
