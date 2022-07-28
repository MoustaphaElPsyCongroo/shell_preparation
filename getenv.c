#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * _getenv - Gets an environment variable
 *
 * Return: A pointer to the variable's value string, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i;
	int j = 0;
	char *value = NULL;

	while (environ[j])
	{
		i = 0;

		while (name[i])
		{
			if (environ[j][i] != name[i])
				break;

			i++;
		}

		if (environ[j][i] == '=' && name[i] == 0)
		{
			value = &(environ[j][i + 1]);
			break;
		}

		j++;
	}

	return (value);
}


/**
 * main - Launch getenv
 *
 * Return: 0
 */
int main(void)
{
	char *s = _getenv("PATH");
	char *h = getenv("PATH");

	printf("_getenv: %s\n", s);
	printf("\n-------------------------------\n");
	printf("getenv: %s", h);

	return (0);
}
