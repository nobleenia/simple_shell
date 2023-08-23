#include "main.h"

/**
 * print_error - prints error from programs
 * @info: pointer to the ShellInfo structure
 * @str: input string for printing
 */
void print_error(ShellInfo *info, char *str)
{
puts_error(info->file_name);
puts_error(": ");
print_decimal(info->line_count, STDERR_FILENO);
puts_error(": ");
puts_error(info->argv[0]);
puts_error(": ");
puts_error(str);
}
