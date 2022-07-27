#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Prints the command entered by the user
 *
 * Return: Number of characters read, -1 if fail
 */
int main(void)
{
	ssize_t rd;
	size_t n = 0;
	char *line = NULL;


	printf("$ ");

	while ((rd = getline(&line, &n, stdin)) != -1)
	{
		printf("%s", line);
		printf("$ ");
	}

	/*	rd = getline(&line, &n, stdin);

		if (rd == -1)
		printf("Can't read");
		else
		printf("%s", line);
		*/
	free(line);

	return (0);
}
