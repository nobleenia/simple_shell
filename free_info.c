#include "main.h"

/**
 * free_info - frees all information in the ShellInfo structure
 * @info: pointer to the ShellInfo structure
 * @all: all elements in the structure list
 */
void free_info(ShellInfo *info, int all)
{
free_str_arr(info->argv);
info->argv = NULL;
info->path = NULL;
if (all)
{
if (!info->cmd_buffer)
{
free(info->get_arg);
}
if (info->env)
{
free_list(&(info->env));
}
if (info->history)
{
free_list(&(info->history));
}
if (info->alias)
{
free_list(&(info->alias));
}
free_str_arr(info->environ);
info->environ = NULL;
safe_free((void **)info->cmd_buffer);
if (info->readfd > 2)
{
close(info->readfd);
}
_putchar(BUFFER_FLUSH);
}
}
