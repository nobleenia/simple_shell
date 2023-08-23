#include "main.h"

/**
 * print_list - prints linked list with numeric and string value
 * @head: pointer to the head of the linked list
 *
 * Return: number of nodes printed
 */
size_t print_list(const list_t *head)
{
size_t num = 0;

while (head)
{
_puts(convert_number(head->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(head->str ? head->str : "(nil)");
_puts("\n");
head = head->next;
num++;
}
return (num);
}
