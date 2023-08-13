#include "main.h"

/**
 * 
 * 
 * 
 */
int _print_int(va_list args, char buffer[], int flags, int width, int prec, int size)
{
  long int n = va_arg(args, long int);
    unsigned long int num;
    int i = BUFF_SIZE - 2;
    int is_negative = 0;

    n = convert_size_number(n, size);

    if (n == 0)
    {
        buffer[i--] = '0';
    }
    buffer[BUFF_SIZE - 1] = '\0';
    num = (unsigned long int)n;

    if (n < 0)
    {
        num = (unsigned long int)((-1) * n);
        is_negative = 1;
    }
    
    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }
    i++;
    
    return (write_spec_num(is_negative, i, buffer, flags, width, prec, size));

}
