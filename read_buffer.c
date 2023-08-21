#include "main.h"

/**
 * read_buffer - reads the input buffer from file
 * @info: pointer to the input file to read from
 * @buffer: pointer to the input buffer being read
 * @len: pointer to the length of buffer
 *
 * Return: the number of bytes read
 */
ssize_t read_buffer(ShellInfo *info, char *buffer, size_t *len)
{
ssize_t num_read = 0;

if (*len)
{
return (0);
}

num_read = read(info->readfd, buffer, BUFFER_SIZE);

if (num_read >= 0)
{
*len = num_read;
}
return (num_read);
}
