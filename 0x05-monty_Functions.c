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
	stack_t *current = *stack;
	int count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		if (tmp == NULL || (*stack)->next == NULL)
			add_error(line_number);
	}

	(tmp->next)->n = tmp->n + (tmp->next)->n;
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
