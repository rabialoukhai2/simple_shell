#include "shell.h"

/**
 * parse_ln - Put arguments in the arr
 * @line: caharachter line will  parsed
 */

char **parse_ln(char *line)
{
	int buffer_size = BUFFERSIZE;
	int location = 0;
	char **tokens = NULL;
	char *token = NULL;

	tokens = malloc(sizeof(char *) * buffer_size);
	if (!tokens)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIMINATOR);

	while (token != NULL)
	{
		tokens[location] = token;
		token = strtok(NULL, DELIMINATOR);
		location++;
	}
	if (location >= buffer_size)
	{
		buffer_size += BUFFERSIZE;
		tokens = _reallocat(tokens, BUFFERSIZE, buffer_size * sizeof(char *));

		if (!tokens)
		{
			{
				perror("hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMINATOR);
	}
	tokens[location] = NULL;
	return (tokens);
}
