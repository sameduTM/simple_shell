#include "shell.h"
/**
 * handle_user_input - handles user input
 *
 * Return: Nothing
 */
void handle_user_input(void)
{
	char *buffer = NULL, **env_var;
	size_t bufsize = 0;
	ssize_t bytes;

	while (1)
	{
		print_prompt();
		bytes = getline(&buffer, &bufsize, stdin);

		if (bytes == -1)
			exit(EXIT_FAILURE);
		if (buffer[bytes - 1] == '\n')
			buffer[bytes - 1] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			break;
		}
		if (strcmp(buffer, "env") == 0)
		{
			env_var = environ;

			while (*env_var != NULL)
			{
				printf("%s\n", *env_var);
				env_var++;
			}
		}
		else
		{
			handle_path(buffer);
		}
	}
	free(buffer);
}
