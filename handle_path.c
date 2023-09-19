#include "shell.h"

#define MAX_ARGS 128
#define MAX_PATH_LEN 1024
/**
 * handle_path - use relative path to run command
 * @buffer: the pointer to string to manipulate
 *
 * Return: Nothing
 */

void handle_path(char *buffer)
{
	char *token, *path, *path_copy, **argv;
	int i = 0;

	argv = (char **)malloc(MAX_ARGS * sizeof(char *));
	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " ");
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

	path = getenv("PATH");
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	token = strtok(path_copy, ":");

	_snprintf(token, argv, path_copy);
}
/**
 * _snprintf - write string from token to buffer argv
 * @token: pointer to string wrten from
 * @argv: pointer to array of strings wrtten to
 * @path_copy: pointer to path
 *
 * Return: Nothind
*/
void _snprintf(char *token, char **argv, char *path_copy)
{
	size_t cmd_path_len;
	char cmd_path[MAX_PATH_LEN];
	int found = 0;

	while (token != NULL)
	{
		cmd_path_len = strlen(token) + strlen("/") + strlen(argv[0]) + 1;
		if (cmd_path_len >= sizeof(cmd_path))
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		strcpy(cmd_path, token);
		strcat(cmd_path, "/");
		strcat(cmd_path, argv[0]);

		if (access(cmd_path, X_OK) == 0)
		{
			execute_command(cmd_path, argv);
			found = 1;
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	if (!found)
	{
		printf("Command not found: %s\n", argv[0]);
	}
	free_argv(argv);
}
