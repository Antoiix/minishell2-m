/*
** EPITECH PROJECT, 2023
** my_pf_putstr.c
** File description:
** this file prints a string given and
** add one to a pointer counter.
** created and edited by Antoine Orange
** and Pauline Seret.
** All rights reserved
*/

#include "my.h"

int my_pf_putstr(char const *str, int *count)
{
    int i = 0;

    while (str[i] != '\0') {
        my_pf_putchar(str[i], count);
        i += 1;
    }
    return 0;
}
