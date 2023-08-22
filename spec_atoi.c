#include "main.h"

/**
 * spec_atoi - converts an input string to an integer
 * @str: input string to be converted
 *
 * Return: interger value of converted string
 */
int spec_atoi(char *str)
{
int index = 0;
unsigned long int result = 0;

if (*str == '+')
{
str++;
}
for (index = 0;  str[index] != '\0'; index++)
{
if (str[index] >= '0' && str[index] <= '9')
{
result *= 10;
result += (str[index] - '0');
if (result > INT_MAX)
{
return (-1);
}
else
{
return (-1);
}
}
}
return (result);
}
