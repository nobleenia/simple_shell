#include "main.h"

/**
 * 
 * 
 * 
 */
void _print_buffer(char buffer[], int *buffer_index)
{
    if (*buffer_index > 0)
    {
        write(1, &buffer[0], *buffer_index);
    }
    *buffer_index = 0;
}
