#include "main.h"

/**
 * replace_string - replaces a string
 * @old_str: string to be replaced
 * @new_str: string used to replace old_str
 *
 * Return: 1 for success
 */
int replace_string(char **old_str, char *new_str)
{
free(*old_str);
*old_str = new_str;
return (1);
}
