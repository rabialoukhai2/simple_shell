#include "shell.h"

/**
 * read_ln - Rd arguments w/ getline
 */

char *read_ln(void)
{
char *line = NULL;
size_t bufsize = 0;
int i = 0;

i = getline(&line, &bufsize, stdin);

if (i == EOF)
{
if ((isatty(STDIN_FILENO)) == 1)
write(1, "\n", 1);
exit(0);
}
return (line);
}

/**
 * funct_filter - Filters commands(fn) built-ins
 */

int funct_filter(char **commands, char **env)
{
int option = 0;
char *builtin[7] = {"exit", "cd", "env", "unsetenv","setenv", NULL};
if (commands[0] == NULL)
return (1);
while (builtin[option] != NULL)
{
if (_strcmp(builtin[option], commands[0]) == 0)
break;
option++;
}
switch (option)
{
case 0:
if (commands[1] == NULL)
calling_exit(commands);
else
calling_exit_status(commands);
break;
case 1:
calling_cdir(commands);
break;
case 2:
calling_enviro(env);
break;
case 3:
calling_unsetenv(env, commands);
break;
case 4:
calling_setenv(env, commands);
break;
default:
return (execu_cmd(commands, env));
}
return (option);
}
