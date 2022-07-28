#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * split - Splits a string and stores each word in an array
 * @str: The string
 *
 * Return: A pointer to the resulting array, or NULL if fail
 */
char **split(char *str)
{
	int i = 0;
	int buf = 1024;
	char **spl;
	char *cur_word;

	spl = malloc(sizeof(char) * buf);

	if (spl == NULL)
	{
		perror("Error: can't allocate memory");
		return (NULL);
	}

	cur_word = strtok(str, " ");

	while (cur_word)
	{
		spl[i] = cur_word;
		i++;
		cur_word = strtok(NULL, " ");
	}
	spl[i] = NULL;

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

	free(arr);

	return (0);
}
