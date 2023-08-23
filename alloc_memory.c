#include "shell.h"

/**
 * _reallocat - return the new size of an array reallocating
 *  the space for a memory block
 */

void *_reallocat(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_pointer;
unsigned int i = 0;

if (old_size == new_size)
return (ptr);

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

new_pointer = malloc(new_size);

if (new_pointer == NULL)
return (NULL);

while (i < old_size)
{
*((char *)new_pointer + i) = *((char *)ptr + i);
i++;
}
free(ptr);
return (new_pointer);
}
