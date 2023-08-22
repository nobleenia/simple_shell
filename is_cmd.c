#include "main.h"

/**
 * is_cmd - checks if an input is a command
 * @info: pointer to the input file to be checked
 * @path: pointer to the file path
 */
int is_cmd(ShellInfo *info, char *path)
{
struct stat file_stat;

(void)info;
if (!path || stat(path, &file_stat))
{
return (0);
}
if (file_stat.st_mode & S_IFREG)
{
return (1);
}
return (0);
}
