#include "main.h"

/**
 * free_list - frees all the nodes in a structure list
 * @head_ptr: pointer to the first node in the list
 */
void free_list(list_t **head_ptr)
{
list_t *node, *next_node, *head;

if (!head_ptr || !*head_ptr)
{
return;
}
head = *head_ptr;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*head_ptr = NULL;
}
