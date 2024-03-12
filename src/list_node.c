/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** list_node.c
*/

#include "my.h"

list_t *init_node(char *arg, char *val)
{
    list_t *tmp = malloc(sizeof(list_t));

    tmp->arg = my_strdup(arg);
    tmp->val = my_strdup(val);
    tmp->next = NULL;
    return tmp;
}

void add_node(list_t **list, char *arg, char *val)
{
    list_t *tmp = init_node(arg, val);
    list_t *head;

    if (!*list) {
        *list = tmp;
        return;
    }
    for (head = *list; head->next; head = head->next);
    head->next = tmp;
}

void del_tmp(list_t *tmp, list_t *tmp_bef)
{
    if (!tmp_bef) {
        return;
    }
    if (!tmp->next) {
        tmp_bef->next = NULL;
        return;
    }
    tmp_bef->next = tmp->next;
}

void del_node(list_t **list, char *str)
{
    list_t *tmp_bef = NULL;

    for (list_t *tmp = *list; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->arg, str) == 0) {
            del_tmp(tmp, tmp_bef);
        }
        tmp_bef = tmp;
    }
}
