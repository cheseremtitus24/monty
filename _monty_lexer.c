/*

    This program illustrates reading and parsing
    command-line input based on whitespace.

*/

#include "monty.h"
/**
 * _istoken- Identifies keywords in character stream
 * @str: Input String
 *
 * Description- Identifies key words as substrings
 *
 * Return: boolean value
 */

bool _istoken(const char *str) {
    char *strd = strdup(str);
    if (!strd)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    strd = _string_toupper(strd);
    /**
     * PUSH<SPACE><INTEGER>
     * POP - removes top item of stack
     * PINT - prints the value at top of stack followd by new line
     * PALL - prints all the items in the stack
     * SWAP - swaps the top 2 elems of stack
     * ADD - adds the top 2 elems of stack - pop 2ice then push result once
     * NOP - does nothing
     *
     */

    if (!strcmp(strd, "PUSH") || !strcmp(strd, "PALL") || !strcmp(strd, "POP") || !strcmp(strd, "PINT") ||
        !strcmp(strd, "SWAP") || !strcmp(strd, "ADD") || !strcmp(strd, "NOP"))
    {

        free(strd);
        return true;
    }
    free(strd);
    return false;
}

void _monty_lexer(char *buffer, const unsigned int file_line_number, stack_t **start) {

    const char *whitespace = " \n\r\f\t\v";
    /*char buffer[81];*/
    char *token;
    bool push_flag;
    char *push_cmd;
    int __attribute__((unused))push_int;
    char *strd;
    unsigned int check_line_pos;
    void (*op)(stack_t **, unsigned int);
    void (*op_p)(stack_t **, unsigned int, int);

    /* initialize push_flag to false*/
    push_flag = false;

    check_line_pos = strlen(buffer);

    /* Print the command as entered. */

    /*printf("\nThis is the command as entered:  %s\n", buffer);*/

    token = strtok(buffer, whitespace);

    while (token != NULL) {

        /**
         * Check if the token is a valid token
         */
        check_line_pos -= strlen(token);
        check_line_pos--;
        /*check_line_pos -= strlen(whitespace);*/
        /*printf("consumed line length is %d\n", check_line_pos);*/

        if (_istoken(token) || push_flag == true)
        {
            /**
             * PUSH<SPACE><INTEGER>
             * POP - removes top item of stack
             * PINT - prints the value at top of stack followd by new line
             * PALL - prints all the items in the stack
             * SWAP - swaps the top 2 elems of stack
             * ADD - adds the top 2 elems of stack - pop 2ice then push result once
             * NOP - does nothing
             *
             */

            strd = strdup(token);
            if (!strd)
            {
                fprintf(stderr, "Error: malloc failed\n");
                free(buffer);
                exit(EXIT_FAILURE);
            }    /* check that we are not at end of line*/
            strd = _string_toupper(strd);
            if (((!strcmp(strd, "PUSH") && check_line_pos > 0) || (push_flag == true && check_line_pos > 0)))
            {
                free(strd);
                /**
                 * Push we are expecting an integer value
                 * This parser function should pass everything
                 * blindly and should not handle any string to integer conversions
                 */

                /* skip to next iter so that we capture integer value*/
                if (push_flag == false) {
                    push_flag = true;
                    /*push_cmd = strcat(push_cmd, token);*/
                    /* duplicate the string to dynamic memory string*/
                    push_cmd = strdup(token);
                    /* Check to ensure that string dup was successful*/
                    if (push_cmd == NULL) {
                        fprintf(stderr, "Erro: malloc failed\n");
                        free(buffer);
                        exit(EXIT_FAILURE);

                    }
                    /*printf("command: %s\n", push_cmd);*/

                    token = strtok(NULL, whitespace);
                    /* handle when push is called with no arguments*/
                    if (!token)
                    {
                        fprintf(stderr, "L %u: usage: push integer\n",file_line_number);
                        free(push_cmd);
                        free(buffer);
                        exit(EXIT_FAILURE);
                    }
                    continue;
                }

                if (push_flag == true) {
                    /*push_cmd = strcat(push_cmd, token);*/
                    /* expand the push_cmd space in order to concatenate opcode + operand*/
                    push_cmd = _realloc(push_cmd, sizeof(push_cmd), (sizeof(push_cmd) + sizeof(token)));
                    push_cmd = strcat(push_cmd, " ");
                    push_cmd = strcat(push_cmd, token);
                    /*printf("operand: %s\n", token);*/
                    /*printf("command + token: %s\n", push_cmd);*/
                    push_flag = false;
                    /* Send string to processing function pointer */
                    op_p = get_op_p_func(push_cmd);
                    push_int = _atoi(push_cmd);
                    if (check_if_digit(token))
                    {
                        /* free the string once processing is complete*/
                        free(push_cmd);
                        op_p(start, file_line_number, push_int);
                    }
                    else
                    {

                        fprintf(stderr, "L %u: usage: push integer\n",file_line_number);
                        free(push_cmd);
                        free(buffer);
                        exit(EXIT_FAILURE);
                    }

                }

            }
                /* Handle when command is another Token other than push is at end of readline*/
            else {
                push_flag = false;
                /*fprintf(stderr, "L %u: unknown instruction %s\n",file_line_number, token);*/
                /*printf("command + token: %s\n", token);*/
                op = get_op_func(token);
                op(start, file_line_number);
		/*exit(EXIT_FAILURE);*/
            }
            /*printf("Everything is a token\n");*/
        }

        /*printf("%s\n", token);*/
        token = strtok(NULL, whitespace);

    }

}
