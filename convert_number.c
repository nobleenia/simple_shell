#include "main.h"

/**
 * convert_number - converts a number to a string
 * @num: number to be converted
 * @base: input base for conversion
 * @flags: flags controlling conversion behavior
 *
 * Return: pointer to the resulting string representation
 */
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}

array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do
{
*--ptr = array[n % base];
n /= base;
}
while (n != 0);

if (sign)
{
*--ptr = sign;
}
return (ptr);
}
