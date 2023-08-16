#ifndef SHELL_H
#define SHELL_H

#define BUFFERSIZE 1024
#define DELIMINATOR "\n\r\t\a "

extern char **environ;

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * struct list_s - singly linked list
 * singly linked list node structr
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

extern char *head;
