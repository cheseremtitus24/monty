/* Created by lab on 12/15/22. */
#include "monty.h"

/*adds operand to stack*/
void monty_push(stack_t **stack, unsigned int line, int n) {
    printf("monty inserting %d\n", n);
    push(stack, n);
}

/*removes top stack operand*/
void monty_pop(stack_t **stack, unsigned int line) {
    pop(stack);
}

/*prints all stack elements*/
void monty_pall(stack_t **stack, unsigned int line) {
    printstack(stack);
}

/*prints the top stack element*/
void monty_pint(stack_t **stack, unsigned int line) {
    topelement(stack);
}

/*swaps the top 2 stack elements*/
void monty_swap(stack_t **stack, unsigned int line) {
    extern stack_t *top;
    int ttop;
    int stop;
    ttop = top->n;
    pop(stack);
    stop = top->n;
    pop(stack);
    push(stack, ttop);
    push(stack, stop);
}

/* Performs a no op*/
void monty_nop(stack_t **stack, unsigned int line) {
    return;
}

/* Adds top 2 elements of a stack deletes the two elements and pushes the result onto the stack*/
void monty_add(stack_t **stack, unsigned int line) {
    extern stack_t *top;
    int ttop;
    int stop;
    int result;
    ttop = top->n;
    pop(stack);
    stop = top->n;
    pop(stack);

    result = ttop + stop;
    push(stack, result);
}

