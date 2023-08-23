#include "shell.h"

/**
 *  calling_exit - take char pnt and exit the shell
 * @args: arguments
 * Return: exit
 */

void calling_exit(char **args)
{
free(*args);
free(args);
exit(EXIT_SUCCESS);
}

/**
 *  calling_exit_status - takes sbl pointer and exiting with a status
 * @args: arguments
 * Return: status
 */

int calling_exit_status(char **args)
{
int status;

status = _exit_stoi(args[1]);

if (status == -1)
{
perror("hsh");
return (0);
}
else
{
exit(status);
}
}

/**
 *  calling_cdir - takes char pntr cd command
 * @args: arguments
 * Return: 0 or home
 */

int calling_cdir(char **args)
{
char *targetDir = NULL, *home = NULL;

home = _getenviro(environ, "HOME");

if (args[1])
{
if (_strcmp(args[1], "~"))
{
targetDir = home;
}
else if (_strcmp(args[1], "-"))
targetDir = _getenviro(environ, "OLDPWD");
else
targetDir = args[1];
}
else
targetDir = home;

if (targetDir == home)
chdir(targetDir);

else if (access(targetDir, F_OK | R_OK) == 0)
chdir(targetDir);
else
perror("hsh");

return (0);
}
