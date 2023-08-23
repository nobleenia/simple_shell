#include "main.h"

/**
 * write_string_to_fd - writes string to a file descriptor
 * @str: pointer to the string to be written
 * @fd: file descriptor to write to
 *
 * Return: number of characters written
 */
int write_string_to_fd(char *str, int fd)
{
int total = 0;

if (!str)
{
return (0);
}
while (*str)
{
total += write_to_fd(*str++, fd);
}
return (total);
}
