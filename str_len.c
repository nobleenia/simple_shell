#include "main.h"

/**
 * strlen - Calculates the length of a stribg
 * @s: the strings to be printed
 *
 * Return: non-negative number
 */
int str_len(char *str)
{
int len = 0;

if (!str)
{
return (0);
}
while (*str++)
{
len++;
}
return (len);
}
