#include "main.h"

/**
 * custom_help - isplay help information
 * @info: pointer to the ShellInfo structure
 *
 * Return: Always 0
 */
int custom_help(ShellInfo *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
{
_puts(*arg_array);
}
return (0);
}
