#include "monty.h"

/**
* main - Main program instructions
* @argc: total of arguments
* @argv: The arguments, monty files
* Return: int
**/

int main(int argc, char **argv)
{
	handle.n = 0;
	handle.line_number = 0;
	handle.token1 = NULL;
	handle.head = NULL;

	if (argc != 2)
		argv_error();

	handle.fp = fopen(argv[1], "r");
	if (handle.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	monty_interpreter();
	free_all();

	return (0);
}
