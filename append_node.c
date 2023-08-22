#include "main.h"
/**
  * append_node - append a node to the end of a linked list
  * @head: pointer to the first node in the linked list
  * @s: the strings to be printed
  * @num: represents a numeric value
  */
list_t *append_node(list_t **head, const char *str, int num)
{
list_t *new_node, *node;

if (!head)
{
return (NULL);
}

node = *head;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
set_memory((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = str_dup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*head = new_node;
return (new_node);
}
