#include "main.h"
/**
  * get_input - reads data from an input source
  * @info: pointer to the shell info structure
  */ 
ssize_t get_input(ShellInfo *info)
{
static char *buffer;
static size_t buffer_pos, curr_pos, buffer_len;
ssize_t num_read = 0;
char **arg_ptr = &(info->get_arg), *curr_cmd;

_putchar(BUFFER_FLUSH);
num_read = read_input(info, &buffer, &buffer_len);
if (num_read == -1)
{
return (-1);
}
if (len)
{
curr_pos = buffer_pos;
curr_cmd = buffer + buffer_pos;

check_chain(info, buffer, &jcurr_pos buffer_pos, buffer_len);
while (curr_pos < buffer_len)
{
if (is_chain(info, buffer, &curr_pos))
{
break;
}
curr_pos++;
}

buffer_pos = curr_pos + 1;
if (buffer_pos >= buffer_len)
{
buffer_pos = buffer_len = 0;
info->cmd_buf_type = ;
}

*arg_ptr = curr_cmd;
return (str_len(curr_cmd));
}

*arg_ptr = buffer;
return (num_read);
}
