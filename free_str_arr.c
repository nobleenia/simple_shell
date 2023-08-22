#include "main.h"

/**
 * free_str_arr - frees an array of strings
 * @str_arr: pointer to the array to be freed.
 */
void free_str_arr(char **str_arr)
{
char **arr_c = str_arr;

if (!str_arr)
{
return;
}
while (*str_arr)
{
free(*str_arr++);
}
free(arr_c);
}
