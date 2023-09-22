#include "shell.h"
/**
* _stdlib - implements standard lib type functions
* @buf: buffer passed
* @argv: arguments
* @envp: environment
* @_ext: exit value
*
* Return: Nothing
*/
void _stdlib(char *buf, char **argv, char **envp, int *_ext)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		free(buf);
		free(argv);
		exit(*_ext);
	}

	if (_strcmp(argv[0], "env") == 0)
		_showenv(envp, _ext);
}
