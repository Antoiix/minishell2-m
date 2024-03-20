/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** execution.c
*/

#include "my.h"

static void cat_path(char *tmp_path, char **paths, int i, char *arg)
{
    my_strcpy(tmp_path, paths[i]);
    my_strcat(tmp_path, "/");
    my_strcat(tmp_path, arg);
}

char *different_paths(list_t *list, char *arg)
{
    char *tmp_path = NULL;
    list_t *tmp = list;
    char **paths;
    int size = 0;

    for (; my_strcmp(tmp->arg, "PATH") != 0; tmp = tmp->next);
    paths = my_str_to_word_array(tmp->val, "\n:");
    for (int i = 0; paths[i] != NULL; i++) {
        size = my_strlen(paths[i]) + my_strlen(arg) + 2;
        tmp_path = malloc(sizeof(char) * size);
        cat_path(tmp_path, paths, i, arg);
        tmp_path[size - 1] = '\0';
        if (access(tmp_path, F_OK) == 0) {
            free_arr(paths);
            return tmp_path;
        }
        free(tmp_path);
    }
    free_arr(paths);
    return NULL;
}

int put_on_path(char **path, char **args, list_t *list)
{
    char *path_found = different_paths(list, args[0]);

    if (path_found) {
        *path = my_strdup(path_found);
    } else
        *path = my_strdup(args[0]);
    free(path_found);
    if (access(*path, F_OK) == 0)
        return 1;
    write(2, args[0], my_strlen(args[0]));
    write(2, ": Command not found.\n", 21);
    return 0;
}

static void command_exec(char *path, char **args, list_t *list)
{
    char **env = list_to_env(list);

    if (execve(path, args, env) == -1) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": ", 2);
        write(2, strerror(errno), my_strlen(strerror(errno)));
        if (errno == ENOEXEC)
            write(2, ". Wrong Architecture", 20);
        write(2, ".", 1);
        write(2, "\n", 1);
        free(path);
        exit(1);
    }
}

void print_status(int *status, int return_val)
{
    if (WEXITSTATUS(return_val) == 1) {
        *status = 1;
        return;
    }
    *status = return_val % 255;
    if (return_val == 0)
        return;
    write(2, strsignal(WTERMSIG(return_val)),
        my_strlen(strsignal(WTERMSIG(return_val))));
    if (WCOREDUMP(return_val))
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
}

int error_commands(char **args, char **path, int *status, list_t *list)
{
    if (args[0] == NULL) {
        free(path);
        return 1;
    }
    if (put_on_path(path, args, list) == 0) {
        free(*path);
        *status = 1;
        return 1;
    }
    return 0;
}

void verif_commands(char *buf, list_t *list, int *status)
{
    char **args;
    int val_f;
    int return_val = 0;
    char *path = NULL;

    args = my_str_to_word_array(buf, " \n\t");
    if (error_commands(args, &path, status, list) == 1) {
        free_arr(args);
        return;
    }
    val_f = fork();
    if (val_f == 0)
        command_exec(path, args, list);
    waitpid(val_f, &return_val, 0);
    print_status(status, return_val);
    free_arr(args);
    free(path);
}
