/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** this file compares two strings with
** ASCII table.
** created and edited by Antoine Orange.
** All rights reserved
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != 0 || s2[i] != 0; i++) {
        if (s1[i] - s2[i] != 0) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
