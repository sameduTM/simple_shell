#include "shell.h"

#define MAX_ARGS 128

/**
* tokenize_string - string tokenization
* @str: pointer to string to be tokenized
* @tokens: pointer to array to store tokens
* @token_count: counts number of tokens
*
* Return: Nothing
*/
void tokenize_string(char *str, char **tokens, int *token_count)
{
	char *token = strtok(str, " ");

	int count = 0;

	while (token != NULL && count < MAX_ARGS - 1)
	{
		tokens[count] = strdup(token);
		if (tokens[count] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " ");
		count++;
	}
	tokens[count] = NULL;
	*token_count = count;
}
