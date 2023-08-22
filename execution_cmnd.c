#include "shell.h"

/**
 * execu_cmd - TakesThe  array_vectorized of user inp in a command to execute
 */

int execu_cmd(char **str, char **env)
{
pid_t pid, wpid;
int id = 0;
char *newstr = malloc(8 * BUFFERSIZE), *path = malloc(8 * BUFFERSIZE);
char *new2 = malloc(sizeof(char) * BUFFERSIZE), *newp = NULL;

if (inp_check(str, env, newstr, path, new2))
return (1);
new2 = _getenviro(env, "PATH"), newp = _strcat("/", str[0]);
pid = fork();
if (pid == 0)
{
path = strtok(new2, ":");
while (path)
{
newstr = _strcat(path, newp);
if ((access(newstr, X_OK)) == 0)
{
free(newp);
id = execve(newstr, str, env);
if (id == -1)
perror("hsh");
}
free(newstr), path = strtok(NULL, ":");
}
write(STDERR_FILENO, "hsh", _strlength("hsh") + 1);
write(2, str[0], _strlength(str[0])), write(2, ": not found\n", 12);
exit(EXIT_SUCCESS);
}
else if (pid < 0)
perror("hsh");
else
do
{
wpid = waitpid(pid, &id, WUNTRACED);
if (wpid == -1)
perror("hsh");
} while (!WIFSIGNALED(id) && !WIFEXITED(id));
free(newp), free(newstr), free(path), free(new2);
return (1);
}

/**
 * inp_check - Save the space!
 */

int inp_check(char **str, char **env, char *newstr, char *path, char *new2)
{
if ((check_inp(str, env)) == 1)
{
return (1);
}

if (newstr == NULL || path == NULL || new2 == NULL)
{
calling_exit(NULL);
}
return (0);
}

/**
 * _getenviro - search & finds the envir of variable
 */

char *_getenviro(char **env, char *str)
{
char *args = NULL, *copy = malloc(sizeof(char *) * BUFFERSIZE);
char *path = malloc(sizeof(char *) * BUFFERSIZE);
int id = 0, len = 0, len2 = 0;
int i = 0;

while (*env)
{
path = _strdup(env[i]);

args = strtok(path, "=");
if (args != NULL && (_strcmp(args, str)) == 0)
{
path = _strdup(env[i]);

while (args[++len])
;
len2 = len + 1;
id = _strlength(path) - len2;
i = 0;
while (i < id)
{
copy[i] = path[len2];
i++;
len2++;
}
free(path);
return (copy);
}
free(path);
i++;
}
free(copy), free(path);
return (NULL);
}

/**
 * enviro_var - Finds index of variable in such the envir 
 */

int enviro_var(char **env, char *str)
{
char *args = NULL;
char *path = malloc(sizeof(char) * BUFFERSIZE);
int i = 0;

while (*env)
{
path = _strdup(env[i]);
args = strtok(path, "=");

if (args != NULL && (_strcmp(args, str)) == 0)
{
free(path);
return (i);
}
free(path);
i++;
}
return (0);
}

/**
 * check_inp - Checks if the input is already a path
 */

int check_inp(char **str, char **env)
{
pid_t pid, wpid;
int id = 0, i = 0;
char *sep = "/";
char *copy = NULL;

copy = _strdup(str[0]);
if ((access(str[0], R_OK | X_OK)) == 0)
{
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
do
{
wpid = waitpid(pid, &id, WUNTRACED);
if (wpid == -1)
perror("hsh");
} while (!WIFSIGNALED(id) && !WIFEXITED(id));
free(copy);
return (1);
}
else if (copy != NULL)
{
for (i = 0; copy[i] != '\0'; i++)
if (copy[i] == sep[0])
{
errno = ENOENT;
perror("hsh"), free(copy);
return (1);
}
}
free(copy);
return (0);
}
