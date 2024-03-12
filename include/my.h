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
char **my_str_to_word_array(char const *str, char *pattern);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int mini_printf(const char *format, ...);
int my_pf_put_nbr(int nb, int *count);
void my_pf_putchar(char c, int *count);
int my_pf_putstr(char const *str, int *count);
char *my_strdup(char const *src);
void launcher(list_t *list, int *status);
void verif_commands(char *buf, list_t *list, int *status);
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
void exit_command(char *buf);
void del_node(list_t **list, char *str);
void unsetenv_command(list_t *list, char *buf, int *status);
void cd_command(char *buf, list_t *list, int *status);
void free_arr(char **arr);

#endif
