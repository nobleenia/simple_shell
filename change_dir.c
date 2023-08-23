#include "main.h"

/**
 * change_dir - changes current working directory
 * @info: pointer to the ShellInfo structure
 */
int change_dir(ShellInfo *info)
{
char *curr_path, *target_dir, buffer[BUFFER_SIZE];
int chdir_result;

curr_path = getcwd(buffer, BUFFER_SIZE);
if (!curr_path)
{
_puts("Error: Unable to retrieve current working directory.\n");
}
if (!info->argv[1])
{
target_dir = get_env(info, "HOME=");
if (!target_dir)
{
chdir_result = chdir((target_dir = get_env(info, "PWD=")) ? target_dir : "/");
}
else
{
chdir_result = chdir(target_dir);
}
}
else if (str_cmp(info->argv[1], "-") == 0)
{
if (!get_env(info, "OLDPWD="))
{
_puts(curr_path);
_putchar('\n');
return (1);
}
 _puts(get_env(info, "OLDPWD=")), _putchar('\n');
chdir_result = chdir((target_dir = get_env(info, "OLDPWD=")) ? target_dir : "/");
}
else
{
chdir_result = chdir(info->argv[1]);
}
if (chdir_result == -1)
{
print_error(info, "can't cd to ");
puts_error(info->argv[1]);
putchar_error('\n');
}
else
{
set_env(info, "OLDPWD", get_env(info, "PWD="));
set_env(info, "PWD", getcwd(buffer, BUFFER_SIZE));
}
return (0);
}
