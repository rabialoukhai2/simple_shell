#include "main.h"

/**
 * main - main function
 * Return: 0 Always
 */

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;
	char *args[COMMAND_LENGTH];

	int is_interactive = isatty(fileno(stdin));

	while (1)
	{
		if (is_interactive)
			tests();
		else
		{
			chars_read = getline(&command, &bufsize, stdin);
			if (chars_read == -1)
				break;
		}
		command[strcspn(command, "\n")] = '\0';
		tokenizer(command, args);
	}
	free(command);
	return (0);
}
