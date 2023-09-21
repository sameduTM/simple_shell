#include "shell.h"
/**
 * get_env - gets value of global env variable
 * @name: name of global variable
 *
 * Return: string of value
 */
char *get_env(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}
/**
 * add_path_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to linked list
 * @str: pointer to string in previous first node
 *
 * Return: address of the new element/node
 */

path_list *add_path_node_end(path_list **head, char *str)
{

	path_list *tmp;
	path_list *new;

	new = malloc(sizeof(path_list));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}
	return (*head);
}

/**
 * link_path - create linked-list for path dirs
 * @path: string to path value
 *
 * Return: pointer to linked-list created
 */
path_list *link_path(char *path)
{
	path_list *head = '\0';
	char *token;
	char *cpath = _mystrdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_path_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}
/**
 * find_executable - find pathname to filename
 * @filename: file/command name
 * @head: head of linked-list to path dirs
 *
 * Return: pathname of filename or NULL if no match
 */
char *find_executable(char *filename, path_list *head)
{
	struct stat stl;
	char *string;

	path_list *tmp = head;

	while (tmp)
	{

		string = concat_str(tmp->dir, "/", filename);
		if (stat(string, &stl) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}
	return (NULL);
}
/**
 * free_path_list - frees linked-list
 * @head: pointer to our linked-list
 *
 * Return: Nothing
 */
void free_path_list(path_list *head)
{
	path_list *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}
}
