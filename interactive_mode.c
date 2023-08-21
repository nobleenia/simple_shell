#include "main.h"

/**
 * interactive_mode - checks if the file input is a shell or not
 * @info: the information to be read from the file
 *
 * Return: if file is interactive or not.
 */
int interactive_mode(ShellInfo *info)
{
  return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
