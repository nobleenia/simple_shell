#include "main.h"

/**
 * print_non_printable - Helper function to print non-printable characters
 * @str: The string to print
 *
 * Return: number of characters printed
 */
int print_non_printable(char *str)
{

int ret_val = 0;
char c;

while (*str)
{
c = *str;
if (c < 32 || c >= 127)
{
ret_val += _putchar('\\');
ret_val += _putchar('x');
if (c < 16)
{
ret_val += _putchar('0');
}
ret_val += print_hex((unsigned char)c);
}
else
{
ret_val += _putchar(c);
}
str++;
}
return (ret_val);
}
