#include "main.h"

/**
 * set_info - set information in the ShellInfo structure
 * @info: pointer to the ShellInfo structure
 * @av: pointer to the argument array
 */
void set_info(ShellInfo *info, char **av)
{
int i = 0;

info->file_name = av[0];
if (info->get_arg)
{
info->argv = split_string(info->get_arg, " \t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = str_dup(info->get_arg);
info->argv[1] = NULL;
}
}
for (i = 0; info->argv && info->argv[i]; i++)
{
}
info->argc = i;
replace_alias(info);
replace_vars(info);
}
}
