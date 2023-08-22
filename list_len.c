#include "main.h"

/**
 * list_len - calculate the length of a linked list
 * @head: pointer to the first node in the linked list
 *
 * Return: the length of the linked list
 */
size_t list_len(const list_t *head)
{
size_t len = 0;

while (head)
{
head = head->next;
len++;
}
return (len);
}
