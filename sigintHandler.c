#include "main.h"

/**
 * sigintHandler - 
 * @sig_num:
 *
 *
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUFFER_FLUSH);
}
