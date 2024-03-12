/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** launcher.c
*/

#include "my.h"

void launcher(list_t *list, int *status)
{
    size_t size = 0;
    char *buf = NULL;

    while (1) {
        if (isatty(STDIN_FILENO) != 0)
            mini_printf("$> ");
        if (getline(&buf, &size, stdin) == -1)
            return;
        if (my_strlen(buf) == 1)
            continue;
        buf[my_strlen(buf)] = '\0';
        if (verif_builtins(buf, list, status) == 1)
            continue;
        verif_commands(buf, list, status);
    }
}
