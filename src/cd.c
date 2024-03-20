/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** cd.c
*/

#include "my.h"

void cd_home(list_t *list)
{
    list_t *tmp = list;
    list_t *tmp2 = list;

    for (; my_strcmp(tmp->arg, "HOME") != 0; tmp = tmp->next);
    chdir(tmp->val);
    for (; my_strcmp(tmp2->arg, "PWD") != 0; tmp2 = tmp2->next);
    free(tmp2->val);
    tmp2->val = my_strdup(tmp->val);
}

void write_on_env(list_t *list)
{
    list_t *tmp = list;

    for (; my_strcmp(tmp->arg, "PWD") != 0; tmp = tmp->next);
    free(tmp->val);
    tmp->val = malloc(PATH_MAX);
    getcwd(tmp->val, PATH_MAX);
}

void write_prev_pwd(list_t *list)
{
    list_t *tmp = list;
    list_t *tmp2 = list;
    int is_old = 0;

    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->arg, "OLDPWD") == 0) {
            is_old = 1;
            break;
        }
    }
    for (; my_strcmp(tmp2->arg, "PWD") != 0; tmp2 = tmp2->next);
    if (is_old == 0) {
        add_node(&list, "OLDPWD", tmp2->val);
        return;
    }
    free(tmp->val);
    tmp->val = my_strdup(tmp2->val);
}

static int exec_cd_back(list_t *tmp, char **arg, int *status)
{
    int is_old = 0;

    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->arg, "OLDPWD") == 0) {
            is_old = 1;
            break;
        }
    }
    if (is_old == 0) {
        *status = 1;
        write(2, ": No such file or directory.\n", 30);
        return 1;
    }
    free(*arg);
    *arg = my_strdup(tmp->val);
    *status = 0;
    return 0;
}

int cd_back(char **arg, list_t *list, int *status)
{
    list_t *tmp = list;

    if (my_strcmp(*arg, "-") == 0) {
        if (exec_cd_back(tmp, arg, status) == 1)
            return 1;
    }
    return 0;
}

static void print_cd_error(char **args)
{
    DIR *directory = opendir(args[1]);

    if (!directory) {
        write(2, args[1], my_strlen(args[1]));
        write(2, ": Not a directory.\n", 19);
        return;
    }
    closedir(directory);
    write(2, args[1], my_strlen(args[1]));
    write(2, ": Permission denied.\n", 21);
}

static void classic_cd(list_t *list, char **args, int *status)
{
    if (my_strcmp(args[1], "~") == 0) {
        cd_home(list);
        *status = 0;
        return;
    }
    if (chdir(args[1]) == 0) {
        write_prev_pwd(list);
        write_on_env(list);
    } else {
        if (access(args[1], F_OK) == 0) {
            print_cd_error(args);
            *status = 1;
            return;
        }
        mini_printf("%s: No such file or directory.\n", args[1]);
        *status = 1;
    }
}

static int cd_error(int size, int *status, char **args)
{
    if (size > 2) {
        mini_printf("cd: Too many arguments.\n");
        *status = 1;
        free_arr(args);
        return 1;
    }
    return 0;
}

void cd_command(char *buf, list_t *list, int *status)
{
    char **args = my_str_to_word_array(buf, " \n");
    int size;

    for (size = 0; args[size] != NULL; size++);
    if (cd_error(size, status, args) == 1)
        return;
    if (size == 1) {
        write_prev_pwd(list);
        cd_home(list);
        *status = 0;
        free_arr(args);
        return;
    }
    if (cd_back(&args[1], list, status) == 1) {
        free_arr(args);
        return;
    }
    classic_cd(list, args, status);
    free_arr(args);
}
