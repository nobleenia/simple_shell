#include "main.h"

/**
 * get_environ - returns string array of the environ
 * @info: pointer to the ShellInfo structure
 */
char **get_environ(ShellInfo *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}

return (info->environ);
}
