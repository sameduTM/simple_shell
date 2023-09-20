#include "shell.h"
/**
 * print_prompt - prints to stdin
 *
 * Return: Nothing
*/
void print_prompt(void)
{
	char *prompt = "#cisfun$ ";

	if (isatty(STDIN_FILENO))
		write(1, prompt, strlen(prompt));
}

