#include "main.h"

/**
 * str_cpy - copy the contents of one string into another
 * @src_str: the strings to be copied
 * @dest_src: the destination string
 *
 * Return: non-negative number
 */
char *str_cpy(char *src_str, char *dest_str)
{
int n = 0;

if (src_str == dest_str || dest_str == 0)
{
return (src_str);
}
while (dest_str[n])
{
src_str[n] = dest_str[n];
n++;
}
src_str[n] = 0;
return (src_str);
}
