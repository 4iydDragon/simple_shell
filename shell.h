#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4098

extern char **environ;
/**
 * struct liststr - singly linked lists
 * @num: the number fields
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
*@fname: the program's filename
 *@env: linked list local copy of environ var
 *@environ: custom modified copy of environ from  env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd commands
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line inputs
 *@histcount: the history line number count
 *struct passinfo - contains pseudo-arguments to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from the get line containing arguments
 *@argv: an array of strings generated from the arg
 *@path: string path for the current command
 *@argc: the argument counter
 *@line_count: the error counter
 *@err_num: the error code for exit status
 *@linecount_flag: if on count this line of inputs
 */
typedef struct passinfo
{
	char *arg;
        int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int status;
	char **cmd_buf;
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related functions
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
        int (*func)(info_t *);
} builtin_table;

/* atoi func */
int _interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* builints cmds */
int _history(info_t *);
int _alias(info_t *);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
char *_getenv(info_t *, const char *);
int _env(info_t *);
int _customsetenv(info_t *);
int _customunsetenv(info_t *);
int populate_env_list(info_t *);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
int _customexit(info_t *);
int _cd(info_t *);
char **strtow(char *, char *);
int isChain(info_t *info, char *buf, size_t *d);
void checkChainCont(info_t *info, char *buf, size_t *d, size_t i, size_t len);
int substitute_alias(info_t *);
int substitute_vars(info_t *);
int substitute_string(char **, char *);
void prompt(void);

/* customized functions */
int is_executable(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int hsh(info_t *, char **);
int is_builtin(info_t *);
void check_cmd(info_t *);
void fork_cmd(info_t *);
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
void set_info(info_t *, char **);

/* memory management func */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);
void clear_info(info_t *);
void free_info(info_t *, int);

/* my handling error functions */
int _erratoi(char *);
void print_error(info_t *, char *);


/* my functions to handle list nodes */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

#endif

