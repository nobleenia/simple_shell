#include "main.h"

/**
 * read_history - reads command history from a file
 * @info: pointer to the ShellInfo structure
 *
 * Return: number of history entries read
 */
int read_history(ShellInfo *info)
{
int i, last = 0, linecount = 0;
ssize_t fd, num_read, file_size = 0;
struct stat st;
char *buffer = NULL, *filename = get_history_file(info);

if (!filename)
{
return (0);
}
fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
{
return (0);
}
if (!fstat(fd, &st))
{
file_size = st.st_size;
}
if (file_size < 2)
{
return (0);
}
buffer = malloc(sizeof(char) * (file_size + 1));
if (!buffer)
{
return (0);
}
num_read = read(fd, buffer, file_size);
buffer[file_size] = 0;
if (num_read <= 0)
{
return (free(buffer), 0);
}
close(fd);
for (i = 0; i < file_size; i++)
{
if (buffer[i] == '\n')
{
buffer[i] = 0;
build_history_list(info, buffer + last, linecount++);
last = i + 1;
}
}
if (last != i)
{
build_history_list(info, buffer + last, linecount++);
}
free(buffer);
info->history_count = linecount;
while (info->history_count-- >= HISTORY_MAX)
{
del_node(&(info->history), 0);
}
renumber_history(info);
return (info->history_count);
}
