#include "main.h"

/**
 * print_alias - prints alias definition
 * @alias_node: pointer to the alias node
 *
 * Return: O for success, 1 for failure
 */
int print_alias(list_t *alias_node)
{
  char *equal_sign_pos = NULL;
  char *alias_value_start = NULL;

if (alias_node)
{
equal_sign_pos = spec_strchr(alias_node->str, '=');
for (alias_value_start = alias_node->str; alias_value_start <= equal_sign_pos; alias_value_start++)
_putchar(*alias_value_start);
_putchar('\'');
_puts(equal_sign_pos + 1);
_puts("'\n");
return (0);
}
return (1);
}
