#include "main.h"

/**
 * get_line - gets the next line in the input
 * @info: the input file to be read
 * @line_ptr: pointer to the line to be checked
 * @line_len: the length of the line to be read
 *
 * Return: the number of bytes read
 */
int get_line(ShellInfo *info, char **line_ptr, size_t *line_len)
{
static char buffer[BUFFER_SIZE];
static size_t start = 0;
static size_t end = 0;
size_t chunk_len = 0;
ssize_t num_read = 0;
ssize_t next_line = 0;
char *line = NULL;
char *new_line = NULL;
char *pos_newline;

line = *line_ptr;
if (line && line_len)
{
next_line = *line_len;
}
if (start == end)
{
start = end = 0;
}

num_read = read_buffer(info, buffer, &end);
if (num_read == -1 || (num_read == 0 && end == 0))
{
return(-1);
}

pos_newline = spec_strchr(buffer + start, '\n');
chunk_len = pos_newline ? 1 + (unsigned int)(pos_newline - buffer) : end;
new_line = _realloc(line, next_line, next_line ? next_line + chunk_len : chunk_len + 1);
if (!new_line)
{
return (line ? free(line), -1 : -1);
}

if (next_line)
{
spec_strcat(new_line, buffer + start, chunk_len - start);
}
else
{
spec_strcpy(new_line, buffer + start, chunk_len - start + 1);
}
next_line += chunk_len - start;
start = chunk_len;
line = new_line;

if (line_len)
{
*line_len = next_line;
}
*line_ptr = line;
return (next_line);
}
