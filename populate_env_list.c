#include "main.h"

/**
 * populate_env_list - populate the environment list in the ShellInfo structure
 * @info: pointer to the ShellInfo structure
 *
 * Return: Always 0
 */
int populate_env_list(ShellInfo *info)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
{
append_node(&node, environ[i], 0);
}
info->env = node;
return (0);
}
