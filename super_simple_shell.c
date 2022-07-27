#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * split - Splits a string into an array of each word
 * @str: The string to split
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

/**
 * exec_command - Executes a program
 * @path: Array containing the path to the program to execute and arguments
 * @env: Array of strings representing the current environement
 *
 * Return: 0
 */
int exec_command(char **path, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
		perror("Can't create new process");

	if (child_pid == 0)
	{
		if (execve(path[0], path, env) == -1)
		{
			perror("Can't execute this command");
			return (0);
		}
	}
	else
	{
		wait(&status);
	}

	return (1);
}

/**
 * readcommand - Reads a command entered by the user
 * Return: The command read, or NULL if fail
 */
char *readcommand(void)
{
	char *command = NULL;
	ssize_t rd = 0;
	size_t n = 0;

	rd = getline(&command, &n, stdin);

	if (rd == -1)
	{
		free(command);
		exit(0);
	}

	command[rd - 1] = 0;

	return (command);
}

/**
 * main - Super simple shell
 * @ac: Arg count
 * @av: Arg vector
 * @env: Environment
 *
 * Return: 0 if success (including quitting)), -1 if fail
 */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
	char *command;
	char **argv;
	int running = 1;

	while (running)
	{
		printf("$ ");

		command = readcommand();

		if (command == NULL)
			return (0);

		argv = split(command);

		if (argv == NULL)
		{
			free(command);
			free(argv);
		}
		else
		{
			running = exec_command(argv, env);
			free(command);
			free(argv);
		}

	}

	return (0);
}
