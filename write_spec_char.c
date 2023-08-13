#include "main.h"

/**
 * 
 * 
 * 
 *
 */
int write_spec_char(char c, char buffer[], int flags, int width, int prec, int size)
{
    int n = 0;
	char padding = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flags & F_ZERO)
		{
            padding = '0';
        }

	buffer[n++] = c;
	buffer[n] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (n = 0; n < width - 1; n++)
        {
			buffer[BUFF_SIZE - n - 2] = padding;
        }

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - n - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - n - 1], width - 1) + write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
