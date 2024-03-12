/*
** EPITECH PROJECT, 2023
** my_pf_putchar.c
** File description:
** this file returns a char given and add
** one to a pointer count.
** created and edited by Antoine Orange
** and Pauline Seret.
** All rights reserved
*/

#include "my.h"

void my_pf_putchar(char c, int *count)
{
    write(1, &c, 1);
    *count += 1;
}
