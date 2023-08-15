#include "main.h"

/**
 *
 *
 *
 *
 */
int main(void)
{
char *line = NULL;
size_t length = 0;
ssize_t read;
pid_t child;

while (1)
{
printf("($) ");

read = getline(&line, &length, stdin);
if (read == -1)
{
printf("\n");
break;
	}
if (line[read - 1] == '\n')
{
line[read - 1] = '\0';
}

child = fork();

if (child == -1)
{
perror("fork failed");
}
else if (child == 0)
{
char *as[2];
as[0] = line;
as[1] = NULL;

execve(as[0], as, NULL);

perror(as[0]);
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(child, &status, 0);
}
}
free(line);
return 0;
}
