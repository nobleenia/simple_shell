#include "main.h"

/**
 * check_delimiter - checks if an input character is a delimiter
 * @delimiter: pointer to the delimiter input
 * @c: character to check through
 *
 * Return: 1 if delimiter, 0 if not
 */
int check_delimiter(char c, char *delimiter)
{
while (*delimiter)
{
if (*delimiter++ == c)
{
return (1);
}
}
return (0);
}
