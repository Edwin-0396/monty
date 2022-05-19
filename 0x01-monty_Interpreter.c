#include "monty.h"

/**
 * monty_interpreter - processes monty instructions
 * Return: 0 on success, EXIT_FAILURE on error
 **/

int monty_interpreter(void)
{
	while ((getline(&handle.buffer, &handle.n, handle.fp)) != EOF)
	{
		handle.line_number++;
		handle.token1 = strtok(handle.buffer, " $\n");
		if (handle.token1 == NULL || handle.token1[0] == ' ')
			continue;
		if (strcmp(handle.token1, "push") == 0)
		{
			handle.token2 = strtok(NULL, " $\n");
			if (!handle.token2)
			{
				fprintf(stderr, "L%lu: usage: push integer\n", handle.line_number);
				free_all();
				exit(EXIT_FAILURE);
			}
			_isnumber();
		}
		opcode_instruction();
	}
	return (0);
}
