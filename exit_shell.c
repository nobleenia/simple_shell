#include "main.h"

/**
 * exit_shell - exits the shell
 * @info: pointer to the ShellInfo structure
 */
int exit_shell(ShellInfo *info)
{
int exit_check;

if (info->argv[1])
{
exit_check = spec_atoi(info->argv[1]);
if (exit_check == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
puts_error(info->argv[1]);
putchar_error('\n');
return (1);
}
info->err_num = spec_atoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}
