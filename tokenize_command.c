#include "shell.h"

#define MAX_ARGS 128

/**
 * tokenize_command - splits the string into commands
 * @command: string to be tokenized
 * @argc: argument count
 *
 * Return: array of strings argv
*/
char **tokenize_command(char *command, int *argc)
{
	char **argv = NULL;
	char *token;
	int i = 0;

	argv = (char **)malloc(MAX_ARGS * sizeof(char *));
	if (argv == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(command, " ");
	while (token != NULL)
	{
		if (i >= MAX_ARGS - 1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	*argc = i;

	return (argv);
}
