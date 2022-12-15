#ifndef __MONTY__
#define __MONTY__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 256
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

/* file: _string_toupper.c*/
char *_string_toupper(char *s);
/* file: _trim.c*/
void _trim(char *str);
/* file: _trim_inbtwn_spaces.c*/
char *_trim_inbtwn_spaces(const char * str);
/* file: _montylexer.c*/
bool _istoken(const char *str); /* identifies monty keywords*/
void _monty_lexer(char *buffer, const unsigned int file_line_number, stack_t **start); /* identifies tokens in an input string*/
/* file: _realloc.c*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* file: get_op_func.c*/
void (*get_op_func(char *s))(stack_t **, unsigned int);
void (*get_op_p_func(char *s))(stack_t **, unsigned int, int);


/* file: monty.c - doubly linked list stack*/
bool isEmpty(stack_t **start);
void push(stack_t **start, int d);
void pop(stack_t **start);
void topelement(stack_t **start);
void stacksize(stack_t **start);
void printstack(stack_t **start);

int _atoi(char *s);
bool check_if_digit(const char *s);

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
void monty_push(stack_t **stack, unsigned int line, int n);
/*removes top stack operand*/
void monty_pop(stack_t **stack, unsigned int line);
/*prints all stack elements*/
void monty_pall(stack_t **stack, unsigned int line);
/*prints the top stack element*/
void monty_pint(stack_t **stack, unsigned int line);
/*swaps the top 2 stack elements*/
void monty_swap(stack_t **stack, unsigned int line);
/* Performs a no op*/
void monty_nop(stack_t **stack, unsigned int line);
/* Adds top 2 elements of a stack deletes the two elements and pushes the result onto the stack*/
void monty_add(stack_t **stack, unsigned int line);

#endif /* MONTY DEFN*/
