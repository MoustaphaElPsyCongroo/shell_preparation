#include <stdio.h>

extern char **environ;

/**
 * main - Prints env and environ's address
 *
 * Return: 0
 */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
	printf("%p\n", (void *)environ);
	printf("%p\n", (void *)env);

	return (0);
}
