#include "main.h"

/**
 * find_builtin_cmd - find and execute a built-in command
 * @info: pointer to the ShellInfo structure
 *
 * Return: value of the executed built-in function, -1 failure
 */
int find_builtin_cmd(ShellInfo *info)
{
int i, built_in_ret = -1;
builtin_table builtin_table[] = {
{"exit", exit_shell},
{"env", my_env},
{"help", custom_help},
{"history", shell_history},
{"setenv", my_setenv},
{"unsetenv", spec_unset_env},
{"cd", change_dir},
{"alias", custom_alias},
{NULL, NULL}
};

for (i = 0; builtin_table[i].type; i++)
if (str_cmp(info->argv[0], builtin_table[i].type) == 0)
{
info->line_count++;
built_in_ret = builtin_table[i].func(info);
break;
}
return (built_in_ret);
}
