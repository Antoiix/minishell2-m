/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** setenv.c
*/

#include "my.h"

int arg_exist(char **args, list_t *list)
{
    char *str = "\0";

    if (args[2])
        str = my_strdup(args[2]);
    for (list_t *tmp = list; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->arg, args[1]) == 0) {
            tmp->val = my_strdup(str);
            return 1;
        }
    }
    return 0;
}

int alpha_contains(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if (('a' <= arg[i] && arg[i] <= 'z') ||
            ('A' <= arg[i] && arg[i] <= 'Z') || arg[i] == '_'
            || ('0' <= arg[i] && arg[i] <= '9'))
            continue;
        else
            return 1;
    }
    return 0;
}

void verif_args2(list_t *list, char **args, int *status)
{
    if (arg_exist(args, list) == 0) {
        if (('a' > args[1][0] || args[1][0] > 'z') &&
            ('A' > args[1][0] || args[1][0] > 'Z') &&
            args[1][0] != '_') {
            write(2, "setenv: Variable name must begin with a letter.\n", 48);
            *status = 1;
            return;
        }
        if (alpha_contains(args[1]) == 1) {
            write(2, "setenv: Variable name must contain "
                "alphanumeric characters.\n", 60);
            *status = 1;
            return;
        }
        add_node(&list, args[1], "\0");
        *status = 0;
    }
}

void verif_args3(list_t *list, char **args, int *status)
{
    if (arg_exist(args, list) == 0) {
        if (('a' > args[1][0] || args[1][0] > 'z') &&
            ('A' > args[1][0] || args[1][0] > 'Z') &&
            args[1][0] != '_') {
            write(2, "setenv: Variable name must begin with a letter.\n", 48);
            *status = 1;
            return;
        }
        if (alpha_contains(args[1]) == 1) {
            write(2, "setenv: Variable name must contain "
                "alphanumeric characters.\n", 60);
            *status = 1;
            return;
        }
        add_node(&list, args[1], args[2]);
        *status = 0;
    }
}

void setenv_command(list_t *list, char *buf, int *status)
{
    char **args = my_str_to_word_array(buf, " \n");
    int size;

    for (size = 0; args[size] != NULL; size++);
    if (size > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        *status = 1;
        return;
    }
    if (size == 1) {
        env_command(list, buf, status);
        return;
    }
    *status = 0;
    if (size == 2) {
        verif_args2(list, args, status);
        return;
    }
    verif_args3(list, args, status);
}
