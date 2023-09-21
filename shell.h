#ifndef SHELL_SMPLE
#define SHELL_SMPLE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>


int _putchar(char c);
void _puts(char *s);
int _strlen(char *s);
char *_mystrdup(char *s);
char *concat_str(char *nm, char *ep, char *val);

char **_tokenizer(char *_str, const char *del);
void exec_cmd(char **argv);
void *reall_mem(void *ptr, unsigned
int old_sz, unsigned int new_sz);

extern char **environ;

/**
* struct path_list - Linked list for PATH directories
* @dir: directory
* @p: next node pointer
*/
typedef struct path_list
{
	char *dir;

	struct path_list *p;
} path_list;

char *get_env(const char *name);

path_list *add_path_node_end(path_list **head, char *str);

path_list *link_path(char *path);

char *find_executable(char *filename, path_list *head);

/**
* struct builtin - pointer to function with with built-in command
* @name: built-in command name
* @func: executes the built-in cmd
*/
typedef struct builtin
{
	char *name;

	void (*func)(char **);
} builtin;

void (*check_builtin(char **argv))(char **av);
int atoi_modf(char *s);
void exit_sh(char **argv);
void env(char **argv);
void set_env(char **argv);
void unset_env(char **argv);
void free_argv(char **argv);
void free_path_list(path_list *head);

#endif
