#include "main.h"

/**
 * safe_free - frees all memory pointers
 * @mem_ptr: memory pointer to be freed
 */
int safe_free(void **mem_ptr)
{
if (mem_ptr && *mem_ptr)
{
free(*mem_ptr);
*mem_ptr = NULL;
return (1);
}
return (0);
}
