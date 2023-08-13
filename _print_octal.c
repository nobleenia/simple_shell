#include "main.h"

/**
 * print_octal - prints an unsigned int in octal format
 * @n: the input integer to be printed
 *
 * Return: number of characters printed
 */
int print_octal(unsigned int n)
{

int ret_val = 0;
int i;
int num_digits = 0;
int octates[100];

if (n == 0)
{
ret_val += _putchar('0');
return (1);
}

while (n != 0)
{
octates[num_digits] = n % 8;
n /= 8;
num_digits++;
}

for (i = num_digits - 1; i >= 0; i--)
{
ret_val += _putchar(octates[i] + '0');
}
return (ret_val);
}
