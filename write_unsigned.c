#include "main.h"

/**
 *
 *
 *
 *
 */
int write_unsigned(int is_negative, int index, char buffer[], int flags, int width, int prec, int size)
{
	int len = BUFF_SIZE - index - 1;
    int n = 0;
	char padding = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (prec > 0 && prec < len)
		padding = ' ';

	while (prec > len)
	{
		buffer[--index] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';

	if (width > len)
	{
		for (n = 0; n < width - len; n++)
			buffer[n] = padding;

		buffer[n] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], n));
		}
		else
		{
			return (write(1, &buffer[0], n) + write(1, &buffer[index], len));
		}
	}

	return (write(1, &buffer[index], len));
}
