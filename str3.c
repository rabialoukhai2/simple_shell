#include "shell.h"

/**
 *  _exit_stoi - stoi for exit status
 */

int _exit_stoi(char *str)
{
int result = 0, index = 0, int_max = 2147483647;

if (str[index] == '-')
{
return (1);
}

while (str[index] != '\0')
{
if (_isdig(str[index]) == 1)
{
result = result * 10 + str[index] - '0';
}
else
{
return (1);
}
index++;
}

if (result > int_max)
{
return (1);
}
else
return (result);
}

/**
 *  _isdig - Finds if char is a digit or not
 */

int _isdig(char str)
{
if (str >= '0' && str <= '9')
{
return (1);
}
return (0);
}

/**
 * _strcopy - Prnt a string
 */

char *_strcopy(char *dest, char *src)
{
int i;

for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';
return (dest);
}
