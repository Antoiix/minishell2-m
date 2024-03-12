/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** this file duplicates a string on
** a new string.
** created and edited by Antoine Orange.
** All rights reserved
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (i = 0; i < my_strlen(src); i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return str;
}
