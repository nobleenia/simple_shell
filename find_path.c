#include "main.h"

/**
 * find_path - finds command in a string path
 * @info: pointer to the input file of strings
 * @path_list: the list od strings paths
 * @cms: the command to be checked for
 *
 * Return: the command or NULL
 */
char *find_path(ShellInfo *info, char *path_list, char *cmd)
{
int index = 0, start_pos = 0;
char *full_path;

if (!path_list)
{
return (NULL);
}
if ((str_len(cmd) > 2) && starting_char(cmd, "./"))
{
if (is_cmd(info, cmd))
{
return (cmd);
}
}
while (1)
{
if (!path_list[index] || path_list[index] == ':')
{
full_path = ext_substr(path_list, start_pos, index);
if (!*full_path)
{
str_cat(full_path, cmd);
}
else
{
str_cat(full_path, "/");
str_cat(full_path, cmd);
}
if (is_cmd(info, full_path))
{
return (full_path);
}
if (!path_list[index])
{
break;
}
start_pos = index + 1;
}
index++;
}
return (NULL);
}
