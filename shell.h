#ifndef SIMPLE_SH
#define SIMPLE_SH

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_prompt(void);
void free_argv(char **argv);
int execute_command(const char *cmd_path, char **argv);
void tokenize_string(char *str, char **tokens, int *token_count);
void handle_user_input(void);
void handle_path(char *);
void _snprintf(char *token, char **argv, char *path_copy);

#endif
