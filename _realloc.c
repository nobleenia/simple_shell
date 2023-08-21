#include "main.h"

/**
 * _realloc - reallocates a block of memory
 * @original_ptr: pointer to initial memory allocation block
 * @old_size: previous memory size
 * @new_size: new memory size to be allocated
 *
 * Return: pointer to the new memory
 */
void *_realloc(void *original_ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr;

if (!original_ptr)
{
return (malloc(new_size));
}

if (!new_size)
{
return (free(original_ptr), NULL);
}

if (new_size == old_size)
{
return (original_ptr);
}

new_ptr = malloc(new_size);
if (!new_ptr)
{
return (NULL);
}
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
{
new_ptr[old_size] = ((char *)original_ptr)[old_size];
}

free (original_ptr);

return (new_ptr);
}
