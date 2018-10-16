//
//  Stack.h
//  
//
//  Created by Nicholas Romano on 10/16/18.
// Modification of

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdbool.h>

typedef struct Stack Stack;
typedef struct StackNode StackNode;

extern Stack *Stack_new();

extern StackNode * StarckNode_new(char data);

extern void Stack_free(Stack *stack, bool free_data_also);

extern bool Stack_is_empty(const Stack *stack);

extern void Stack_push(Stack *stack, char value);

extern char Stack_pop(Stack *stack);



#endif /* Stack_h */
