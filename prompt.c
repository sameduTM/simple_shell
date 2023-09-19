#include "shell.h"

/**
* print_prompt - displays prompt waiting for user input
*
* Return: Nothing
*/

void print_prompt(void)
{
	char *prompt = "#cisfun$ ";

	if (isatty(STDIN_FILENO))
		write(1, prompt, strlen(prompt));
	fflush(stdout);
}
