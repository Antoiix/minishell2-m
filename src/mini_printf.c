/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** this file can print simple
** flags of printf.
** created and edited by Antoine Orange.
** All rights reserved
*/

#include "my.h"

void if_case(const char *format, int i, va_list disp_params, int *count)
{
    switch (format[i + 1]) {
        case 'c':
            my_pf_putchar((char)va_arg(disp_params, int), count);
            break;
        case 'i':
            my_pf_put_nbr(va_arg(disp_params, int), count);
            break;
        case 'd':
            my_pf_put_nbr(va_arg(disp_params, int), count);
            break;
        case 's':
            my_pf_putstr(va_arg(disp_params, char *), count);
            break;
        case '%':
            my_pf_putchar('%', count);
            break;
        default:
            my_pf_putchar(format[i], count);
            my_pf_putchar(format[i + 1], count);
    }
}

int verif_if(const char *format, int i, va_list disp_params, int *count)
{
    if (format[i] == '%') {
        if_case(format, i, disp_params, count);
        i += 2;
    } else {
        my_pf_putchar(format[i], count);
        i++;
    }
    return i;
}

int mini_printf(const char *format, ...)
{
    va_list disp_params;
    int count = -1;

    va_start(disp_params, format);
    for (int i = 0; format[i] != '\0';) {
        i = verif_if(format, i, disp_params, &count);
    }
    va_end(disp_params);
    return count;
}
