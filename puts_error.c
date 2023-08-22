#include "main.h"

/**
 * puts_error - prints a string to the error output
 * @str: the str to be printed
 */
void puts_error(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
putchar_error(str[i]);
i++;
}
}
