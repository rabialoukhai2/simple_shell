#ifndef SHELL_H
#define SHELL_H

/* import built-in fn header */
#include <signal.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
extern char **environ;

/* decalre buffers */
#define BUFFERSIZE 1024

/* declare deliminator */
#define DELIMINATOR "\n\r\t\a "

/**
 * struct list_s - singly linked list
 * @str: a string
 * @len: the number of field
 * @next: point to the next node
 */

typedef struct list_s
{
char *str;
unsigned int len;
struct list_s *next;
} list_t;
extern char *head;

/* shell */
list_t *add_node(list_t **head, const char *str);
void free_list(list_t *head);

/* execution_cmnd */
int inp_check(char **str, char **env, char *newstr, char *path, char *new2);
int enviro_var(char **env, char *str);
int check_inp(char **str, char **env);
int execu_cmd(char **str, char **env);
char *_getenviro(char **env, char *str);

/* str1 */
int _strlength(char *str);
char *_strdup(const char *str);
int _strcmp(char *str1, char *str2);

/* cmd_env */
int calling_enviro(char **args);

/* cmd_rdline_filt */
char *read_ln(void);
int funct_filter(char **commands, char **env);

/* builtin_cmd */
int calling_cdir(char **args);
int calling_help(char *args);
void calling_exit(char **args);
int calling_exit_status(char **args);

/* cmd_setenv */
int calling_setenv(char **env, char **str);
int calling_unsetenv(char **env, char **str);

/* alloc_memory */
void *_reallocat(void *ptr, unsigned int old_size, unsigned int new_size);

/* tokenizer_parser */
char **parse_ln(char *line);

/* str2 */
int _stoi(char *str);
char *_strcat(char *s1, char *s2);

/* str3 */
int _isdig(char str);
int _exit_stoi(char *str);
char *_strcopy(char *dest, char *src);

/* main.c */
void ctrl_c_hdlr(int sig_num);

/* fn1 */
int fn1(void);

#endif
