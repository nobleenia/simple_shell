#include "main.h"

/**
 * print_list_str - prints the strings stored in a linked list
 * @head: pointer to first node of the linked list
 *
 * Return: number of nodes printed
 */
size_t print_list_str(const list_t *head)
{
size_t count = 0;

while (head)
{
_puts(head->str ? head->str : "(nil)");
_puts("\n");
head = head->next;
count++;
}
return (count);
}
