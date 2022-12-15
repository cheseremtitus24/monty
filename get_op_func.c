/* Created by lab on 12/15/22. */
#include "monty.h"
/**
 * get_op_func- Is a pointer to a function
 * @s: character pointer argument
 *
 * Description- returns a pointer to a function that takes in two int arguments
 *
 * Return: Pointer to a function else NULL
 */

void (*get_op_func(char *s))(stack_t **, unsigned int)
{
    /* array of structs */
    instruction_t ops[] = {
            { "POP", monty_pop},
            { "PALL", monty_pall},
            { "PINT", monty_pint},
            { "SWAP", monty_swap},
            { "NOP", monty_nop},
            { "ADD", monty_add},
            { NULL, NULL}
    };
    int i;
    char *strd;

    strd = strdup(s);
    if (!strd)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }    /* check that we are not at end of line*/
    strd = _string_toupper(strd);
    i = 0;
    while (i < (int)sizeof(ops))
    {
        if (strcmp(strd,ops[i].opcode) == 0 && strd != NULL && ops[i].f != NULL)
        {
            free(strd);
            return (ops[i].f);
        }
        i++;
    }

    free(strd);
    return (NULL);

}

void (*get_op_p_func(char *s))(stack_t **, unsigned int, int)
{
    /* array of structs */
    instruction_t ops[] = {
            { "PUSH", monty_push},
            { NULL, NULL}
    };
    int i;
    char *strd;

    strd = strdup(s);
    if (!strd)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }    /* check that we are not at end of line*/
    strd = _string_toupper(strd);
    i = 0;
    while (i < (int)sizeof(ops))
    {
        if (strstr(ops[i].opcode, strd) == 0 && strd != NULL && ops[i].f != NULL)
        {
            free(strd);
            return (ops[i].f);
        }
        i++;
    }
    free(strd);

    return (NULL);

}



