/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** this file compare n letters in the
** ASCII table.
** created and edited by Antoine Orange.
** All rights reserved
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i != n; i++) {
        if (s1[i] == '\0' || s2[i] == '\0') {
            return s1[i] - s2[i];
        }
        if (s1[i] - s2[i] != 0) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
