#include "monty.h"

/**
 * opcode_instruction - compares instructions to opcodes and calls functions
 * Return: 0 on success, EXIT_FAILURE on error
 **/

int opcode_instruction(void)
{
	int i = 0;
	instruction_t OPcode[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}};
	i = 0;
	while (OPcode[i].opcode)
	{
		if (strcmp(OPcode[i].opcode, handle.token1) == 0)
		{
			OPcode[i].f(&handle.head, handle.line_number);
			break;
		}
		i++;
	}
	if (!OPcode[i].opcode)
	{
		fprintf(stderr, "L%lu: unknown instruction %s\n",
				handle.line_number, handle.token1);
		free_all();
		exit(EXIT_FAILURE);
	}
	return (0);
}
