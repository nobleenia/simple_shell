#include "main.h"

/**
 * 
 * 
 * 
 */
int _print_pointer(va_list args, char buffer[], int flags, int width, int prec, int size)
{
    char more_char = 0, padding = ' ';
	int index = BUFF_SIZE - 2;
    int len = 2;
    int init_padding = 1;
	unsigned long num;
	char mask[] = "0123456789abcdef";
	void *loc = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (loc == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);

	num = (unsigned long)loc;

	while (num > 0)
	{
		buffer[index--] = mask[num % 16];
		num /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		more_char = '+', len++;
	else if (flags & F_SPACE)
		more_char = ' ', len++;

	index++;

	return (write_pointer(buffer, index, len, width, flags, padding, more_char, init_padding));
}
