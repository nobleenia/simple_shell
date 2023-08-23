#include "main.h"

/**
 * find_exec_cmd - finds a command that can be executed in the input
 * @info: pointer to the input file to be checked
 *
 * Return: nothing
 */
void find_exec_cmd(ShellInfo *info)
{
char *path = NULL;
int i, arg_count;

info->path = info->argv[0];
if (info->line_count_flag == 1)
{
info->line_count++;
info->line_count_flag = 0;
}
for (i = 0, arg_count = 0; info->get_arg[i]; i++)
if (!check_delimiter(info->get_arg[i], " \t\n"))
{
arg_count++;
}
if (!arg_count)
{
return;
}
path = find_path(info, get_env(info, "PATH="), info->argv[0]);
if (path)
{
info->path = path;
fork_cmd(info);
}
else
{
if ((interactive_mode(info) || get_env(info, "PATH=")
     || info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
{
fork_cmd(info);
}
else if (*(info->get_arg) != '\n')
{
info->status = 127;
print_error(info, "not found\n");
}
}
}
