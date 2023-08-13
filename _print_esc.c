#include "main.h"

/**
 * print_escaped_str - print string with escaped non-printable characters
 * @str: input string to be printed
 *
 * Return: number of characters printed
 */
int print_esc_str(char *str)
{
int ret_val = 0;

while (*str)
{
  if (*str == '\n')
{
ret_val += _putchar('\\');
ret_val += _putchar('x');
ret_val += _putchar('0');
ret_val += _putchar('A');
}
else
{
ret_val += _putchar(*str);
}
str++;
}
return (ret_val);
}
