/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** this file converts and returns
** a string to a number.
** created and edited by Antoine Orange.
** All rights reserved
*/

int limits(int long a)
{
    if (a < -2147483648 || a > 2147483647) {
        return 0;
    } else {
        return a;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int long nb = 0;
    int neg = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            neg *= -1;
        }
        i += 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb *= 10;
        nb = nb + str[i] - 48;
        i += 1;
        if (nb * neg < -2147483648 || nb * neg > 2147483647) {
            nb = 0;
            return nb;
        }
    }
    return (limits(nb * neg));
}
