/**
 * @file stackArrayList.c
 * 
 * @brief Provides an implementation of the ADT Stack with an array list
 * as the underlying data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "stack.h" 
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 20

typedef struct stackImpl { 
    StackElem *elements;   
    int capacity;     
    int size;      
} StackImpl;

static bool ensureCapacity(PtStack stack) {
    if (stack->size == stack->capacity) {
        int newCapacity = stack->capacity * 2;
        StackElem* newArray = (StackElem*) realloc( stack->elements, 
                                newCapacity * sizeof(StackElem) );
        
        if(newArray == NULL) return false; 

        stack->elements = newArray;
        stack->capacity = newCapacity;
    }
    
    return true;
}

PtStack stackCreate() {
    PtStack stack = NULL;

    //TODO (allocation and initialization algorithm)
    // return appropriate error codes

    return stack;
}

int stackDestroy(PtStack *ptStack) {
    PtStack stack = (*ptStack);
    if (stack == NULL) return STACK_NULL;

    //TODO (free resources)

    *ptStack = NULL;

    return STACK_OK;
}

int stackPush(PtStack stack, StackElem elem) {
    if (stack == NULL) return STACK_NULL;
    
    if(!ensureCapacity(stack)) return STACK_NO_MEMORY;

    //TODO (insert 'elem' at the end of the sequence)

    return STACK_OK;
}

int stackPop(PtStack stack, StackElem *ptElem) {
    if (stack == NULL) return STACK_NULL;

    if (stack->size == 0) return STACK_EMPTY;

    //TODO (discard and return by reference last element of sequence)

    return STACK_OK;
}

int stackPeek(PtStack stack, StackElem *ptElem) {
    if (stack == NULL) return STACK_NULL;

    if (stack->size == 0) return STACK_EMPTY;

    //TODO (return by reference last element of sequence)

    return STACK_OK;
}

int stackSize(PtStack stack, int *ptSize) {
    if (stack == NULL) return STACK_NULL;

    //TODO (return by reference the size of the current sequence)

    return STACK_OK;
}

bool stackIsEmpty(PtStack stack) {
    if (stack == NULL) return true;

    return (stack->size == 0);
}

int stackClear(PtStack stack) {
    if (stack == NULL) return STACK_NULL;

    stack->size = 0;

    //TODO (if allocated space is greater than INITIAL_CAPACITY, cap it)

    return STACK_OK;
}

void stackPrint(PtStack stack) {
    if (stack == NULL) {
        printf("(Stack NULL)\n");
    }
    else if (stackIsEmpty(stack)) {
        printf("(Stack Empty)\n");
    }
    else {
        printf("Stack contents (top to bottom): \n");
    
        //TODO (print each element of the sequence from last to first)
        
        printf("--- bottom --- \n");
    }
    printf("\n");
}

