#include "main.h"

/**
 * build_history_list - builds a command history linked list
 * @info: pointer to the ShellInfo structure
 * @buffer: command string to be added to the history list
 * @line_count: line count identifier for the command
 *
 * Return: Always 0
 */
int build_history_list(ShellInfo *info, char *buffer, int line_count)
{
list_t *node = NULL;

if (info->history)
{
node = info->history;
}
append_node(&node, buffer, line_count);

if (!info->history)
{
info->history = node;
}
return (0);
}
