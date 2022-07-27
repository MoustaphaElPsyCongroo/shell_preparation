#include <stdio.h>
#include <string.h>

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
	int equal = 0;
	char *value = NULL;

	while (environ[j])
	{
		i = 0;

		while (environ[j][i] != '=')
		{
			if (environ[j][i] == name[i])
				i++;
			else
				break;
		}

		if (environ[j][i] == '=')
		{
			value = &(environ[j][i + 1]);
			break;
		}

		j++;
	}

	return (value);
}

/**
 * printpath - Prints each directory of the PATH
 */
void printpath(void)
{
	char *pth;
	char *cur_word;

	pth = _getenv("PATH");

	cur_word = strtok(pth, " ");

	while (cur_word)
	{
		printf("%s\n", cur_word);
		cur_word = strtok(NULL, " ");
	}
}

/**
 * main - Execute printpath
 *
 * Return: 0
 */
int main(void)
{
	printpath();

	return (0);
}
