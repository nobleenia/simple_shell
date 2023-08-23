#include "main.h"

/**
 * unset_env - unset an environment variable
 * @info: pointer to the ShellInfo structure
 * @var: pointer to the variable to unset
 */
int unset_env(ShellInfo *info, char *var)
{
list_t *node = info->env;
size_t n = 0;
char *line_ptr;

if (!node || !var)
{
return (0);
}
while (node)
{
line_ptr = starting_char(node->str, var);
if (line_ptr && *line_ptr == '=')
{
info->env_changed = del_node(&(info->env), n);
n = 0;
node = info->env;
continue;
}
node = node->next;
n++;
}
return (info->env_changed);
}
