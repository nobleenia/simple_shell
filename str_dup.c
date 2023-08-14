#include "main.h"

/**
 * strdup - used to create a duplicate copy of a given string
 * @s: the strings to be printed
 *
 * Return: non-negative number
 */
char *str_dup(const char *str)
{
int len = 0;
char *dup;

if (str == NULL)
{
return (NULL);
}
while (*str++)
{
len++;
}
dup = malloc(sizeof(char) * (len + 1));
if (!dup)
{
return (NULL);
}
for (len++; len--;)
{
dup[len] = *--str;
}
return (dup);
}
