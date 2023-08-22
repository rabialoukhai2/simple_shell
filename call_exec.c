#include "shell.h"

/**
 * enviro_var - Finds the envir variable
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
