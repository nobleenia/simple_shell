#include "main.h"

/**
 * spec_strcat - concatenates two strings
 * @str1: the first string
 * @str2: the second string
 * @n: the amount of bytes to be maximally used
 * 
 * Return: the concatenated string
 */
char *spec_strcat(char *str1, char *str2, int n)
{
int i = 0;
int j = 0;
char *new = str1;

while (str1[i] != '\0')
{
i++;
}
while (str2[j] != '\0' && j < n)
{
str1[i] = str2[j];
i++;
j++;
}
if (j < n)
{
str1[i] = '\0';
}
return (new);
}
