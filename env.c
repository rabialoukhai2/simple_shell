#include "shell.h"

/**
 * calling_enviro - Built in fn for enviro
 * @env: Dbl char pntr
 * Return: Int
 */

int calling_enviro(char **env)
{
	int i = 0;
	int len = 0;
	char *copy = malloc(8192);

	while (env[i] != NULL)
	{
		len = _strlength(env[i]);
		copy = _strdup(env[i]);

		write(STDOUT_FILENO, copy, len + 1);
		write(1, "\n", 1);
		free(copy);
		i++;
	}
	return (1);
}