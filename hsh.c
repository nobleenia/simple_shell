#include "main.h"

/**
 * hsh - shell loop and command execution
 * @info: pointer to the ShellInfo structure
 * @argv: pointer to the argument array
 *
 * Return: value from the last executed built-in command or exit status
 */
int hsh(ShellInfo *info, char **av)
{
ssize_t num_read = 0;
int builtin_ret = 0;

while (num_read != -1 && builtin_ret != -2)
{
clear_info(info);
if (interactive_mode(info))
{
_puts("$ ");
}
putchar_error(BUFFER_FLUSH);
num_read = get_input(info);
if (num_read != -1)
{
set_info(info, av);
builtin_ret = find_builtin_cmd(info);
if (builtin_ret == -1)
{
find_exec_cmd(info);
}
}
else if (interactive_mode(info))
{
_putchar('\n');
}
free_info(info, 0);
}
write_history(info);
free_info(info, 1);
if (!interactive_mode(info) && info->status)
{
exit(info->status);
}
if (builtin_ret == -2)
{
if (info->error_no == -1)
{
exit(info->status);
}
exit(info->error_no);
}
return (builtin_ret);
}
