#include "shell.h"
/**
 * _printf - prints string
 * @str: string to print
 *
 * Return: Nothing
 */
void _printf(char *str)
{
	int i, sz, pt;

	for (i = 0; str[i] != '\0'; i++)
		;

	sz = i;

	pt = write(STDOUT_FILENO, str, sz);
	if (pt == EOF)
		return;
}
/**
 * _strpth - prints path
 * @nxt: string that follows PATH
 * @cmd: command that is followed by flags
 *
 * Return: 0 if success
 */
char *_strpth(char *nxt, char *cmd)
{
	char *str = NULL, *token = NULL;
	int len = 0, len1 = 0;

	token = nxt;
	len = _strlen(token);
	len1 = _strlen(cmd);

	str = malloc((len + len1 + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);

	str[0] = '\0';

	_strcat(str, nxt);
	_strcat(str, "/");
	_strcat(str, cmd);
	_strcat(str, "\0");

	return (str);
}
/**
 * _numprint - print integer
 * @counter: pointer to counter
 *
 * Return: Nothing
 */
void _numprint(int *counter)
{
	int i = 0, len = 0, k, n;

	unsigned int trm = 1, x, tot;

	n = *counter;
	tot = n;
	x = tot;

	do {
		x /= 10;
		++len;
	} while (x != 0);

	i += len;

	for (k = 0; k < len; k++)
		trm = trm * 10;
	_putchar('0' + (tot / trm));

	if (len > 1)
	{
		for (k = 0; k < len - 2; k++)
		{
			trm /= 10;
			x = tot / trm;
			_putchar('0' + x % 10);
		}
		_putchar('0' + (tot % 10));
	}
}
/**
 * _parse_r - parses double pointer to string using space delim
 * @input: pointer to string input
 *
 * Return: parsed string
*/
char **_parse_r(char *input)
{
	char **av;
	char *str1 = NULL, *str2 = NULL, *str_copy = NULL;
	int argc = 0, i = 0;

	str_copy = _strdup(input);
	str1 = strtok(str_copy, " \t");

	for (argc = 0; str1 != NULL; argc++)
	{
		str1 = strtok(NULL, " \t");
	}

	av = malloc(sizeof(char *) * (argc + 1));

	if (av == NULL)
		return (NULL);

	str2 =  strtok(input, " \t");

	while (str2 != NULL)
	{
		av[i] = str2;
		str2 = strtok(NULL, " \t");
		i++;
	}
	av[i] = NULL;
	free(str_copy);
	return (av);
}
