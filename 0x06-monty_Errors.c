#include "monty.h"

/**
* argv_error - If user doesnt give file or more than valid arguments
* Return: void
**/

void argv_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
* instruction_error - Print message if le to open the file
* has an invalid instruction
* @line_number: line of file
* @opcode: command to execute.
* Return: void
**/

void instruction_error(int line_number, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
* malloc_error - Print message if can´t malloc
* Return: Void
**/

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_all();
	exit(EXIT_FAILURE);
}
