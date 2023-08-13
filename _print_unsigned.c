#include "main.h"

/**
 * print_unsigned - print an unsigned integer
 * @n: The number to print
 *
 * Return: number printed
 */
int print_unsigned(unsigned int n)
{

int ret_val = 0;

if (n / 10 != 0)
{
ret_val += print_unsigned(n / 10);
}
ret_val += _putchar((n % 10) + '0');

return (ret_val);

