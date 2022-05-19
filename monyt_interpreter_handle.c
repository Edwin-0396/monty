#include "monty.h"
/**
 * monty_interpreter - processes monty instructions
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */

int monty_interpreter(void)
{
	
	while((getline(&handle.buffer, &handle.n, handle.fp)) != EOF)
	{
		handle.line_number++;
		handle.token1 = strtok(handle.buffer, " $\n");
		if (handle.token1 == NULL || handle.token1[0] == ' ')
			continue;
		if(strcmp(handle.token1, "push") == 0)
		{
			handle.token2 = strtok(NULL, " $\n");
			if(!handle.token2)
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

/**
 * opcode_instruction - compares monty instructions to opcodes and calls functions
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
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

/**
 * _isnumber - determines if string is number
 * Return: 0 on success, exits on failure
 */
int _isnumber(void)
{
	int i = 0;

	if ((!isdigit(handle.token2[0]) && handle.token2[0] != '-')
	    || (handle.token2[0] == '-' && handle.token2[1] == '\0'))
	{
		fprintf(stderr, "L%lu: usage: push integer\n",
			handle.line_number);
		/*free_everything();*/
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (handle.token2[i])
	{
		if (!isdigit(handle.token2[i]))
		{
			fprintf(stderr, "L%lu: usage: push integer\n", handle.line_number);
			free_all();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

/**
 * free_all - frees allocated memory
 */
void free_all(void)
{
	free(handle.buffer);
	free_dlistint(handle.head);
	fclose(handle.fp);
}

/**
 * free_dlistint - free a dlistint_t list
 * @head: pointer to stack_t struct
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp = NULL;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}