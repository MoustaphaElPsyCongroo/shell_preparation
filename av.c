#include <stdio.h>

/**
 * main - Prints all this program's arguments, without argc
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	int i = 0;

	while (argv[i])
	{
		printf("%s", argv[i++]);
	}


	return (0);
}
