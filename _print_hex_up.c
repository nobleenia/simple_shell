#include "main.h"

/**
 * print_hex_upper - print a number in uppercase hexadecimal format
 * @n: number to be printed
 *
 * Return: number of characters printed
 */
int print_hex_upper(unsigned int n)
{
int ret_val = 0;
unsigned int mask = 0xF0000000;
int shift = 28;
char *hex_digits = "0123456789ABCDEF";

while (shift >= 0)
{
ret_val += _putchar(hex_digits[(n & mask) >> shift]);
mask >>= 4;
shift -= 4;
}
return (ret_val);
}
