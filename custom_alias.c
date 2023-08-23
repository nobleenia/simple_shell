#include "main.h"

/**
 * custom_alias - handle custom aliases
 * @info: pointer to the ShellInfo structure
 *
 * Return: Always 0
 */
int custom_alias(ShellInfo *info)
{
int i = 0;
char *equal_sign_pos = NULL;
list_t *alias_node = NULL;

if (info->argc == 1)
{
alias_node = info->alias;
while (alias_node)
{
print_alias(alias_node);
alias_node = alias_node->next;
}
return (0);
}

for (i = 1; info->argv[i]; i++)
{
equal_sign_pos = spec_strchr(info->argv[i], '=');
if (equal_sign_pos)
{
set_alias(info, info->argv[i]);
}
else
{
alias_node = check_haystack(info->alias, info->argv[i], '=');
print_alias(alias_node);
}
}

return (0);
}
