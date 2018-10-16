//
//  TableParser.h
//  
//
//  Created by Nicholas Romano on 10/16/18.
//

#ifndef TableParser_h
#define TableParser_h
#include "Stack.h"

int TableParser_run(char* inputString);
int is_terminal(char c);
int is_operator(char c);
int char_toIndex(char c);
int prod_toIndex(char c);

#endif /* TableParser_h */
