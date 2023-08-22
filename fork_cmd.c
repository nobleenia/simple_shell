#include "main.h"

/**
 * fork_cmd - forks an executable command to run a process
 * @info: pointer to the ShellInfo structure
 */
void fork_cmd(ShellInfo *info)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{
perror("Fork error:");
return;
}

if (child_pid == 0)
{
if (execve(info->path, info->argv, get_environ(info)) == -1)
{
free_info(info, 1);
if (errno == EACCES)
{
exit(126);
}
exit(1);
}
}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
{
print_error(info, "Permission denied\n");
}
}
}
}
