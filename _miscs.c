#include "shell.h"
/**
* _freeargv - frees the pointer array
* @dptr: pointer to free
* @len: size of array to free
*
* Return: Nothing
*/
void _freeargv(char **dptr, int len)
{
	int i = 0;

	while (i < len)
	{
		free(dptr[i]);
		i++;
	}
	free(dptr);
}
/**
* _rmnl - replace newline with null terminating character
* @nl: newline
*
* Return: Nothing
*/
void _rmnl(char *nl)
{
	int j = 0;

	while (nl[j])
	{
		if (nl[j] == '\n')
		{
			nl[j] = '\0';
			return;
		}
		j++;
	}
}
/**
* _uniqchar - handles EOF and tab entry
* @tabs: no. of bytes read from stdin
* @buf: buffer
* @_exit: exit value
*
* Return: Always 0
*/
int _uniqchar(char *buf, ssize_t tabs, int *_exit)
{
	int j = 0;

	if (tabs == EOF && isatty(STDIN_FILENO) == 1)
	{
		_putchar('\n');
		free(buf);
		exit(*_exit);
	}
	if (tabs == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(buf);
		exit(*_exit);
	}
	if (_strcmp(buf, "\n") == 0)
	{
		*_exit = 0;
		return (127);
	}
	while (buf[j] != '\n')
	{
		if (buf[j] != ' ' && buf[j] != '\t')
			return (0);
		++j;
	}

	*_exit = 0;
	return (127);
}
