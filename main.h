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


#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

int _putchar(char c);
void _puts(char *str);
char *str_cat(char *str1, char *str2);
int str_len(char *s);
char *str_cpy(char *src_str, char *dst_str);
char *str_dup(const char *str);
int str_cmp(char *str1, char *str2);

int main(void);
#endif
