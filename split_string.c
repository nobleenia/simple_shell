#include "main.h"

/**
 * split_string - splits a string into words ignoring repeated delimiter
 * @str: strings to be split into words
 * @delimiter: delimiter to be considered
 *
 * Return: array of words
 */
char **split_string(char *str, char *delimiter)
{
int i, j, k, m, num_words = 0;
char **word_arr;

if (str == NULL || str[0] == '\0')
{
return (NULL);
}

if (!delimiter)
{
delimiter = " ";
}

for (i = 0; str[i] != '\0'; i++)
{
if (!check_delimiter(str[i], delimiter) && (check_delimiter(str[i + 1], delimiter) || !str[i + 1]))
{
num_words++;
}
}

if (num_words == 0)
{
return (NULL);
}

word_arr = (char **)malloc((1 + num_words) * sizeof(char *));
if (!word_arr)
{
return (NULL);
}

for (i = 0, j = 0; j < num_words; j++)
{
while (check_delimiter(str[i], delimiter))
{
i++;
}
k = 0;
while (!check_delimiter(str[i + k], delimiter) && str[i + k])
{
k++;
}

word_arr[j] = (char *)malloc((k + 1) * sizeof(char));
if (!word_arr[j])
{
for (k = 0; k < j; k++)
{
free(word_arr[k]);
}
free(word_arr);
return (NULL);
}

for (m = 0; m < k; m++)
{
word_arr[j][m] = str[i++];
}
word_arr[j][m] = '\0';
}

word_arr[j] = NULL;
return (word_arr);
}
