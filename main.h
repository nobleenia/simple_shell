#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

#define GETLINE 0

typedef struct liststr
{
  int num;
  char *str;
  struct liststr *next;
} list_t;

typedef struct passinfo
{
  char *arg;
  char **argv;
  int line_count_flag;
  char ** cmd_buffer;
  int readfd;
} ShellInfo;

typedef struct builtin
{
  char *type;
  int (*func)(ShellInfo *);
} builtin_table;

/*Character Handling*/
int _putchar(char c);
void _puts(char *str);
char *str_cat(char *str1, char *str2);
int str_len(char *s);
char *str_cpy(char *src_str, char *dst_str);
char *str_dup(const char *str);
int str_cmp(char *str1, char *str2);
char *spec_strcat(char *src, char *dest, int n);
char *spec_strcpy(char *src, char *dest, int n);

/*Read User Input*/
int interactive_mode(ShellInfo *info);
int check_delimiter(char c, char *delimiter);
char *spec_strchr(char *str, char c);
ssize_t read_input(ShellInfo *info, char **buffer, size_t *buffer_size);
int get_line(ShellInfo *info, char **line_ptr, size_t *line_len);
ssize_t read_buffer(ShellInfo *info, char *buffer, size_t *len);

/*Tokenization*/
char **split_string(char *str, char *delimiter);

void sigintHandler(__attribute__((unused))int sig_num);
void *_realloc(void *original_ptr, unsigned int old_size, unsigned int new_size);

/*Command Execution*/


int main(void);

#endif
