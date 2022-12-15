/*

    This program illustrates reading and parsing
    command-line input based on whitespace.

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// todo: Remove extra spaces in between words

bool _istoken(char *str)
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

	if (!strcmp(str, "PUSH") || !strcmp(str, "PALL") || !strcmp(str, "POP") || !strcmp(str, "PINT") || !strcmp(str, "SWAP") || !strcmp(str, "ADD") || !strcmp(str, "NOP"))
		return true;
	return false;
}

int main()
{

    const char* whitespace = " \n\r\f\t\v";
    char buffer[81];
    char* token;
    bool push_flag;
    char *push_cmd;
    unsigned int check_line_pos;

    /* initialize push_flag to false*/
    push_flag = false;

    /* Start an endless loop. */

    while (1)
    {

        /* Read in up to 80 characters or until the newline is encountered. */

        printf("\nEnter command:  ");
        fgets(buffer, 81, stdin);
	check_line_pos = strlen(buffer);

        /* Print the command as entered. */

        printf("\nThis is the command as entered:  %s\n", buffer);

        /* Print the command broken into whitespace-delimited tokens. */

        printf("\nThis is the command parsed into whitespace-delimited tokens (one per line):  \n\n");

        token = strtok(buffer, whitespace);

        while (token != NULL)
        {

	/**
	 * Check if the token is a valid token
	 */
		check_line_pos -= strlen(token);
		check_line_pos --;
		//check_line_pos -= strlen(whitespace);
		printf("consumed line length is %d\n",check_line_pos);
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

			/* check that we are not at end of line*/
			if(((!strcmp(token, "PUSH") && check_line_pos > 0 ) || push_flag == true) )
			{
				/**
				 * Push we are expecting an integer value
				 * This parser function should pass everything
				 * blindly and should not handle any string to integer conversions
				 */

				/* skip to next iter so that we capture integer value*/
				if(push_flag == false)
				{
					push_flag = true;
					/*push_cmd = strcat(push_cmd, token);*/
					/* duplicate the string to dynamic memory string*/
					push_cmd = strdup(token);
					/* Check to ensure that string dup was successful*/
					if (push_cmd == NULL)
					{
						fprintf(stderr, "Erro: malloc failed\n");
						exit(EXIT_FAILURE);

					}
					printf("command: %s\n",push_cmd);

				    token = strtok(NULL, whitespace);
				    continue;
				}

				if (push_flag == true)
				{
					/*push_cmd = strcat(push_cmd, token);*/
					/* expand the push_cmd space in order to concatenate opcode + operand*/
					push_cmd = realloc(push_cmd, sizeof(token));
					push_cmd = strcat(push_cmd, " ");
					push_cmd = strcat(push_cmd, token);
					printf("operand: %s\n",token);
					printf("command + token: %s\n", push_cmd);
					push_flag = false;
					/* Send string to processing function pointer */

					/* free the string once processing is complete*/
					free(push_cmd);
				}

			}
			/* Handle when PUSH is at end of readline*/
			else
			{
				push_flag = false;
				fprintf(stderr, "L 3: unknown instruction %s\n", token);
				free(push_cmd);

				exit(EXIT_FAILURE);
			}
			/*printf("Everything is a token\n");*/
		}
		
            /*printf("%s\n", token);*/
            token = strtok(NULL, whitespace);

        }

    }

    return 0;

}
