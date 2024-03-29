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

static void dup_in(int pipe_fd[2])
{
    dup2(pipe_fd[0], STDIN_FILENO);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
}

int pipe_cond(char *command, int pipe_fd[2], list_t *list, int *status)
{
    char **args;

    pipe(pipe_fd);
    dup2(pipe_fd[1], STDOUT_FILENO);
    args = my_str_to_word_array(command, " \n\t");
    if (args[0] == NULL) {
        free_arr(args);
        return -1;
    }
    if (my_strcmp(args[0], "exit") != 0) {
        line_exec(command, list, status, 0);
    }
    dup_in(pipe_fd);
    free_arr(args);
    return 0;
}

int pipe_loop(command_t **command, list_t *list, int *sta)
{
    int val[2] = {0};
    char *str;
    int pipe_fd[2];
    int tmp_fd;

    for (val[0] = 0; command[val[0] + 1] != NULL; val[0] = val[0] + 1) {
        if (command[val[0]]->sep == '|')
            val[1] = pipe_cond(command[val[0]]->command, pipe_fd, list, sta);
        redir_loop(command, val, list, sta);
        if (command[val[0]]->sep == '<') {
            str = clean_str(command[val[0] + 1]->command);
            tmp_fd = open(str, O_RDONLY);
            free(str);
            dup2(tmp_fd, STDIN_FILENO);
            val[1] = redirect_l(command[val[0]]->command, list, sta);
        }
        if (val[1] == -1)
            return -1;
    }
    return val[0];
}

void status_pr(command_t **command, int *status, int in_fd, int i)
{
    int return_val = 0;

    dup2(in_fd, STDIN_FILENO);
    for (int j = 0; j != i - 1; j++) {
        wait(&return_val);
        print_status(status, return_val);
    }
    free_command(command);
}

static int error_exec(command_t **command, int out_fd, int i)
{
    dup2(out_fd, STDOUT_FILENO);
    if (i == -1) {
        free_command(command);
        return 0;
    }
    return 1;
}

static int piper2(command_t **com_list, list_t *list, int *status, int i)
{
    int in_fd = dup(STDIN_FILENO);
    int out_fd = dup(STDOUT_FILENO);

    if (size_com(com_list) < 2){
        free_command(com_list);
        return 0;
    }
    i = pipe_loop(com_list, list, status);
    if (error_exec(com_list, out_fd, i) == 0)
        return 0;
    if (com_list[i - 1]->sep != '>' && com_list[i - 1]->sep !=
    '<' && com_list[i - 1]->sep != 'r' && com_list[i - 1]->sep != 'l') {
        if (line_exec(com_list[i]->command, list, status, 1) == -1) {
            dup2(in_fd, STDIN_FILENO);
            free_command(com_list);
            return -1;
        }
    }
    status_pr(com_list, status, in_fd, i);
    return 1;
}

int piper(char *buf, list_t *list, int *status)
{
    command_t **com_list = com_list_c(buf);
    int i = 0;

    return piper2(com_list, list, status, i);
}
