#include "main.h"

/**
 * set_alias - set or update custom alias
 * @info: pointer to the ShellInfo structure
 */
int set_alias(ShellInfo *info, char *alias_str)
{
char *equal_sign_pos;

equal_sign_pos = spec_strchr(alias_str, '=');
if (!equal_sign_pos)
{
return (1);
}

if (!*++equal_sign_pos)
{
return (unset_alias(info, alias_str));
}

unset_alias(info, alias_str);
return (append_node(&(info->alias), alias_str, 0) == NULL);
}
