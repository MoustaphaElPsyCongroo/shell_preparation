#include <stdio.h>

extern char **environ;

/**
 * main - Prints the environment
 *
 * Return: 0
 */
int main(void)
{
	int i = 0;

	while (environ[i])
		printf("%s\n", environ[i++]);

	return (0);
}
