#include "shell.h"
/**
 * execute_command - execve function
 * @argv: pointer to array of commands
 *
 * Return: Nothing
*/
void execute_command(char **argv)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
