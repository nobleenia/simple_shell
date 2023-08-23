#include "main.h"
/**
  * set_memory - to allocate memory to a data structure
  * @mem: pointer to the memory
  * @blocksize: unit of memory allocation
  */ 
char *set_memory(char *mem_blk, char value, unsigned int blck_size)
{
unsigned int n;

for (n = 0; n < blck_size; n++)
{
mem_blk[n] = value;
}
return (mem_blk);
}
