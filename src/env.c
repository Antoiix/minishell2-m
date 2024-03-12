/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** env.c
*/

#include "my.h"

void env_command(list_t *list, char *buf, int *status)
{
    char **args = my_str_to_word_array(buf, " \n\t");

    if (args[1]) {
        write(2, "env: '", 6);
        write(2, args[1], my_strlen(args[1]));
        write(2, "': No such file or directory\n", 29);
        *status = 127;
        return;
    }
    for (list_t *tmp = list; tmp; tmp = tmp->next) {
        mini_printf("%s=%s\n", tmp->arg, tmp->val);
    }
    *status = 0;
}
