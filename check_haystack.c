#include "main.h"

/**
 * check_haystack - find a node with a string starting with
 * a prefix and optional character
 * @head: pointer to the head of the linked list
 * @prefix: prefix to search for at the start of strings
 * @opt_char: character to check for in found strings
 *
 * Return: pointer to the found node, or NULL if not found 
 */
list_t *check_haystack(list_t *head, char *prefix, char opt_char)
{
char *start = NULL;
list_t *curr_node = head;

while (curr_node)
{
start = starting_char(curr_node->str, prefix);
if (start && ((opt_char == -1) || (*start == opt_char)))
{
return (curr_node);
}
curr_node = curr_node->next;
}
return (NULL);
}
