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
  char *get_arg;
  char **argv;
  int line_count_flag;
  char ** cmd_buffer;
  int readfd;
  char *path;
  unsigned int line_count;
  int status;
  list_t *env;
  char *fname;
  char **environ;
  int env_changed;
  list_t *history;
  list_t *alias;
  int err_num;
  int argc;
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
int is_cmd(ShellInfo *info, char *path);
void find_exec_cmd(ShellInfo *info);
char *find_path(ShellInfo *info, char *path_list, char *cmd);
void fork_cmd(ShellInfo *info);

/* Exit Shell*/
int exit_shell(ShellInfo *info);

/*Environment Manipulations*/
int set_env(ShellInfo *info, char *var, char *value);
char *get_env(ShellInfo *info, const char *name);
int spec_unset_env(ShellInfo *info);
int unset_env(ShellInfo *info, char *var);

char *ext_substr(char *pathstr, int start, int stop);
char *starting_char(const char *str, const char *needle);
void print_error(ShellInfo *info, char *str);
char **get_environ(ShellInfo *info);
void free_info(ShellInfo *info, int all);
void free_str_arr(char **str_arr);
void free_list(list_t **head_ptr);
int safe_free(void **mem_ptr);
char **list_to_strings(list_t *head);
size_t list_len(const list_t *head);
int print_decimal(int input, int fd);
void puts_error(char *str);
int putchar_error(char c);
int spec_atoi(char *str);

list_t *append_node(list_t **head, const char *str, int num);
int del_node(list_t **head, unsigned int index);
ssize_t get_input(ShellInfo *info);
void check_chain(ShellInfo *info, char *buffer, size_t *position, size_t curr_pos, size_t buffer_len);
int is_chain(ShellInfo *info, char *buffer, size_t *position);
char *set_memory(char *mem_blk, char value, unsigned int blck_size);

int main(void);

#endif
