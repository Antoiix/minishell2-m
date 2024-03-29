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
    if (my_strcmp(arg, "|") == 0) {
        write(2, "Invalid null command.\n", 22);
        return 1;
    }
    return 0;
}

int verif_cd_exit(char *buf, list_t *list, char **args, int *status)
{
    if (my_strcmp(args[0], "exit") == 0)
        return exit_command(buf, status);
    if (my_strcmp(args[0], "cd") == 0) {
        cd_command(buf, list, status);
        return 1;
    }
    return 0;
}

int verif_builtins(char *buf, list_t *list, int *status)
{
    char **args = my_str_to_word_array(buf, " \n\t");
    int return_val = 0;

    if (args[0] == NULL) {
        free_arr(args);
        return 0;
    }
    if (verif_env(buf, list, args[0], status) == 1) {
        free_arr(args);
        return 1;
    }
    return_val = verif_cd_exit(buf, list, args, status);
    free_arr(args);
    if (return_val == 1)
        return 1;
    if (return_val == -1)
        return -1;
    return 0;
}
