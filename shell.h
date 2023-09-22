#ifndef UNIX_SH
#define UNIX_SH

#define TRUE 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>


int _pth(char *, char **, char **, int *);



int _showenv(char **, int *ex_st);
char *_dupenv(char **);



void _stdlib(char *, char **, char **, int *);
void _execve(int, char **, int *, int *);



int _strlen(char *);
char *_strdup(char *);
int _strcmp(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);



int _putchar(char);
void _printf(char *);
char *_strpth(char *, char *);
char **_parse_r(char *);
void _numprint(int *);



void _rmnl(char *);
void _freeargv(char **, int);
int _uniqchar(char *, ssize_t, int *);

#endif
