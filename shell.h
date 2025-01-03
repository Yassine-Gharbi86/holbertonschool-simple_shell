#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define TOK_DELIM " \t\n"
#define SIZE 64
extern char **environ;

char *line_read(void);
char **parse_the_line(char *, const char *);
int process_line(char **, char *);
void _env(void);
char *check_path(char *);
void free_d_p(char **);



#endif
