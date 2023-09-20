#include "shell.h"
/**
 * main - checks the code
 * @argc: argument count
 * @argv: string of pointer array
 *
 * Return: 0 Always
*/
int main(int argc, char **argv)
{
	char *command;

	while (1)
	{
		print_prompt();
		command = read_command();

		if (command == NULL)
			exit(EXIT_FAILURE);
		argv = tokenize_command(command, &argc);
		execute_command(argv);
		free(command);
	}

	return (0);
}
