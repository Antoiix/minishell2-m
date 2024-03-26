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

int exec_suite(char *buf, list_t *list, int *status)
{
    int return_val;
    char **commands = my_str_to_word_array(buf, ";\n");

    for (int i = 0; commands[i] != NULL; i++) {
        if (piper(commands[i], list, status) == 1)
            continue;
        return_val = verif_builtins(commands[i], list, status);
        if (return_val == 1)
            continue;
        if (return_val == -1) {
            free_arr(commands);
            return -1;
        }
        verif_commands(commands[i], list, status);
    }
    free_arr(commands);
    return 0;
}

void launcher(list_t *list, int *status)
{
    size_t size = 0;
    char *buf = NULL;

    while (1) {
        if (get_command(&buf, &size) == 1)
            break;
        if (my_strlen(buf) == 1)
            continue;
        buf[my_strlen(buf)] = '\0';
        if (exec_suite(buf, list, status) == -1)
            break;
    }
    free(buf);
}
