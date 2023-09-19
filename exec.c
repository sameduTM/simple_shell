#include "shell.h"
/**
* execute_command - executes command passed using execve function
* @cmd_path: pathname or command to execute
* @argv: pounter to array of string of flags to command
*
* Return: 0 if success, -1 if failure
*/
int execute_command(const char *cmd_path, char **argv)
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
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (status);
}
