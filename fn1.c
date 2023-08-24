#include "shell.h"

/**
 * fn1 - Checks if the input
 * @str: string
 * @env: environement
 * Return: multiple 1
 */

int fn1(char **str, char **env)
{
pid_t pid, wpid;
int id = 0;
char *copy = NULL;
pid = fork();
if (pid == 0)
{
id = execve(str[0], str, env);
if (id == -1)
{
perror("hsh");
}
exit(EXIT_SUCCESS);
}
else if (pid < 0)
perror("hsh");
else
do {
wpid = waitpid(pid, &id, WUNTRACED);
if (wpid == -1)
perror("hsh");
} while (!WIFSIGNALED(id) && !WIFEXITED(id));
free(copy);
return (1);
}
