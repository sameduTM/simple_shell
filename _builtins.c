#include "shell.h"

/**
 * exit_sh - exits the shell
 * @argv: array of commands given
 *
 * Return: Nothing
 */
void exit_sh(char **argv)
{
	int i, k;

	if (argv[1])
	{
		k = atoi_modf(argv[1]);
		if (k <= -1)
			k = 2;
		free_argv(argv);
		exit(k);
	}
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	exit(0);
}

/**
 * atoi_modf - converts a string to integer
 *@s: pointer to a string
 *
 *Return: the integer j
 */
int atoi_modf(char *s)
{
	int i = 0, j = 0, sign = 1;

	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		j = (j * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (j);
}

/**
 * env - prints the current environment
 * @argv: array of arguments
 */
void env(char **argv __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}

/**
 * set_env - initialize/modify a new environment variable
 * @argv: array of input string
 *
 * Return: Nothing
 */
void set_env(char **argv)
{
	int i, j, k;

	if (!argv[1] || !argv[2])
	{
		perror(get_env("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (argv[1][j] == environ[i][j])
		{
			while (argv[1][j])
			{
				if (argv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (argv[1][j] == '\0')
			{
				k = 0;
				while (argv[2][k])
				{
					environ[i][j + 1 + k] = argv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = concat_str(argv[1], "=", argv[2]);
		environ[i + 1] = '\0';
	}
}

/**
 * unset_env - get rid of an environment variable
 * @argv: array of strings
 *
 * Return: Nothing
 */
void unset_env(char **argv)
{
	int i, j;

	if (!argv[1])
	{
		perror(get_env("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (argv[1][j] == environ[i][j])
		{
			while (argv[1][j])
			{
				if (argv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (argv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
