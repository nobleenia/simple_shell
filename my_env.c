#include "main.h"

/**
 * my_env - shows current environment
 * @info: pointer to the ShellInfo structure
 *
 * Return: Always 0
 */
int my_env(ShellInfo *info)
{
print_list_str(info->env);
return (0);
}
