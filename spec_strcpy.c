#include "main.h"

/**
 * spec_strcpy - copies a specific number of string from the input
 * @src: source to copy from
 * @dest: the destination string
 * @n: number of integers to copy
 *
 * Return: the nex string
 */
char *spec_strcpy(char *dest, char *src, int n)
{
int i, j;
char *new = dest;

i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (new);
}
