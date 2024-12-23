#include "shell.h"

/**
 * main - Main function.
 * Return: Always 0 on success.
 */
int main(void)
{
char *readline, **tokens, *path = NULL;
int status;
while (1)
{
if (isatty(STDIN_FILENO))
printf("$ ");
readline = read_line();
if (strcmp("env\n", readline) == 0)
{
free(readline);
_env();
continue;
}
if (strcmp(readline, "exit\n") == 0)
{
free(readline);
break;
}
tokens = parse_the_line(readline, TOK_DELIM);
if (*tokens == NULL)
{
free_d_p(tokens);
if (path == NULL)
{
perror("commant not found");
free(path);
free_d_p(tokens);
return (3);
}
if (path != NULL)
{
status = execute_line(tokens, path);
free(path);
}
free_d_p(tokens);
}
return (status);
}
}
