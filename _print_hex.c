#include "main.h"

/**
 * print_hex - prints hexadecimals
 * @n: the input integer
 *
 * Return: hexadecimal value of input
 */
int print_hex(unsigned int n)
{
int ret_val = 0;
unsigned int mask = 0xf0000000;
int shift = 28;
char *hex_digits = "0123456789abcdef";

while (shift >= 0)
{
ret_val += _putchar(hex_digits[(n & mask) >> shift]);
mask >>= 4;
shift -= 4;
}
return (ret_val);
}
