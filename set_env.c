#include "main.h"

/**
 * set_env - set or modify an environment variable
 * @info: pointer to the ShellInfo structure
 * @var: pointer to the environment variable
 * @value: value to be assigned to the environment variable
 *
 * Return: 0 on success, 1 on failure
 */
int set_env(ShellInfo *info, char *var, char *value)
{
char *buffer = NULL;
list_t *node;
char *line_ptr;

if (!var || !value)
return (0);

buffer = malloc(str_len(var) + str_len(value) + 2);
if (!buffer)
{
return (1);
}
str_cpy(buffer, var);
str_cat(buffer, "=");
str_cat(buffer, value);
node = info->env;
while (node)
{
line_ptr = starting_char(node->str, var);
if (line_ptr && *line_ptr == '=')
{
free(node->str);
node->str = buffer;
info->env_changed = 1;
return (0);
}
node = node->next;
}
append_node(&(info->env), buffer, 0);
free(buffer);
info->env_changed = 1;
return (0);
}
