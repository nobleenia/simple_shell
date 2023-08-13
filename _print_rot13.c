#include "main.h"

/**
 * print_rev_str - print string in reverse format
 * @str: input string to be printed
 *
 * Return: number of characters printed
 */
int print_rev_str(char *str)
{

int len = 0;
char *ptr = str;

while (*ptr)
{
len++;
ptr++;
}
while (len > 0)
{
_putchar(str[len - 1]);
len--;
}
return (len);
}
