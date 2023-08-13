#include "main.h"

/**
 * pointer_to_hex - Convert a pointer value to a hexadecimal string
 * @ptr: The pointer value to convert
 * @buf: The buffer to store the resulting string
 *
 * Return: Number of characters in the hexadecimal string
 */
int pointer_to_hex(uintptr_t ptr, char *buf)
{
char hex_digits[] = "0123456789abcdef";
int num_digits = (sizeof(uintptr_t) * 2);
int i;
int non_zero = 0;
char digit;

for (i = num_digits - 1; i >= 0; i--)
{
digit = hex_digits[ptr & 0xF];
if (digit != '0' || non_zero || i == 0) {
buf[i] = digit;
non_zero = 1;
}
else
{
buf[i] = ' ';
}
buf[i] = hex_digits[ptr & 0xF];
ptr >>= 4;
}

buf[num_digits] = '\0';

return (num_digits);
}
