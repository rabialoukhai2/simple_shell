#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define COMMAND_LENGTH 1024

void execute_cmd(char *args[]);
void tokenizer(char *command, char *args[]);
int tests(void);

#endif
