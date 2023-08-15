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
  size_t len = 0;
  ssize_t read;

  pid_t child;

  char *args[] = {line, NULL};
  
  while (1)
    {
  
  printf("($) ");

  read = getline(&line, &len, stdin);

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
     char *args[] = {line, NULL};
      execve(line, args, NULL);

      perror(line);
      exit(EXIT_FAILURE);
    }
  else
    {
      int status;
      waitpid(child, &status, 0);
    }
    }
  free(line);
  return (0);
}
