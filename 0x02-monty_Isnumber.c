#include "monty.h"
/**
 * _isnumber - determines if string is number
 * Return: 0 on success, exits on failure
 **/

int _isnumber(void)
{
	int i = 0;

	if ((!isdigit(handle.token2[0]) && handle.token2[0] != '-') ||
	 (handle.token2[0] == '-' && handle.token2[1] == '\0'))
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
