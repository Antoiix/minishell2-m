/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** unsetenv.c
*/

#include "my.h"

void unsetenv_command(list_t *list, char *buf, int *status)
{
    char **args = my_str_to_word_array(buf, " \n");
    int size;

    for (size = 0; args[size] != NULL; size++);
    if (size < 2) {
        write(2, "setenv: Too few arguments.\n", 27);
        *status = 1;
        return;
    }
    for (int i = 1; args[i]; i++) {
        del_node(&list, args[i]);
    }
    *status = 0;
}
