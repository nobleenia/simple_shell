#include "main.h"
/**
  * is_chain - refers to a sequence of connected elements
  * @info: pointer to the shell info structure
  * @buffer: pointer to the temporary storage area
  * @position: pointer to the location of a document
  */ 
int is_chain(ShellInfo *info, char *buffer, size_t *position)
{
size_t curr_pos = *position;

if (buffer[curr_pos] == '|' && buffer[curr_pos + 1] == '|')
{
buffer[curr_pos] = 0;
curr_pos++;
info->cmd_buf_type = CMD_OR;
}
else if (buffer[curr_pos] == '&' && buffer[curr_pos + 1] == '&')
{
buffer[curr_pos] = 0;
curr_pos++;
info->cmd_buf_type = CMD_AND;
}
else if (buffer[curr_pos] == ';')
{
buffer[curr_pos] = 0;
info->cmd_buf_type = CMD_CHAIN;
}
else
{
return (0);
}
*position = curr_pos;
return (1);
}
