#include "main.h"

/**
 * strcat - used to concatenate two strings
 * @s: the strings to be printed
 *
 * Return: non-negative number
 */
char *str_cat(char *str1, char *str2)
{
char *new_str = str1;

while (*str1)
{
str1++;
}
while (*str2)
{
*str1++ = *str2++;
}
*str1 = *str2;
return (new_str);
}
