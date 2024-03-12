/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** free.c
*/

#include "my.h"

void free_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}
