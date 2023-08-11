#ifndef "MAIN_H"
#define "MAIN_H"

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


struct dirent {
ino_t d_ino;       /* Inode number */
off_t d_off;       /* Not an offset; see below */
unsigned short d_reclen;    /* Length of this record */
unsigned char  d_type; /* Type of file; not supported by all filesystem types */
char d_name[256]; /* Null-terminated filename */
};



int access(const char *pathname, int mode);
int chdir(const char *path);
int close(int fd);
int closedir(DIR *dirp);
int execve(const char *pathname, char *const argv[],char *const envp[]);
void exit(int status);
void _Exit(int status);
int fflush(FILE *stream);
pid_t fork(void);
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
char *getcwd(char *buf, size_t size);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
pid_t getpid(void);
int isatty(int fd);
int kill(pid_t pid, int sig);
int open(const char *pathname, int flags);
DIR *opendir(const char *name);
void perror(const char *s);
ssize_t read(int fd, void *buf, size_t count);
struct dirent *readdir(DIR *dirp);
sighandler_t signal(int signum, sighandler_t handler);
int stat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);
char *strtok(char *str, const char *delim);
pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *wstatus, int options);
int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
ssize_t write(int fd, const void *buf, size_t count);

#endif
