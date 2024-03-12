/*
** EPITECH PROJECT, 2023
** my_pf_put_nbr.c
** File description:
** this file prints a number given and
** add one to a pointer counter.
** created and edited by Antoine Orange
** and Pauline Seret.
** All rights reserved
*/

#include "my.h"

int my_pf_put_nbr(int nb, int *count)
{
    long int nb2 = nb;

    if (nb2 < 0) {
        nb2 *= -1;
        my_pf_putchar(45, count);
    }
    if (nb2 >= 10) {
        my_pf_put_nbr(nb2 / 10, count);
        my_pf_putchar(nb2 % 10 + 48, count);
    } else {
        my_pf_putchar(nb2 + 48, count);
    }
    return 0;
}
