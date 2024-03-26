/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** launcher.c
*/

#include "my.h"

int get_command(char **buf, size_t *size)
{
    if (isatty(STDIN_FILENO) != 0)
        mini_printf("$> ");
    if (getline(buf, size, stdin) == -1)
        return 1;
    return 0;
}

void launcher(list_t *list, int *status)
{
    size_t size = 0;
    char *buf = NULL;
    int return_val;

    while (1) {
        if (get_command(&buf, &size) == 1)
            break;
        if (my_strlen(buf) == 1)
            continue;
        buf[my_strlen(buf)] = '\0';
        if (piper(buf, list, status) == 1)
            continue;
        return_val = verif_builtins(buf, list, status);
        if (return_val == 1)
            continue;
        if (return_val == -1)
            break;
        verif_commands(buf, list, status);
    }
    free(buf);
}
