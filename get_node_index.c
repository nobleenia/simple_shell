#include "main.h"

/**
 * get_node_index - gets the index of a node in a linked list
 * @head: pointer to first node of the linked list
 * @node: pointer to the node whose index is to be determined
 * 
 * Return: index of the node in the list, -1 for failure
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t index = 0;

while (head)
{
if (head == node)
{
return (index);
}
head = head->next;
index++;
}
return (-1);
}
