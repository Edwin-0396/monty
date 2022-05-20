#include "monty.h"

/**
* pop_error - Print error message if the stack is empty
* @line_number: line number of file
* Return: void
**/

void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

/**
* swap_error - Print error message if the stack is empty.
* @line_number: line number of file
* Return: void.
**/

void swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
* add_error - Print error message if the stack is empty
* @line_number: line number of file
* Return: void.
**/

void add_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
