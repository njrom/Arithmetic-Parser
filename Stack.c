//
//  Stack.c
//  
//
//  Created by Nicholas Romano on 10/16/18.
//

#include "Stack.h"

typedef struct Stack {
    struct StackNode *first;
}Stack;

typedef struct StackNode {
    char data;
    struct StackNode *next;
}StackNode;


Stack *Stack_new() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->first = NULL;
    return stack;
}

StackNode * StarckNode_new(char data) {
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    if (node == NULL) {
        return NULL; // Out of memory
    }
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * Free the memory used for the given Stack.
 * If boolean free_data_also is true, also free the data associated with
 * each element.
 */
void Stack_free(Stack *stack) {
    // Free the elements
    StackNode *elt = stack->first;
    while (elt != NULL) {
        StackNode *next = elt->next;
        free(elt);
        elt = next;
    }
    // Free the list itself
    free(stack);
}

bool Stack_is_empty(const Stack *stack) {
    return stack->first == NULL;
}

void Stack_push(Stack *stack, char value) {
    StackNode *node = StackNode_new(value);
    node->next = stack->first;
    stack->first = node;
}

char Stack_pop(Stack *stack) {
    char data = '\0'; // EOF returned if stack is empty
    if (stack->first != NULL) {
        if (stack->first->data != '\0') {
            data = stack->first->data;
            if (stack->first->next != NULL) { // Another element is in the stack
                stack->first = stack->first->next;
            } else {
                stack->first = NULL;
            }
        }
    }
    return data;
}
