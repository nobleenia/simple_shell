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
int j = 0;

for (j = 0; index = start, index < stop; index++)
{
if (pathstr[index] != ':')
{
buffer[j++] = pathstr[index];
}
}
buffer[j] = 0;
return (buffer);
}
