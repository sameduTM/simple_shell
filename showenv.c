#include "shell.h"
/**
* _showenv - prints environment
* @envp: pointer to env var
* @exit_val: exit value
*
* Return: Always 0
*/
int _showenv(char **envp, int *exit_val)
{
	unsigned int n;

	envp = environ;
	for (n = 0; envp[n] != NULL; n++)
	{
		_printf(envp[n]);
		_putchar('\n');
	}
	envp[n] = NULL;
	*exit_val = 0;
	return (0);
}
