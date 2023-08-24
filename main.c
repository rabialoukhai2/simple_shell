#include "main.h"

/**
<<<<<<< HEAD
 * main
 *
 *
 *Return: 0 Always
=======
 * main - The main fucntion
 * Return: 0
>>>>>>> 8d361ff4292c62c085c80c45e815a10bfda78dfe
 */

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;
	char *args[COMMAND_LENGTH];

	int is_interactive = isatty(fileno(stdin));

<<<<<<< HEAD
	while (1)
	{
		if (is_interactive)
		{
			printf("($) ");
			chars_read = getline(&command, &bufsize, stdin);
			if (chars_read == -1)
			{
				if (feof(stdin))
				{
					printf("\n");
					break;
				}
				else if (ferror(stdin))
				{
					perror("getline");
					exit(EXIT_FAILURE);
				}
			}
		}
		else
		{
			chars_read = getline(&command, &bufsize, stdin);
			if (chars_read == -1)
				break;
		}
		command[strcspn(command, "\n")] = '\0';
		tokenize_command(command, args);
	}
	free(command);
	return (0);
=======
/**
 *  ctrl_c_hdlr - Handles ctrl C
 * @sig_num: signal
 * Return: file
 */

void ctrl_c_hdlr(int sig_num __attribute__((unused)))
{
signal(SIGINT, ctrl_c_hdlr);
write(STDOUT_FILENO, "\n$ ", 3);
>>>>>>> 8d361ff4292c62c085c80c45e815a10bfda78dfe
}
