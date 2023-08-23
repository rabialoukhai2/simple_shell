#include "shell.h"

/**
 * fn1 - Checks if the input
 * @str: string
 * @env: environment
 * Return: multiple 1
 */

int fn1(char **str, char **env)
{
/* pid_t pid, wpid; */
int i = 0;
char *copy = NULL;
copy = _strdup(str[0]);
if ((access(str[0], R_OK | X_OK)) == 0)
{
int result = execute_and_check(str, env);
free(copy);
return (result);
}
else if (copy != NULL)
{
for (i = 0; copy[i] != '\0'; i++)
{
if (copy[i] == '/')
{
errno = ENOENT;
perror("hsh");
free(copy);
return (1);
}
}
}
free(copy);
return (0);
}
