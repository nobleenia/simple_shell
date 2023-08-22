#include "main.h"

/**
 * spec_unset_env - Unset environment variables
 * @info: pointer to the ShellInfo structure
 *
 * Return: 0 on success, 1 for failure
 */
int spec_unset_env(ShellInfo *info)
{
int i;

if (info->argc == 1)
{
puts_error("Too few arguments.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
{
unset_env(info, info->argv[i]);
}

return (0);
}
