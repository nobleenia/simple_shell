#include "main.h"

/**
 * strcmp - to compare two strings to determine their relative ordering
 * @s: the strings to be printed
 *
 * Return: non-negative number
 */
int str_cmp(char *str1, char *str2)
{
while (*s1 && *s2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}
