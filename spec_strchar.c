#include "main.h"

/**
 * spec_strchr - locates a specific character in a string
 * @str: string to be checked
 * @c: special character to check for
 *
 * Return: the character if present in the string, otherwisee NULL
 */
char *spec_strchr(char *str, char c)
{
do
{
if (*str == c)
{
return (str);
}
}
while (*str++ != '\0');

return (NULL);

}
