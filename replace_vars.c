#include "main.h"

/**
 * replace_vars - replaces variables in command-line arguments
 * @info: pointer to the ShellInfo structure
 *
 * Return: always returns 0
 */
int replace_vars(ShellInfo *info)
{
int i = 0;
list_t *node;

for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
{
continue;
}
if (!str_cmp(info->argv[i], "$?"))
{
replace_string(&(info->argv[i]), str_dup(convert_number(info->status, 10, 0)));
continue;
}
if (!str_cmp(info->argv[i], "$$"))
{
replace_string(&(info->argv[i]), str_dup(convert_number(getpid(), 10, 0)));
continue;
}
node = check_haystack(info->env, &info->argv[i][1], '=');
if (node)
{
replace_string(&(info->argv[i]), str_dup(spec_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[i], str_dup(""));
}
return (0);
}
