
#include "shell.h"

/**
 * calling_unsetenv - take user var and unsets environments vars
 * @env: environe
 * @str: string
 * Return: 1
 */

int calling_unsetenv(char **env, char **str)
{
int i = 0;
if (str == NULL || str[1] == NULL || str[1][0] == '\0')
{
errno = EINVAL;
perror("hsh");

return (1);
}

i = enviro_var(env, str[1]);

while (env[i] != NULL)
{
env[i] = env[i + 1];
i++;
}

return (1);
}

/**
 *calling_setenv - setenv builtin
 * @env: environem
 * @str: string
 * Return: 1
 */

int calling_setenv(char **env, char **str)
{
int i = 0, total = 0, len = 0;
char *copy = NULL, *new = NULL;

printf("%s\n", str[1]);
printf("%s\n", env[0]);

i = enviro_var(env, str[1]);

printf("%s\n", env[i]);
if (i != 0 && str[3] != 0)
{
len = _strlength(env[i]);
calling_unsetenv(env, str);

total = (_strlength(str[1]) + _strlength(str[2]) + 2);

new = malloc(1024);
copy = malloc(total);

new = _strcat(str[1], "=");
copy = _strcat(new, str[2]);
_reallocat(env[i], len, _strlength(copy));
env[i] = copy;
}

return (1);
}
