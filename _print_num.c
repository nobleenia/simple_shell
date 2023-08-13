#include "main.h"

/**
 * print_num - print a signed integer
 * @n: input number to be printed
 *
 * Return: number of characters printed
 */
int print_num(int n)
{
int ret_val = 0;
unsigned int num;

if (n < 0)
{
ret_val += _putchar('-');
num = -n;
}
else
{
num = n;
}

if (num / 10 != 0)
{
ret_val += print_num(num / 10);
}
ret_val += _putchar((num % 10) + '0');

return (ret_val);
}
