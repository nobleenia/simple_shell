#include "main.h"

/**
 * 
 * 
 * 
 */
int _print_binary(va_list args, char buffer[], int flags, int width, int prec, int size)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int m = 2147483648;
    unsigned int i, sum;
unsigned int arr[32];
int ret_val;
char z;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(prec);
    UNUSED(size);

arr[0] = n / m;

for (i = 1; i < 32; i++)
{
    m /= 2;
    arr[i] = (n / m) % 2;
}

for ( i = 0, sum = 0, ret_val = 0; i < 32; i++)
{
    sum += arr[i];
    if (sum || i == 31)
    {
        z = '0' + arr[i];
        write(1, &z, 1);
        ret_val++;
    }
}
 return(ret_val);
}
