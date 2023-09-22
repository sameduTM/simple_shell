#include "shell.h"
/**
 * _strcat - concats 2 strings
 * @src: source string to copy from
 * @dest: destination string to copy to
 *
 * Return: concat null terminated string
*/
char *_strcat(char *dest, char *src)
{
	int l = _strlen(dest), i;

	for (i = 0; src[i] != '\0'; i++)
		dest[l + i] = src[i];
	dest[l + i] = '\0';

	return (dest);
}
/**
 * _strcpy - copies string to another mem location
 * @str1: first string to copy to
 * @str2: second string to copy from
 *
 * Return: copied string
*/
char *_strcpy(char *str1, char *str2)
{
	int d;

	for (d = 0; d <= _strlen(str2); d++)
		str1[d] = str2[d];
	return (str1);
}
/**
* _strlen - gets length of string
* @str: string
*
* Return: returns length of string
*/
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
/**
* _strdup - duplicates a string and returns pointer to it
* @s: string to be copied
*
* Return: new string, NULL if not enough memory allocated
*/
char *_strdup(char *s)
{
	char *cpd_str;

	int i, j;

	if (s == NULL)
		return (NULL);

	j = 0;

	for (i = 0; s[i] != '\0'; i++)
		j++;

	cpd_str = malloc(sizeof(char) * j + 1);

	if (cpd_str == NULL)
		return (NULL);

	for (i = 0; i < j; i++)
		cpd_str[i] = s[i];
	cpd_str[j] = '\0';

	return (cpd_str);
}
/**
* _strcmp - compare str1 and str2
* @str1: first string
* @str2: second string
*
* Return: two string comparison
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
			exit(EXIT_FAILURE);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
