#include "main.h"

/**
 * 
 * 
 * 
 * 
 *
 */
int write_num(int index, char buffer[], int flags, int width, int prec, int len, char padding, char extra_char)
{
	int n, init_padding = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padding = ' ';
	if (prec > 0 && prec < len)
		padding = ' ';
	while (prec > len)
		buffer[--index] = '0', len++;
	if (extra_char != 0)
		len++;
	if (width > len)
	{
		for (n = 1; n < width - len + 1; n++)
		  {
			buffer[n] = padding;
		  }
		buffer[n] = '\0';
		if (flags & F_MINUS && padding == ' ')
		{
			if (extra_char)
			  {
				buffer[--index] = extra_char;
			  }
			return (write(1, &buffer[index], len) + write(1, &buffer[1], n - 1));
		}
		else if (!(flags & F_MINUS) && padding == ' ')
    		{
			if (extra_char)
			  {
				buffer[--index] = extra_char;
			  }
			return (write(1, &buffer[1], n - 1) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && padding == '0')
		{
			if (extra_char)
			  {
				buffer[--init_padding] = extra_char;
			  }
			return (write(1, &buffer[init_padding], n - init_padding));
				write(1, &buffer[index], len - (1 - init_padding));
		}
	}
	if (extra_char)
	  {
		buffer[--index] = extra_char;
	  }
	return (write(1, &buffer[index], len));
}
