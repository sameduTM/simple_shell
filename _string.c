#include "shell.h"
/**
 * _mystrdup - returns pointer to new memory
 * @str: pointer to a string
 *
 * Return: pointer to a string
 */
char *_mystrdup(char *str)
{
	int i, p;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (p = 0; str[p] != '\0';)
	{
		p++;
	}
	new = malloc(sizeof(char) * p + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < p; i++)
	{
		new[i] = str[i];
	}
	new[p] = str[p];
	return (new);
}

/**
 * concat_str - concats strings in new memory
 * @nm: string 1
 * @sp: string 2
 * @val: string 3
 *
 * Return: pointer to the new string
 */
char *concat_str(char *nm, char *sp, char *val)
{
	char *res;
	int str1, str2, str3, i, k;

	str1 = _strlen(nm);
	str2 = _strlen(sp);
	str3 = _strlen(val);

	res = malloc(str1 + str2 + str3 + 1);
	if (!res)
		return (NULL);

	for (i = 0; nm[i]; i++)
		res[i] = nm[i];
	k = i;

	for (i = 0; sp[i]; i++)
		res[k + i] = sp[i];
	k = k + i;

	for (i = 0; val[i]; i++)
		res[k + i] = val[i];
	k = k + i;

	res[k] = '\0';

	return (res);
}

/**
 * _strlen - finds length of string
 * @s: pointer to string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: pointer to string
 *
 * Return: Nothing
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
