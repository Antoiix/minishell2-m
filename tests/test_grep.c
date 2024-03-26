/*
** EPITECH PROJECT, 2023
** testing_grep.c
** File description:
** abc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(pipe, test_grep)
{
    cr_redirect_stdout();
    system("echo \"ls | grep Ma | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M\" | ./mysh ");
    cr_assert_stdout_eq_str("Makefile\n");
}

Test(pipe, test_folder)
{
    cr_redirect_stdout();
    system("echo \"ls | grep include | grep i | grep u\" | ./mysh");
    cr_assert_stdout_eq_str("include\n");
}

Test(pipe, test_builtin)
{
    cr_redirect_stdout();
    system("echo \"env | grep SHELL=\" | ./mysh");
    cr_assert_stdout_eq_str("SHELL=/bin/bash\n");
}
