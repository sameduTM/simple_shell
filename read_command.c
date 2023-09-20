#include "shell.h"
/**
 * read_command - reads user input
 *
 * Return: Nothing
*/
char *read_command(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t bytes;

	bytes = getline(&buffer, &bufsize, stdin);
	/* handles eof */
	if (bytes == -1)
		exit(EXIT_FAILURE);
	/* removes newline at the end */
	if (buffer[bytes - 1] == '\n')
		buffer[bytes - 1] = '\0';

	return (buffer);
}
