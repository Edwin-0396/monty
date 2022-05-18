#include "monty.h"

/**
 *
 * @argc: total of arguments
 * @argv: The arguments, monty files
 * Return: int
**/

int main(int argc, char **argv)
{
	char *buf;
	int count = 0;

	char *token = NULL, *temp_buf = NULL;

	if (argc != 2) /* Verifies if the function recives 2 arguments */
		return (-1);
		/*error_argv();*/

	/*op_re_file(argv);*/
	buf = read_textfile(argv[1], 114);
	count = count_words(buf);

	temp_buf = _strdup(buf);
	token = strtok(temp_buf, "\n");
	printf("Printed chars:\n%s\nn_words: %d\ntoken: %d\n %s\n\n", buf, count, _strlen(token), token);

	
	while(token)
	{
		printf("%s\n", token);
		token = strtok(NULL, "\n");
		printf("%d", _strlen(token));
	}

	free(buf);
	return (0);
}
