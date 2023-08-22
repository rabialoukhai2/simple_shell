#include "shell.h"

/**
 * _strlength - returns the length of a str
 */

int _strlength(char *str)
{
int length = 0;

while (str[length] != '\0')
{
length++;
}
return (length);
}

/**
 * _putchar - writes the character c to stdout
 */

int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _puts -  print str
 */

void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str);
str++;
}
_putchar('\n');
}

/**
 * _strcmp - compare strs
 */

int _strcmp(char *str1, char *str2)
{

int index;

for (index = 0; str1[index] != '\0' || str2[index] != '\0'; index++)
{
if (str1[index] != str2[index])
{
return (str1[index] - str2[index]);
}
}
return (0);
}

/**
 * _strdup - cp str given as a param.
 */

char *_strdup(const char *str)
{
unsigned int counter1, counter2;
char *strCopy;

counter1 = 0;
counter2 = 0;

if (str == NULL)
{
return (0);
}

while (str[counter1] != '\0')
{
counter1++;
}

strCopy = malloc(sizeof(char) * (counter1 + 1));
if (strCopy == NULL)
{
return (NULL);
}

while (counter2 < counter1)
{
strCopy[counter2] = str[counter2];
counter2++;
}

strCopy[counter2] = '\0';

return (strCopy);
}
