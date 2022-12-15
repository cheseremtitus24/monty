/* Created by lab on 12/15/22. */
#include "monty.h"

/*adds operand to stack*/
void monty_push(stack_t **stack, unsigned int line, int n) {
    /*printf("monty inserting %d\n", n);*/
    push(stack, n);
}

/*removes top stack operand*/
void monty_pop(stack_t **stack, unsigned int line) {
    pop(stack, line);
}

/*prints all stack elements*/
void monty_pall(stack_t **stack, unsigned int line) {
    printstack(stack);
}

/*prints the top stack element*/
void monty_pint(stack_t **stack, unsigned int line) {
    topelement(stack, line);
}

/*swaps the top 2 stack elements*/
void monty_swap(stack_t **stack, unsigned int line) {
    extern stack_t *top;
    int ttop;
    int stop;
    int stack_size;

   stack_size = stacksize(stack);
   if (stack_size < 2)
   {
       fprintf(stderr, "L %u: can't swap, stack too short\n", line);
       exit(EXIT_FAILURE);
   } else
   {
       ttop = top->n;
       pop(stack, 0);
       stop = top->n;
       pop(stack, 0);
       push(stack, ttop);
       push(stack, stop);
   }

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
    int stack_size;

    stack_size = stacksize(stack);
    if (stack_size < 2)
    {
        fprintf(stderr, "L %u: can't add, stack too short\n", line);
        exit(EXIT_FAILURE);
    } else
    {

        ttop = top->n;
        pop(stack, 0);
        stop = top->n;
        pop(stack, 0);

        result = ttop + stop;
        push(stack, result);
    }




}

