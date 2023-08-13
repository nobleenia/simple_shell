#include "main.h"

/**
 * print_hex_without_leading_zeros - Prints a hexadecimal
 * value without leading zeros
 * @ptr: The input integer
 *
 * Return: number of characters printed
 */
int print_hex_without_leading_zeros(uintptr_t ptr)
{
int ret_val = 0;
char hex_digits[] = "0123456789abcdef";
int num_digits = (sizeof(uintptr_t) * 2);
int i;
int non_zero = 0;
char digit;

for (i = num_digits - 1; i >= 0; i--)
{
digit = hex_digits[(ptr >> (i * 4)) & 0xF];
if (digit != '0' || non_zero || i == 0)
{
ret_val += _putchar(digit);
non_zero = 1;
}
}

return ret_val;
}
