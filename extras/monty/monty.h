#ifndef __MONTY__
#define __MONTY__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char *_string_toupper(char *s);
void _trim(char *str);
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*adds operand to stack*/
bool monty_push(stack_t **stack, unsigned int line);
/*removes top stack operand*/
bool monty_pop(stack_t **stack, unsigned int line);
/*prints all stack elements*/
bool monty_pall(stack_t **stack, unsigned int line);
/*prints the top stack element*/
bool monty_pint(stack_t **stack, unsigned int line);
/*swaps the top 2 stack elements*/
bool monty_swap(stack_t **stack, unsigned int line);
/* Performs a no op*/
bool monty_nop(stack_t **stack, unsigned int line);
/* Adds top 2 elements of a stack deletes the two elements and pushes the result onto the stack*/
bool monty_add(stack_t **stack, unsigned int line);

#endif /* MONTY DEFN*/
