#include "main.h"

/**
 *
 *
 *
 *
 */
int write_spec_num(int is_negative, int index, char buffer[], int flags, int width, int prec, int size)
{
	int len = BUFF_SIZE - index - 1;
	char padding = ' ';
	char extra_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';

	return (write_num(index, buffer, flags, width, prec, len, padding, extra_char));
}
