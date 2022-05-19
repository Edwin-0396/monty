#include "monty.h"

/**
 * error_argv - If user doesnt give file or more than valid arguments
 * Return: void
 **/

void error_argv(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}


/**
 * invalid_instrution - print message if le to open the
 * filehas an invalid instruction
 * @line: line of file
 * @opcode: command to execute.
 * Return: void
 **/

void invalid_instrution(int line, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Print message if can´t malloc
 * Return: Void
 **/

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	/*free_everything();*/
	exit(EXIT_FAILURE);
}
