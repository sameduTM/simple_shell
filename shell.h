#ifndef SIMPLE_SH
#define SIMPLE_SH

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* prototypes to be used */
void print_prompt(void);
char *read_command(void);
void free_argv(char **argv, int argc);
void execute_command(char **argv);
char **tokenize_command(char *command, int *argc);
void handle_user_input(void);
void handle_path(char *);
void _snprintf(char *token, char **argv, char *path_copy);

#endif

