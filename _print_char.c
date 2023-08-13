
/**
 * 
 * 
 * 
 */
int _print_char(va_list args, char buffer[], int flags, int width, int prec, int size)
{
    char c = va_arg(args, int);
    return (write_spec_char(c, buffer, flags, width, prec, size));
}
