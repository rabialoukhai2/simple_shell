#ifndef SHELL_H
#define SHELL_H



#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>


#define DELIMINATOR "\n\r\t\a "
#define BUFFERSIZE 1024
extern char **environ;


/**
 * struct list_s - singly linked list struct node
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

extern char *head;
