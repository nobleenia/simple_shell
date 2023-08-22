#include "main.h"
/**
  * del_node - deletes a node in a linked list
  *
  * @head: pointer to the first node in the linked list
  * @index: refers to the location of an element within a data structure 
  */ 
int del_node(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int n = 0;

if (!head || !*head)
{
return (0);
}
if (!index)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (i == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
n++;
prev_node = node;
node = node->next;
}
return (0);
}
