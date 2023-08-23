#include "main.h"

/**
 * get_history_file - get the path to the history file
 * @info: pointer to the ShellInfo structure
 *
 * Return: pointer to the allocated buffer, NULL for failure
 */
char *get_history_file(ShellInfo *info)
{
char *buffer, *dir;

dir = get_env(info, "HOME=");
if (!dir)
{
return (NULL);
}
buffer = malloc(sizeof(char) * (str_len(dir) + str_len(HISTORY_FILE) + 2));
if (!buffer)
{
return (NULL);
}
buffer[0] = 0;
str_cpy(buffer, dir);
str_cat(buffer, "/");
str_cat(buffer, HISTORY_FILE);
return (buffer);
}
