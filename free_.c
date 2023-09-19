#include "shell.h"
/**
* free_argv - frees the memory allocated to array
* @argv: pointer to array of strings
*
* Return: Nothing
*/
void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
