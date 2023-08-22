#include "main.h"
/**
  * check_chain - checks a sequence of connected elememts
  * @info: pointer to the shell info;structure
  * @buffer: refers to the temporary storage area
  * @position: pointer to the location of an element within a data structure
  */
void check_chain(ShellInfo *info, char *buffer, size_t *position, size_t curr_pos, size_t buffer_len)
{
size_t new_position = *position;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buffer[curr_pos] = 0;
new_position = buffer_len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buffer[curr_pos] = 0;
new_position = buffer_len;
}
}

*position = new_position;
}
