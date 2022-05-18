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