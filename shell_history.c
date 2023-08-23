#include "main.h"

/**
 * shell_history - displays shell command history
 * @info: pointer to the ShellInfo structure
 *
 * Return: Always 0
 */
int shell_history(ShellInfo *info)
{
print_list(info->history);
return (0);
}
