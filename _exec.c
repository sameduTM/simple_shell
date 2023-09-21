#include "shell.h"
/**
 * _tokenizer - tokenize string into command and flags
 * @str: the string to be split
 * @delim: the delimiter
 *
 * Return: array of ponters of words
 */

char **_tokenizer(char *str, const char *delim)
{
	int i, j;
	char **array, *token, *token_copy;

	token_copy = malloc(_strlen(str) + 1);
	if (token_copy == NULL)
	{
		perror(get_env("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		token_copy[i] = str[i];
		i++;
	}
	token_copy[i] = '\0';

	token = strtok(token_copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _mystrdup(token);

	i = 1;
	j = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = reall_mem(array, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		array[i] = _mystrdup(token);
		i++;
		j++;
	}
	free(token_copy);
	return (array);
}
/**
 * exec_cmd - executes a command
 * @argv: array pointer of arguments
 *
 * Return: Nothing
 */
void exec_cmd(char **argv)
{

	int status, d;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(get_env("_"));
	}
	if (d == 0)
	{
		execve(argv[0], argv, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
/**
 * reall_mem - reallocates memory
 * @ptr: old pointer
 * @old_sz: old size of pointer
 * @new_sz: new size of pointer
 *
 * Return: New resized Pointer
 */
void *reall_mem(void *ptr, unsigned int old_sz, unsigned int new_sz)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_sz));

	if (new_sz == old_sz)
		return (ptr);

	if (new_sz == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_sz);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_sz > old_sz)
	{
		for (i = 0; i < old_sz; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_sz; i < new_sz; i++)
			new[i] = '\0';
	}
	if (new_sz < old_sz)
	{
		for (i = 0; i < new_sz; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}
/**
 * free_argv - frees array of pointers argv
 * @av: array of pointers
 *
 * Return: Nothing
 */
void free_argv(char **av)
{
	int i;

	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
}
