char *spec_strcat(char *src, char *dest, int n)
{
int i = 0;
int j = 0;
char *new = dest;

while (dest[i] != '\0')
{
i++;
}
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
{
dest[i] = '\0';
}
return (new);
}
