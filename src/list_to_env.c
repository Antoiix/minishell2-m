/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** list_to_env.c
*/

#include "my.h"

void dup_in_str(char *str, list_t *tmp)
{
    my_strcpy(str, tmp->arg);
    my_strcat(str, "=");
    my_strcat(str, tmp->val);
}

char **list_to_env(struct list *list)
{
    char **env = NULL;
    int size;
    char *str;
    int env_s = 0;
    list_t *tmp = list;

    for (list_t *tmp2 = list; tmp2; tmp2 = tmp2->next)
        env_s++;
    env = malloc(sizeof(char *) * (env_s + 1));
    env[env_s] = NULL;
    for (int i = 0; tmp; tmp = tmp->next) {
        str = NULL;
        size = my_strlen(tmp->arg) + my_strlen(tmp->val) + 1;
        str = malloc(sizeof(char) * (size + 1));
        dup_in_str(str, tmp);
        str[size] = '\0';
        env[i] = my_strdup(str);
        i++;
    }
    return env;
}
