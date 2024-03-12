/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** exit.c
*/

#include "my.h"

void exit_command(char *buf)
{
    char **args = my_str_to_word_array(buf, " ");
    int size;

    for (size = 0; args[size] != NULL; size++);
    if (size > 2) {
        write(2, "exit: Expression Syntax\n", 24);
        return;
    }
    mini_printf("exit\n");
    if (args[1])
        exit(my_getnbr(args[1]) % 256);
    exit(0);
}
