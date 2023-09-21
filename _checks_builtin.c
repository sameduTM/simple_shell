#include "shell.h"
/**
 * check_builtin - identifies builtin commands
 * @av: array of string arguments
 *
 * Return: pointer to function that takes argv, returns void
 */
void (*check_builtin(char **av))(char **argv)
{
	int i, j;
	builtin C[] = {
		{"exit", exit_sh},
		{"env", env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{NULL, NULL}};

	for (i = 0; C[i].name; i++)
	{
		j = 0;
		if (C[i].name[j] == av[0][j])
		{
			for (j = 0; av[0][j]; j++)
			{
				if (C[i].name[j] != av[0][j])
					exit(EXIT_FAILURE);
			}
			if (!av[0][j])
				return (C[i].func);
		}
	}
	return (0);
}
