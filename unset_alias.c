#include "main.h"

/**
 * unset_alias - unset a custom alias
 * @info: pointer to the ShellInfo structure
 * @alias_name: alias to be unset
 */
int unset_alias(ShellInfo *info, char *alias_name)
{
char *equal_sign_pos, equal_sign_char;
int delete_result;

equal_sign_pos = spec_strchr(alias_name, '=');
if (!equal_sign_pos)
{
return (1);
}

equal_sign_char = *equal_sign_pos;
*equal_sign_pos = 0;
    

delete_result = del_node(&(info->alias),
get_node_index(info->alias, check_haystack(info->alias, alias_name, -1)));

*equal_sign_pos = equal_sign_char;

return (delete_result);
}
