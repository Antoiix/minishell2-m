/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** free.c
*/

#include "my.h"

void free_arr(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr[i]);
    free(arr);
}

void free_list(list_t **head)
{
    list_t *current = *head;
    list_t *next;

    while (current != NULL) {
        next = current->next;
        free(current->arg);
        free(current->val);
        free(current);
        current = next;
    }
}
