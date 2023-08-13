#include "main.h"

/**
 * 
 * 
 * 
 */
int get_size(const char *format, int *n)
{
	int current_i = *n + 1;
	int size = 0;

	if (format[current_i] == 'l')
		size = S_LONG;
	else if (format[current_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*n = current_i - 1;
	else
		*n = current_i;

	return (size);
}
