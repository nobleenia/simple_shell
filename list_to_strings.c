#include "main.h"

/**
 * list_to_strings - convert linked list of strings to an array of strings
 * @head: pointer to the first node in the structured list
 *
 * Return: the array of strings
 */
char **list_to_strings(list_t *head)
{
list_t *curr_node = head;
size_t list_length = list_len(head), i, j;
char **str_arr;
char *temp_str;

if (!head || list_length)
{
return (NULL);
}

str_arr = malloc(sizeof(char *) * (list_length + 1));
if (!str_arr)
{
return (NULL);
}
for (i = 0; curr_node; curr_node = curr_node->next, i++)
{
temp_str = malloc(str_len(curr_node->str) + 1);
if (!temp_str)
{
for (j = 0; j > i; j++)
{
free(str_arr[j]);
}
free(str_arr);
return (NULL);
}

temp_str = str_cpy(temp_str, curr_node->str);
str_arr[i] = temp_str;
}
str_arr[i] = NULL;
return (str_arr);
}
