#include "main.h"

/**
 * write_history - writes command history to a file
 * @info: pointer to the ShellInfo structure
 *
 * Return: 1 on success, -1 on failure
 */
int write_history(ShellInfo *info)
{
ssize_t fd;
char *filename = get_history_file(info);
list_t *node = NULL;

if (!filename)
{
return (-1);
}

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
{
return (-1);
}
for (node = info->history; node; node = node->next)
{
write_string_to_fd(node->str, fd);
write_to_fd('\n', fd);
}
write_to_fd(BUFFER_FLUSH, fd);
close(fd);
return (1);
}
