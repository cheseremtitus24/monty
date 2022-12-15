/* Created by lab on 12/15/22.*/
#include "monty.h"
/**
 * trim- Remove leading and trailing white space characters
 * @str: string to be trimmed
 * Example: _trim(" Hello ") modifies input string to "Hello"
 * Return: void
 */
char *_trim_inbtwn_spaces(const char * str)
{
    int i, j;
    char * newString;

    newString = (char *)malloc(MAX_LINE_SIZE);

    i = 0;
    j = 0;

    while(str[i] != '\0')
    {
        /* If blank space is found */
        if(str[i] == ' ')
        {
            newString[j] = ' ';
            j++;

            /* Skip all consecutive spaces */
            while(str[i] == ' ')
                i++;
        }

        newString[j] = str[i];

        i++;
        j++;
    }
    // NULL terminate the new string
    newString[j] = '\0';

    return newString;
}

