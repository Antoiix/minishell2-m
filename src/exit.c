/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** exit.c
*/

#include "my.h"

int exit_command(char *buf, int *status)
{
    char **args = my_str_to_word_array(buf, " ");
    int size;

    for (size = 0; args[size] != NULL; size++);
    if (size > 2) {
        write(2, "exit: Expression Syntax\n", 24);
        free_arr(args);
        return 1;
    }
    if (args[1])
        *status = my_getnbr(args[1]) % 256;
    else
        *status = 0;
    free_arr(args);
    return -1;
}
