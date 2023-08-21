#include "main.h"

/**
 * read_input - reads user input to interactive shell
 * @info: input file information
 * @buffer: pointer to input file buffer
 * @buffer_size: the size of the input buffer
 *
 * Return: the size of bytes read.
 */
ssize_t read_input(ShellInfo *info, char **buffer, size_t *buffer_size)
{
ssize_t num_read = 0;
size_t len = 0;

if(!*buffer_size)
{
free(*buffer);
*buffer = NULL;
signal(SIGINT, sigintHandler);
#if GETLINE
num_read = getline(buffer, &len, stdin);
#else
num_read = get_line(info, buffer, &len);
#endif
if (num_read > 0)
{
if ((*buffer)[num_read - 1] == '\n')
{
(*buffer)[num_read - 1] = '\0';
num_read--;
}
info->line_count_flag = 1;
/*if (spec_strchr(*buffer, ';'))*/
{
*buffer_size = num_read;
info->cmd_buffer = buffer;
}
}
}
return (num_read);
}
