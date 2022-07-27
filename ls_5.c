#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Lists the contents of /tmp in five different processes
 *
 * Return: 0 if success, -1 if fail
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t child_pid;
	int status;
	int i = 0;

	while (i < 5)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Can't create process");
			return (-1);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Can't execve process");
				return (-1);
			}
		}
		else
		{
			wait(status);
			i++;
		}
	}

	return (0);
}
