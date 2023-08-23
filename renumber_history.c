#include "main.h"

/**
 * renumber_history - renumber the history entries in the linked list
 * @info: pointer to the ShellInfo structure
 *
 * Return: new history count
 */
int renumber_history(ShellInfo *info)
{
list_t *node = info->history;
int n = 0;

while (node)
{
node->num = n++;
node = node->next;
}
return (info->history_count = n);
}
