#include "main.h"

/**
 * get_env -  gets value of an environment variable
 * @info: pointer to the ShellInfo structure
 * @name: environment variable name
 *
 * Return: value of the environment value
 */
char *get_env(ShellInfo *info, const char *name)
{
list_t *node = info->env;
char *line_ptr;

while (node)
{
line_ptr = starting_char(node->str, name);
if (line_ptr && *line_ptr)
return (line_ptr);
node = node->next;
}
return (NULL);
}
