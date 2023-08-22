#include "main.h"

/**
 * putchar_error - rite a character to the error output
 * @c: character to be written
 *
 * Return: Always 1
 */
int putchar_error(char c)
{
static int n;
static char buffer[BUFFER_SIZE];

if (c == BUFFER_FLUSH || n >= BUFFER_SIZE)
{
write(2, buffer, n);
n = 0;
}
if (c != BUFFER_FLUSH)
{
buffer[n++] = c;
}
return (1);
}
