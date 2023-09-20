#include "shell.h"
/**
 * free_argv - frees the dynamically allocated memory
 * @argv: pointer to string of arrays to be freed
 * @argc: array count
 *
 * Return: Nothing
*/
void free_argv(char **argv, int argc)
{
	int j;

	for (j = 0; j < argc; j++)
	{
		free(argv[j]);
	}
	free(argv);
}
