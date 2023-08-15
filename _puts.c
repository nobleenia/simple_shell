#include "main.h"

/**
 * puts - prints the characters in an array of strings
 * @s: the strings to be printed
 *
 * Return: non-negative number
 */
void _puts(char *str)
{
int n = 0;

if (!str)
{
return;
}
while (str[n] != '\0')
{
_putchar(str[n]);
n++;
}
}
