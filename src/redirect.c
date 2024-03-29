/*
** EPITECH PROJECT, 2024
** minishell2-m
** File description:
** redirect.c
*/

//#define _GNU_SOURCE
#include "my.h"

int redirect_d(char *command, list_t *list, int *status)
{
    char **args;

    args = my_str_to_word_array(command, " \n\t");
    if (args[0] == NULL) {
        free_arr(args);
        return -1;
    }
    if (my_strcmp(args[0], "exit") != 0) {
        line_exec(command, list, status, 0);
    }
    free_arr(args);
    return 0;
}

int redirect_l(char *command, list_t *list, int *status)
{
    char **args;

    args = my_str_to_word_array(command, " \n\t");
    if (args[0] == NULL) {
        free_arr(args);
        return -1;
    }
    if (my_strcmp(args[0], "exit") != 0) {
        line_exec(command, list, status, 1);
    }
    free_arr(args);
    return 0;
}

void redir_loop(command_t **command, int val[2], list_t *list, int *status)
{
    int tmp_fd;
    char *str;

    if (command[val[0]]->sep == '>') {
        str = clean_str(command[val[0] + 1]->command);
        tmp_fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0666);
        free(str);
        dup2(tmp_fd, STDOUT_FILENO);
        val[1] = redirect_d(command[val[0]]->command, list, status);
    }
    if (command[val[0]]->sep == 'r') {
        str = clean_str(command[val[0] + 1]->command);
        tmp_fd = open(str, O_CREAT | O_WRONLY | O_APPEND, 0666);
        free(str);
        dup2(tmp_fd, STDOUT_FILENO);
        val[1] = redirect_d(command[val[0]]->command, list, status);
    }
}

/*void redir_l(command_t **command, int val[2], list_t *list, int *status)
{
    int tmp_fd;
    char *str;
    char *input = NULL;
    size_t size = 0;

    if (command[val[0]]->sep == 'l') {
        str = clean_str(command[val[0] + 1]->command);
        tmp_fd = open(".", O_RDWR | O_TMPFILE | O_APPEND, 0666);
        mini_printf("fd %i\n", tmp_fd);
        while (1) {
            mini_printf("? ");
            getline(&input, &size, stdin);
            mini_printf("%s, %s\n", clean_str(input), str);
            if (my_strcmp(clean_str(input), str) == 0) {
                break;
            }
            else {
                write(tmp_fd, input, my_strlen(input));
            }
        }
        free(str);
        dup2(tmp_fd, STDIN_FILENO);
        val[1] = redirect_l(command[val[0]]->command, list, status);
        close(tmp_fd);
    }
}
*/
