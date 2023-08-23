#include "main.h"

/**
 * replace_alias - replaces a command with an alias
 * @info: pointer to the ShellInfo structure
 *
 * Return: 1 successful, 0 failure
 */
int replace_alias(ShellInfo *info)
{
int i;
list_t *node;
char *ptr;

for (i = 0; i < 10; i++)
{
node = check_haystack(info->alias, info->argv[0], '=');
if (!node)
{
return (0);
}
free(info->argv[0]);
ptr = spec_strchr(node->str, '=');
if (!ptr)
return (0);
ptr = str_dup(ptr + 1);
if (!ptr)
{
return (0);
}
info->argv[0] = ptr;
}
return (1);
}
