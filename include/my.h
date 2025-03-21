/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** contains all of prototypes
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include "sys/stat.h"
    #include <sys/wait.h>
    #include "signal.h"
    #include "limits.h"
    #include <dirent.h>

typedef struct list {
    char *arg;
    char *val;
    struct list *next;
} list_t;
typedef struct command_s {
    char *command;
    char sep;
} command_t;
char **my_str_to_word_array(char const *str, char *pattern);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int mini_printf(const char *format, ...);
int my_pf_put_nbr(int nb, int *count);
void my_pf_putchar(char c, int *count);
int my_pf_putstr(char const *str, int *count);
char *my_strdup(char const *src);
void launcher(list_t *list, int *status);
void verif_commands(char *buf, list_t *list, int *status, int wait_int);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int verif_builtins(char *buf, list_t *list, int *status);
list_t *env_to_list(char **env);
void env_command(list_t *list, char *buf, int *status);
char **list_to_env(struct list *list);
void add_node(list_t **list, char *arg, char *val);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
void setenv_command(list_t *list, char *buf, int *status);
int exit_command(char *buf, int *status);
void del_node(list_t **list, char *str);
void unsetenv_command(list_t *list, char *buf, int *status);
void cd_command(char *buf, list_t *list, int *status);
void free_arr(char **arr);
void free_list(list_t **head);
int error_commands(char **args, char **path, int *status, list_t *list);
int put_on_path(char **path, char **args, list_t *list);
void command_exec(char *path, char **args, list_t *list);
int size_arr(char **arr);
int piper(char *buf, list_t *list, int *status);
void print_status(int *status, int return_val);
command_t **com_list_c(char *buf);
void print_com_list(command_t **com_list);
void free_command(command_t **com_list_c);
int size_com(command_t **com_list);
char *clean_str(char *str);
int redirect_l(char *command, list_t *list, int *status);
int redirect_d(char *command, list_t *list, int *status);
int line_exec(char *buf, list_t *list, int *status, int wait_int);
void redir_loop(command_t **command, int val[2], list_t *list, int *status);

#endif
