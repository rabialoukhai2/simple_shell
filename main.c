#include "shell.h"

/**
 * main - The main fucntion
 */

int main(void)
{
char *buffer = NULL;
char **args;
int value = 1;
int loop_count = 0;

while (value)
{
signal(SIGINT, ctrl_c_hdlr);

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);

buffer = read_ln();
args = parse_ln(buffer);
value = funct_filter(args, environ);
free(args);
free(buffer);
loop_count++;
}
return (0);
}

/**
 *  ctrl_c_hdlr - Handles ctrl C
 */

void ctrl_c_hdlr(int sig_num __attribute__((unused)))
{
signal(SIGINT, ctrl_c_hdlr);
write(STDOUT_FILENO, "\n$ ", 3);
}
