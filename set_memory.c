#include "main.h"
/**
  * set_memory - to allocate memory to a data structure
  * @mem: pointer to the memory
  * @blocksize: unit of memory allocation
  */ 
char *set_memory(char *mem_blk, char value, unsigned int blck_size)
{
unsigned int i;

for (i = 0; i < blck_size; i++)
{
mem_blck[i] = value;
}
return (mem_blck);
}
