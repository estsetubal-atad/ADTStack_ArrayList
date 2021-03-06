/**
 * @file main.c
 * 
 * @brief Provides an example program that uses the
 * ADT Stack. Please note that the StackElem type
 * must be defined as 'int'.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main() {
    PtStack stack = stackCreate();
    if(stack == NULL) {
        printf("Could not create the stack. \n");
        return EXIT_FAILURE;
    }

    int number, sum = 0;
    
    while(true) {

        printf("Number (0 to stop)? ");
        scanf("%d", &number);

        if(number == 0) break;

        int error = stackPush(stack, number);
        if( error == STACK_FULL || error == STACK_NO_MEMORY ) {
            printf("The stack reached its max limit.\n");
            break;
        }
    }

    printf("You entered the following numbers in reversed order: \n");
    while(!stackIsEmpty(stack)) {

        stackPop(stack, &number);
        printf("%d ", number);

        sum += number;
    }

    printf("\nTheir sum is: %d \n", sum);

    //Silent testing of size clear function
    printf("\nTesting size and clear functions... Pushing 100 elements...\n");
    for(int i=1; i<=100; i++) {
        stackPush(stack, i);
    }
    int size;
    stackSize(stack, &size);
    printf("Stack size before clear = %d \n", size);
    stackClear(stack);
    stackSize(stack, &size);
    printf("Stack size after clear = %d \n", size);
    printf("Dont forget to check valgrind! \n");
    //

    stackDestroy(&stack);

    return EXIT_SUCCESS;
}