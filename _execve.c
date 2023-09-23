#include "shell.h"
/**
* _execve - runs our main shell
* @pathstat: file path status, whether exe or not
* @argv: arguments parsed to the program
* @_exit: exit value
* @cmd_count: no. of commands run
*
* Return: Nothing
*/
void _execve(int pathstat, char **argv, int *_exit, int *cmd_count)
{
	if (pathstat == 2)
	{
		if (access(argv[0], X_OK) == 0)
		{
			if (fork() == 0)
				execve(argv[0], argv, environ);
			else
				wait(NULL);
			*_exit = 0;
		}
		else if (access(argv[0], F_OK) != 0)
		{
			_printf("hsh: ");
			_numprint(cmd_count);
			_printf(": ");
			perror(argv[0]);
			*_exit = 127;
		}
		else if (access(argv[0], F_OK) == 0 && access(argv[0], X_OK) != 0)
		{
			_printf("hsh: ");
			_numprint(cmd_count);
			_printf(": ");
			perror(argv[0]);
			*_exit = 126;
		}
	}
	free(argv);
}
