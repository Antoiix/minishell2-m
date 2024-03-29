/*
** EPITECH PROJECT, 2024
** minishell2-m
** File description:
** clean_str.c
*/

#include "my.h"

char *clean_str(char *str)
{
    char new_str[1000];
    char *str_r;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (('A' <= str[i] && str[i] <= 'Z') ||
            ('a' <= str[i] && str[i] <= 'z') ||
            ('0' <= str[i] && str[i] <= '9')) {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    str_r = my_strdup(new_str);
    return str_r;
}
