/*
** EPITECH PROJECT, 2024
** navy
** File description:
** main.c
*/

#include "my.h"

int main(int ac, __attribute_maybe_unused__ char **av, char **env)
{
    list_t *list = NULL;
    int status = 0;

    list = env_to_list(env);
    if (ac != 1)
        return 84;
    launcher(list, &status);
    return status;
}
