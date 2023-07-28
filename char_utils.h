#ifndef CHAR_UTILS_H
#define CHAR_UTILS_H

void custom_stderr(const char *error_msg);
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
#endif /* CHAR_UTILS_H */

