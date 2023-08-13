#include "main.h"

/**
 * _putchar - writes char c to standard output
 * @c: the character to be printed
 *
 * Return: 1 for success, 0, -1 for error
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
