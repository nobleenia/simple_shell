#include "main.h"

/**
 * print_decimal - print an integer as a decimal number
 * @input: integer to be printed
 * @fd: file descriptor indicating where to print
 *
 * Return: count of characters printed
 */
int print_decimal(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
{
__putchar = putchar_error;
}
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
{
_abs_ = input;
}
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;

return (count);
}
