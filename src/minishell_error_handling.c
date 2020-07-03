/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell_error_handling.c
*/

#include "../include/my.h"

void my_free_tab(char **tab)
{
    for (int cursor = 0; tab[cursor]; cursor += 1)
        free (tab[cursor]);
    free (tab);
}

void disps_errors(int pid)
{
    switch (WTERMSIG(pid)) {
        case SIGSEGV:
            my_printf("Segmentation fault");
            break;
        case SIGFPE:
            my_printf("Floating exception");
            break;
    }
    if (WCOREDUMP(pid))
        my_printf(" (core dumped)");
    my_printf("\n");
}

void print_exec(char *command)
{
    if (errno == ENOEXEC)
        my_printf("%s: Exec format error. Wrong Architecture.\n", command);
    else
        my_printf("%s: %s.\n", command, strerror(errno));
}

void my_print_words(char *str, int current)
{
    if (my_strncmp(str, "point", 5) == 1) {
        if (current == 0)
            my_printf("%s", str);
        else
            my_printf(" %s", str);
    }
}

int my_disp_error(int pid)
{
    if (WIFSIGNALED(pid))
        disps_errors(pid);
    return (0);
}