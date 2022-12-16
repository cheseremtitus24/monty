/* Created by lab on 12/15/22.*/
#include "monty.h"

int
main (int argc, char *argv[])
{
  unsigned int line_counter;
  char line[MAX_LINE_SIZE];
  char *opcode;
  char *fileName;
  FILE *file;
  stack_t *start;

  start = NULL;

  if (argc != 2)
    {
      fprintf (stderr, "USAGE: %s file\n", argv[0]);
      exit (EXIT_FAILURE);
    }
  fileName = argv[1];
  file = fopen (fileName, "r");	/* should check the result */

  if (file == NULL)
    {
      fprintf (stderr, "Error: Can't open file %s\n", argv[1]);
      exit (EXIT_FAILURE);
    }


  line_counter = 0;
  while (fgets (line, sizeof (line), file))
    {
      line_counter++;
      /**
       * note that fgets don't strip the terminating \n
       * , checking its presence would allow to handle
       * lines longer that sizeof(line)
       */

      /* Trims leading and trailing whitespaces */
      _trim (line);

      /* trims extra spaces in between sentence returns heap alloc variable */
      opcode = _trim_inbtwn_spaces (line);

      /* Converts all characters to their equivalent Capital Letters */
      /*opcode = _string_toupper(opcode); */

      /*printf("line %d - %s\n",line_counter, opcode); */

      /* pass in the doubly linked stack by ref */
      _monty_lexer (opcode, line_counter, &start);

      /* After finished processing of opcode free it */
      free (opcode);
    }
  /* may check feof here to make a difference between eof and io failure -- network
     timeout for instance */

  fclose (file);

  return (0);
}
