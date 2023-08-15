#include "main.h"

/**
 * _putchar - writes char c to standard output
 * @c: the character to be printed
 *
 * Return: 1 for success, 0, -1 for error
 */
int _putchar(char c)
{
static int n;
static char buffer[BUFFER_SIZE];

if (c == BUFFER_FLUSH || n >= BUFFER_SIZE)
{
write(1, buffer, n);
n = 0;
}
if (c != BUFFER_FLUSH)
{
buffer[n++] = c;
}
return (1);
}
