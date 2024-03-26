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

void exec_loop(char **commands, list_t *list, int *status, int *return_exit)
{
    int return_val;
    int pipe_val;

    for (int i = 0; commands[i] != NULL; i++) {
        pipe_val = piper(commands[i], list, status);
        if (pipe_val == 1)
            continue;
        if (pipe_val == -1) {
            *return_exit = *status;
            break;
        }
        return_val = verif_builtins(commands[i], list, status);
        if (return_val == 1)
            continue;
        if (return_val == -1) {
            *return_exit = *status;
            continue;
        }
        verif_commands(commands[i], list, status);
    }
}

int exec_suite(char *buf, list_t *list, int *status)
{
    char **commands = my_str_to_word_array(buf, ";\n");
    int return_exit = -1;

    exec_loop(commands, list, status, &return_exit);
    if (return_exit != -1) {
        mini_printf("exit\n");
        free_arr(commands);
        return -1;
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
