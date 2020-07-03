/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** minishell_check_special.c
*/

#include "../include/my.h"

void little_print(void)
{
    my_printf("Invalid null command.\n");
}

int should_parse(char c)
{
    return (c == '|' || c == ';' || c == '>' || c == '<');
}

int my_check_minishelll_two(char *buffer)
{
    for (int cursor = 0; buffer[cursor]; cursor += 1) {
        if (should_parse(buffer[cursor]))
            return (1);
    }
    return (0);
}