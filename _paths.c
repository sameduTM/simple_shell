#include "shell.h"
/**
 * _pth - shows the environment PATH
 * @_keyw: first word of user command
 * @args: series of command and its flags
 * @envp: pointer to environment
 * @ext: the exit value
 *
 * Return: 0 if success, 2 for failure
 */
int _pth(char *_keyw, char **args, char **envp, int *ext)
{
	char *str = NULL, *_psenvp = NULL;

	char *tmp, *_ft, *_ht;

	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		_psenvp = _strdup(envp[i]);
		_ft = strtok(_psenvp, "= \t");
		tmp = strtok(NULL, "= \t");

		if (_strcmp(_ft, "PATH") == 0)
		{
			_ht = strtok(tmp, ": \t");
			while (_ht)
			{
				str = _strpth(_ht, _keyw);

				if (access(str, X_OK) == 0)
				{
					if (fork() == 0)
						execve(str, args, NULL);
					else
						wait(NULL);
					*ext = 0;
					free(str);
					free(_psenvp);
					return (0);
				}
				_ht = strtok(NULL, ": \t");
				free(str);
			}
		}
		free(_psenvp);
	}
	return (2);
}
