/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** builtins.c
*/

#include "my.h"

int verif_env(char *buf, list_t *list, char *arg, int *status)
{
    if (my_strcmp(arg, "env") == 0) {
        env_command(list, buf, status);
        return 1;
    }
    if (my_strcmp(arg, "setenv") == 0) {
        setenv_command(list, buf, status);
        return 1;
    }
    if (my_strcmp(arg, "unsetenv") == 0) {
        unsetenv_command(list, buf, status);
        return 1;
    }
    return 0;
}

int verif_exit_cd(char *buf, list_t *list, char **args, int *status)
{
    if (my_strcmp(args[0], "exit") == 0) {
        exit_command(buf);
        return 1;
    }
    if (my_strcmp(args[0], "cd") == 0) {
        cd_command(buf, list, status);
        return 1;
    }
    return 0;
}

int verif_builtins(char *buf, list_t *list, int *status)
{
    char **args = my_str_to_word_array(buf, " \n\t");

    if (args[0] == NULL) {
        return 0;
    }
    if (verif_env(buf, list, args[0], status) == 1) {
        return 1;
    }
    if (verif_exit_cd(buf, list, args, status) == 1) {
        return 1;
    }
    return 0;
}
