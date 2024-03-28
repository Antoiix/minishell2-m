/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** pipe.c
*/

#include "my.h"

int line_exec(char *buf, list_t *list, int *status, int wait_int)
{
    int return_val;

    return_val = verif_builtins(buf, list, status);
    if (return_val != 0)
        return return_val;
    verif_commands(buf, list, status, wait_int);
    return 0;
}

void dup_in(int pipe_fd[2])
{
    dup2(pipe_fd[0], STDIN_FILENO);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
}

int pipe_loop(int pipe_fd[2], char **command, list_t *list, int *status)
{
    char **args;
    int i;

    for (i = 0; command[i + 1] != NULL; i++) {
        pipe(pipe_fd);
        dup2(pipe_fd[1], STDOUT_FILENO);
        args = my_str_to_word_array(command[i], " \n\t");
        if (args[0] == NULL) {
            free_arr(args);
            return -1;
        }
        if (my_strcmp(args[0], "exit") != 0) {
            line_exec(command[i], list, status, 0);
        }
        dup_in(pipe_fd);
        free_arr(args);
    }
    return i;
}

void status_pr(char **command, int *status, int in_fd, int i)
{
    int return_val = 0;

    dup2(in_fd, STDIN_FILENO);
    for (int j = 0; j != i - 1; j++) {
        wait(&return_val);
        print_status(status, return_val);
    }
    free_arr(command);
}

static int error_exec(char **command, int out_fd, int i)
{
    dup2(out_fd, STDOUT_FILENO);
    if (i == -1) {
        free_arr(command);
        return 0;
    }
    return 1;
}

int piper(char *buf, list_t *list, int *status)
{
    int in_fd = dup(STDIN_FILENO);
    int out_fd = dup(STDOUT_FILENO);
    char **command = my_str_to_word_array(buf, "|\n");
    int pipe_fd[2];
    int i;

    if (size_arr(command) < 2){
        free_arr(command);
        return 0;
    }
    i = pipe_loop(pipe_fd, command, list, status);
    if (error_exec(command, out_fd, i) == 0)
        return 0;
    if (line_exec(command[i], list, status, 1) == -1) {
        dup2(in_fd, STDIN_FILENO);
        free_arr(command);
        return -1;
    }
    status_pr(command, status, in_fd, i);
    return 1;
}
