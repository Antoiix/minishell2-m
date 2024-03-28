/*
** EPITECH PROJECT, 2024
** minishell2-m
** File description:
** command_parse.c
*/

#include "my.h"

void print_com_list(command_t **com_list)
{
    for (int i = 0; com_list[i] != NULL; i++) {
        mini_printf("%s\n", com_list[i]->command);
        if (com_list[i + 1] != NULL)
            mini_printf("%c\n", com_list[i]->sep);
    }
}

void command_dump(char *buf, int *buf_tmp, command_t **com_list, int i)
{
    if (buf[*buf_tmp + 1] == buf[*buf_tmp] && buf[*buf_tmp] == '>') {
        com_list[i]->sep = 'r';
        *buf_tmp = *buf_tmp + 1;
    }
    if (buf[*buf_tmp + 1] == buf[*buf_tmp] && buf[*buf_tmp] == '<') {
        com_list[i]->sep = 'l';
        *buf_tmp = *buf_tmp + 1;
    }
    *buf_tmp = *buf_tmp + 1;
}

command_t **com_list_c(char *buf)
{
    char **command = my_str_to_word_array(buf, "<>|\n");
    command_t **com_list = malloc(sizeof(command_t *) *
        (size_arr(command) + 1));
    int buf_tmp = 0;
    int i;

    for (i = 0; command[i] != NULL; i++) {
        com_list[i] = malloc(sizeof(command_t));
        com_list[i]->command = my_strdup(command[i]);
        buf_tmp += my_strlen(command[i]);
        com_list[i]->sep = buf[buf_tmp];
        command_dump(buf, &buf_tmp, com_list, i);
    }
    com_list[i] = NULL;
    free_arr(command);
    return com_list;
}
