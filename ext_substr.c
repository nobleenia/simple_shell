#include "main.h"

/**
 * ext_substr - extracts substring from a path string
 * @pathstr: pointer to the input path string to be extracted
 * @start: starting index of the path string
 * @stop: final index of the path string
 *
 * Return: pointer to the extracted path string
 */
char *ext_substr(char *pathstr, int start, int stop)
{
static char buffer[BUFFER_SIZE];
int index = 0;
int i;

for (i = start; i < stop; i++)
{
if (pathstr[i] != ':')
{
buffer[index++] = pathstr[i];
}
}
buffer[index] ='\0';
return (buffer);
}
