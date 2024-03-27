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

int exec_for(char **commands, int *tmp_val[2], list_t *list, int *return_exit)
{
    int i;

    for (i = 0; commands[i] != NULL; i++) {
        *tmp_val[1] = piper(commands[i], list, tmp_val[0]);
        if (*tmp_val[1] == 1)
            continue;
        if (*tmp_val[1] == -1) {
            *return_exit = *tmp_val[1];
            break;
        }
        *tmp_val[1] = verif_builtins(commands[i], list, tmp_val[0]);
        if (*tmp_val[1] == 1)
            continue;
        if (*tmp_val[1] == -1) {
            *return_exit = *tmp_val[0];
            continue;
        }
        verif_commands(commands[i], list, tmp_val[0], 1);
    }
    return i;
}

void exec_loop(char **commands, list_t *list, int *status, int *return_exit)
{
    int *tmp_val[2];
    int k = 0;

    tmp_val[0] = status;
    tmp_val[1] = &k;
    exec_for(commands, tmp_val, list, return_exit);
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
