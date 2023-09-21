#include "shell.h"

/**
 * s_handler - checks for Ctrl C input
 * @s_num: int
 *
 * Return: Nothing
 */
void s_handler(int s_num)
{
	if (s_num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
 * _eof - checks end-of-file
 * @len: return value of _puts function
 *
 * @buffer: buffer
 */
void _eof(int len, char *buffer)
{
	(void)buffer;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}
/**
 * _isatty - check if input is from terminal
 */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}
/**
 * main - our main function
 *
 * Return: 0 on success
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	path_list *head = '\0';
	void (*f)(char **);

	signal(SIGINT, s_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_eof(len, buff);
		arv = _tokenizer(buff, " \n");
		if (!arv || !arv[0])
			exec_cmd(arv);
		else
		{
			value = get_env("PATH");
			head = link_path(value);
			pathname = find_executable(arv[0], head);
			f = check_builtin(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				exec_cmd(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				exec_cmd(arv);
			}
		}
	}
	free_path_list(head);
	free_argv(arv);
	free(buff);
	return (0);
}
