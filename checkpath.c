#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

/**
 * _strlen - Gets the length of a string
 * @s: The string to evaluate
 *
 * Return: s' length
 */
int _strlen(char *s)
{
	char *i;
	int count = 0;

	for (i = s; *i > 0; i++)
		count++;

	return (count);
}

/**
 * _strcpy - Copies a string to a buffer
 * @dest: The buffer where to copy the string to
 * @src: The string to copy
 *
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = 0;

	return (dest);
}

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
 * alloc_concat - Concatenates two strings, allocating memory for them
 * @dest: Destination string
 * @tocat: String to concatenate to dest
 *
 * Return: A pointer to the new string, or NULL if fail
 */
char *alloc_concat(char *dest, char *tocat)
{
	int len1;
	int len2;
	char *s;

	len1 = _strlen(dest);
	len2 = _strlen(tocat);

	s = malloc(len1 + len2 + 1);
	if (s == NULL)
		return (NULL);

	s = _strcpy(s, dest);
	s = _strcat(s, tocat);

	return (s);
}

/**
 * checkpath - Search for files in the PATH
 * @filename: The name of the file to search
 *
 * Return: A pointer to the alloc'd full path of the file, or NULL if fail
 */
char *checkpath(char *filename)
{
	char *path = _getenv("PATH");
	char *cur_folder = NULL;
	char *folder_sep = "/";
	char *slash_filename;
	char *filepath;
	int fn_length = _strlen(filename);
	struct stat st;

	slash_filename = alloc_concat(folder_sep, filename);
	if (slash_filename == NULL)
		return (NULL);

	cur_folder = strtok(path, ":");

	while (cur_folder)
	{
		filepath = alloc_concat(cur_folder, slash_filename);
		if (filepath == NULL)
			return (NULL);

		if (stat(filepath, &st) != 0)
		{
			free(filepath);
			cur_folder = strtok(NULL, ":");
		}
		else
		{
			free(slash_filename);
			return (filepath);
		}
	}

	free(slash_filename);
	return (NULL);
}

int main(void)
{
	char *s = checkpath("bety");

	printf("%s", s);
	free(s);

	return (0);
}
