/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** env_to_list.c
*/

#include "my.h"

char *arg_calc(char *env_line)
{
    int size = 0;
    char *arg;
    int i = 0;

    for (; env_line[size] != '='; size++);
    arg = malloc(sizeof(char) * (size + 1));
    for (; i != size; i++)
        arg[i] = env_line[i];
    arg[i] = '\0';
    return arg;
}

char *val_calc(char *env_line)
{
    int size = 0;
    int size2 = 0;
    char *val;

    for (; env_line[size] != '='; size++);
    val = my_strdup(env_line + size + 1);
    for (; env_line[size + 1 + size2] != '\0'; size2++);
    val[size2] = '\0';
    return val;
}

list_t *env_to_list(char **env)
{
    list_t *list = NULL;

    for (int i = 0; env[i] != NULL; i++)
        add_node(&list, arg_calc(env[i]), val_calc(env[i]));
    return list;
}
