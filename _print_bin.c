#include "main.h"

/**
 * print_binary - Helper function to print an unsigned int in binary format
 * @n: The unsigned int to print
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
int ret_val = 0;
unsigned int mask = 1 << ((sizeof(unsigned int) * 8) - 1);
int zero = 0;
int bit;

while (mask > 0)
{

bit = (n & mask) ? 1 : 0;
if (bit == 1 || zero || mask == 1)
{
ret_val += _putchar(bit + '0');
zero = 1;
}
mask >>= 1;
}
return (ret_val);
}
