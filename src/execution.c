/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** execution.c
*/

#include "my.h"

void print_status(int *status, int return_val)
{
    if (return_val == 0 || return_val == -1) {
        return;
    }
    if (WTERMSIG(return_val) == return_val) {
        return;
    }
    *status = return_val % 255;
    if (return_val == 136)
        write(2, "Floating exception", 18);
    else
        write(2, strsignal(WTERMSIG(return_val)),
            my_strlen(strsignal(WTERMSIG(return_val))));
    if (WCOREDUMP(return_val))
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
}

int error_commands(char **args, char **path, int *status, list_t *list)
{
    if (args[0] == NULL) {
        return 1;
    }
    if (put_on_path(path, args, list) == 0) {
        free(*path);
        *status = 1;
        return 1;
    }
    return 0;
}

void verif_commands(char *buf, list_t *list, int *status)
{
    char **args;
    int val_f;
    char *path = NULL;

    args = my_str_to_word_array(buf, " \n\t");
    if (error_commands(args, &path, status, list) == 1) {
        free_arr(args);
        return;
    }
    val_f = fork();
    if (val_f == 0)
        command_exec(path, args, list);
    free_arr(args);
    free(path);
}
