#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 *
 * Description: Space for the new string is obtained with malloc, must be freed
 * Return: A pointer to the new string, or NULL if fail
 */
char *_strdup(char *str)
{
	int length = 0;
	int i;
	char *s;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	s = malloc(sizeof(char) * (length + 1));

	if (s == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		s[i] = str[i];

	return (s);
}

/**
 * split - Splits a string and stores each word in an array
 * @str: The string
 *
 * Return: A pointer to the resulting array, or NULL if fail
 */
char **split(char *str)
{
	int i = 0;
	int words = 0;
	char **spl;
	char *temp_str = NULL;
	char *cur_word = NULL;

	if (str == NULL)
		return (NULL);

	temp_str = _strdup(str);

	if (temp_str == NULL)
		return (NULL);

	cur_word = strtok(temp_str, " ");

	while (cur_word)
	{
		words++;
		cur_word = strtok(NULL, " ");
	}

	spl = malloc(sizeof(char) * words);

	if (spl == NULL)
		return (NULL);

	cur_word = strtok(str, " ");
	i = 0;

	while (cur_word)
	{
		spl[i] = _strdup(cur_word);
		cur_word = strtok(NULL, " ");
		i++;
	}

	free(temp_str);
	return (spl);
}

int main(void)
{
	char str[] = "Hello world!";
	char **arr = split(str);
	int i = 0;

	if (arr == NULL)
	{
		printf("Error: arr can't be NULL");
		exit(-1);
	}

	printf("%s", arr[0]);

	while (arr[i])
		free(arr[i++]);
	free(arr);

	return (0);
}
