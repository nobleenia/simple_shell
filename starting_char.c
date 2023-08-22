#include "main.h"

/**
 * starting_char - checks if needle starts with haystack
 * @str: the string to search
 * @needle: the substring to be found
 *
 * Return: the starting character of the prompt
 */
char *starting_char(const char *str, const char *needle)
{
while (*needle)
{
if (*needle++ != *str++)
{
return (NULL);
}
}
return ((char *)str);
}
