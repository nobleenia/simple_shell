#include "main.h"

/**
 * 
 * 
 * 
 */
int get_width(const char *format, int *n, va_list list)
{
	int current_i;
	int width = 0;

	for (current_i = *n + 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			width *= 10;
			width += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*n = current_i - 1;

	return (width);
}
