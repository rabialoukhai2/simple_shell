#include "main.h"
/**
 * tests - f n for testing
 * @chars_read: read char
 * Return: 1
 */

int tests(ssize_t chars_read)
{
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
return (1);
}
