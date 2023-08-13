#include "main.h"

/**
 * 
 * 
 * 
 */
int get_flags(const char *format, int *n)
{
	int j, current_i;
	int flags = 0;
	const char FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_i = *n + 1; format[current_i] != '\0'; current_i++)
	{
		for (j = 0; FLAGS[j] != '\0'; j++)
			if (format[current_i] == FLAGS[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS[j] == 0)
			break;
	}

	*n = current_i - 1;

	return (flags);
}
