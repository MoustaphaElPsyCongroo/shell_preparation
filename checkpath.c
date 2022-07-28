#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

/**
 * _strcat - Concatenates two strings
 * @dest: The base string
 * @src: The string to concatenate to dest
 *
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;

	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = 0;

	return (dest);
}

/**
 * _getenv - Gets an environment variable
 * @name: The name of the variable to get
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
 * checkpath - Checks for files in the PATH
 * @filename: The name of the file to search
 *
 * Return: 0 if file exists in PATH, or NULL if fail
 */
int checkpath(char *filename)
{
	char *path = _getenv("PATH");
	char *cur_word = NULL;
	char *folder;
	char *filepath;
	struct stat st;

	cur_word = strtok(path, ":");

	while (cur_word)
	{
		folder = cur_word;
		filepath = _strcat(folder, filename);

		if (stat(filepath, &st) != 0)
		{
			
		}

	}

	return (0);
}

int main(void)
{
	checkpath("test");
}
