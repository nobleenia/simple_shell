#include "main.h"

/**
 * my_setenv - set an environment variable
 * @info: pointer to the ShellInfo structure
 *
 * Return: 0 successful, 1 otherwise
 */
int my_setenv(ShellInfo *info)
{
if (info->argc != 3)
{
puts_error("Incorrect number of arguements\n");
return (1);
}
if (set_env(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}
