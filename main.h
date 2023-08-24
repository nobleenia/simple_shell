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

#define CMD_NORM 0
#define CMD_AND 2
#define CMD_OR 1
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2


#define HISTORY_FILE ".simple_shell_history"
#define HISTORY_MAX 4096

extern char **environ;

typedef struct liststr
{
  int num;
  char *str;
  struct liststr *next;
} list_t;

typedef struct
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
  char *file_name;
  char **environ;
  int env_changed;
  list_t *history;
  list_t *alias;
  int err_num;
  int argc;
  int cmd_buf_type;
  int error_no;
  int history_count;
} ShellInfo;

#define INITIALIZER {NULL, NULL, 0, NULL, 0, NULL, 0, 0, NULL, NULL, NULL, 0, NULL, NULL, 0, 0, 0, 0, 0}

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
ssize_t get_input(ShellInfo *info);

/*Tokenization*/
char **split_string(char *str, char *delimiter);

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
int my_env(ShellInfo *info);
int my_setenv(ShellInfo *info);
int populate_env_list(ShellInfo *info);

/*Deal with Aliases*/
int print_alias(list_t *alias_node);
int custom_alias(ShellInfo *info);
int set_alias(ShellInfo *info, char *alias_str);
int unset_alias(ShellInfo *info, char *alias_name);
int replace_alias(ShellInfo *info);

char *ext_substr(char *pathstr, int start, int stop);
char *starting_char(const char *str, const char *needle);
char **get_environ(ShellInfo *info);
void free_info(ShellInfo *info, int all);
void free_str_arr(char **str_arr);
void free_list(list_t **head_ptr);
int safe_free(void **mem_ptr);
char **list_to_strings(list_t *head);
size_t list_len(const list_t *head);
int print_decimal(int input, int fd);
int spec_atoi(char *str);
char *convert_number(long int num, int base, int flags);
int replace_string(char **old_str, char *new_str);
void check_chain(ShellInfo *info, char *buffer, size_t *position, size_t curr_pos, size_t buffer_len);
int is_chain(ShellInfo *info, char *buffer, size_t *position);
char *set_memory(char *mem_blk, char value, unsigned int blck_size);
void sigintHandler(__attribute__((unused))int sig_num);
void *_realloc(void *original_ptr, unsigned int old_size, unsigned int new_size);
size_t print_list(const list_t *head);
void clear_info(ShellInfo *info);
void set_info(ShellInfo *info, char **av);
int write_history(ShellInfo *info);
char *get_history_file(ShellInfo *info);
int write_string_to_fd(char *str, int fd);
int write_to_fd(char c, int fd);
int read_history(ShellInfo *info);
int build_history_list(ShellInfo *info, char *buffer, int line_count);
int renumber_history(ShellInfo *info);

/*Error Handling*/
void puts_error(char *str);
int putchar_error(char c);
void print_error(ShellInfo *info, char *str);

/*Node Manipulations*/
list_t *check_haystack(list_t *head, char *prefix, char opt_char);
list_t *append_node(list_t **head, const char *str, int num);
int del_node(list_t **head, unsigned int index);
ssize_t get_node_index(list_t *head, list_t *node);

/*Variable Replacement*/
int replace_vars(ShellInfo *info);

/*Handle Comments*/
void handle_comments(char *buffer);

/*Handle Built-in Commands*/
int custom_help(ShellInfo *info);
int shell_history(ShellInfo *info);
size_t print_list_str(const list_t *head);
int change_dir(ShellInfo *info);
int find_builtin_cmd(ShellInfo *info);

/*Shell Loop*/
int hsh(ShellInfo *info, char **argv);

int main(int ac, char **av);

#endif
