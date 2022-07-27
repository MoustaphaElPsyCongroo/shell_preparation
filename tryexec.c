#include <stdio.h>
#include <unistd.h>

/**
 * main - Trying execve
 * @ac: Arg count
 * @av: Arg vector
 * @env: Env vector
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	av++;
	printf("Before execve\n");

	if (execve(av[0], av, env) == -1)
		perror("Error");

	printf("After execve, never executed\n");
	return (0);
}
