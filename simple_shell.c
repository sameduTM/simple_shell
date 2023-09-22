#include "shell.h"
/**
* main - main function of the simple shell program
* @ac: count of arguments
* @av: pointer to arguments
* @envp: pointer to environment array
*
* Return: 0 Always
*/
int main(__attribute__((unused)) int ac, __attribute__((unused))

char **av, char **envp)
{
	char *prompt = "#cisfun$ ";

	char *buffer = NULL, **str = NULL;

	int i = 0, stat = 0, argc = 0;

	static int _exitval, counter;

	size_t bufsize = 0;
	ssize_t bytes = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, strlen(prompt));

		bytes = getline(&buffer, &bufsize, stdin);
		++counter;
		if (_uniqchar(buffer, bytes, &_exitval) == 127)
			continue;

		_rmnl(buffer);

		str = _parse_r(buffer);

		for (i = 0; str[i]; i++)
			argc++;

		_stdlib(buffer, str, envp, &_exitval);

		stat = _pth(str[0], str, envp, &_exitval);

		_execve(stat, str, &_exitval, &counter);

		fflush(stdin);
	}
	free(buffer);
	return (0);

}
