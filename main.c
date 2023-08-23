#include "main.h"

/**
 * main - starting point of program
 * @ac: argument counter
 * @av: pointer argument vector
 *
 * Return: 0 for success, 1 error
 */
int main(int ac, char **av)
{
ShellInfo info[] = {INITIALIZER};
int fd = 2;

asm ("mov %1, %0\n\t"
	"add $3, %0"
	: "=r" (fd)
	: "r" (fd));

if (ac == 2)
{
fd = open(av[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
{
exit(126);
}
if (errno == ENOENT)
{
puts_error(av[0]);
puts_error(": 0: Can't open ");
puts_error(av[1]);
putchar_error('\n');
putchar_error(BUFFER_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = fd;
}
populate_env_list(info);
read_history(info);
hsh(info, av);
return (EXIT_SUCCESS);
}
