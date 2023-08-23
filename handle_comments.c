#include "main.h"

/**
 * remove_comments - remove comments from a string
 * @buffer: pointer to the input string containing comments
 */
void handle_comments(char *buffer)
{
int n;

for (n = 0; buffer[n] != '\0'; n++)
{
if (buffer[n] == '#' && (!n || buffer[n - 1] == ' '))
{
buffer[n] = '\0';
break;
}
}
}
