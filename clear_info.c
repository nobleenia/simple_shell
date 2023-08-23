#include "main.h"

/**
 * clear_info - clear members of the ShellInfo structure
 * @info: pointer to the ShellInfo structure
 */
void clear_info(ShellInfo *info)
{
info->get_arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}
