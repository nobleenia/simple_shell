#include "main.h"

/**
 * write_to_fd - write character to a file descriptor, with buffering
 * @c: character to be written
 * @fd: file descriptor to write to
 *
 * Return: 1 for success
 */
int write_to_fd(char c, int fd)
{
static int buffer_index;
static char buffer[BUFFER_SIZE];

if (c == BUFFER_FLUSH || buffer_index >= BUFFER_SIZE)
{
write(fd, buffer, buffer_index);
buffer_index = 0;
}
if (c != BUFFER_FLUSH)
buffer[buffer_index++] = c;
return (1);
}
