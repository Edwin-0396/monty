#include "monty.h"
handlers handle;

/**
 *
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
		error_argv();

	handle.fp = fopen(argv[1], "r");
	if (handle.fp == NULL)
		open_error(&argv[1]);

	monty_interpreter();

	return (0);
}
