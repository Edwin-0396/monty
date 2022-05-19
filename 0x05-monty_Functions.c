#include "monty.h"

/**
 * _add - Function that adds the top two elements of the stack
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL || (*stack)->prev == NULL)
		add_error(line_number);

	(tmp->prev)->n = tmp->n + (tmp->prev)->n;
	_pop(stack, line_number);
}

/**
 * _nop - Function that do anything
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: Void
 **/

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
