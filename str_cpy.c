#include "main.h"

/**
 * str_cpy - copy the contents of one string into another
 * @s: the strings to be copied
 *
 * Return: non-negative number
 */
char *str_cpy(char *src_str, char *dst_str)
{
int n = 0;

if (dst_str == src_str || src_str == 0)
{
return (dst_str);
}
while (src_str[n])
{
dst_str[n] = src_str[n];
n++;
}
dst_str[n] = 0;
return (dst_str);
}
