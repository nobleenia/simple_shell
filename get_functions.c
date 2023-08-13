#include "main.h"

/**
 * 
 * 
 * 
 */
int get_function(const char *format, int *index, va_list list, char buffer[], int flags, int width, int precision, int size)
{
	int n;
	int len = 0;
	int printed_chars = -1;
	format_t format_types[] = {
		{'c', _print_char}, {'s', _print_string}, {'%', _print_percent},
		{'i', _print_int}, {'d', _print_int}, {'b', _print_binary},
		{'u', _print_unsigned}, {'o', _print_octal}, {'x', _print_hex_low},
		{'X', _print_hex_up}, {'p', _print_pointer}, {'S', print_non_printable},
		{'r', _print_rev}, {'R', _print_rot13}, {'\0', NULL}
	};
	for (n = 0; format_types[n].format != '\0'; n++)
		if (format[*index] == format_types[n].format)
			return (format_types[n].funct(list, buffer, flags, width, precision, size));

	if (format_types[n].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		len += write(1, &format[*index], 1);
		return (len);
	}
	return (printed_chars);
}
