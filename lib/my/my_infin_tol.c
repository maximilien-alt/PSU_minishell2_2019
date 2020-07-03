/*
** EPITECH PROJECT, 2019
** bistro matic
** File description:
** infinstrtol
*/

#include <stdlib.h>
#include <stdio.h>

int    is_operator(char c)
{
    return ((c == '(' || c == ')' || c == '+' || c == '-' ||
    c == '*' || c == '/' || c == '%'));
}

char    *my_par(char *str, char **endptr)
{
    char *result;
    int cursor = 1;
    int var = 1;
    int size = 0;

    while (!is_operator(str[cursor]) && str[cursor])
        cursor += 1;
    result = malloc(sizeof(char) * (cursor + 1));
    while (size < (cursor - 1)) {
        result[size] = str[var];
        size += 1;
        var += 1;
    }
    result[size] = '\0';
    *endptr = &str[size + 1];
    return (result);
}

char    *my_infin_tol(char *str, char **endptr)
{
    char *result;
    int cursor = 0;
    int size = 0;

    if (str[cursor] == '(') {
        result = my_par(str, endptr);
        return (result);
    }
    if (is_operator(str[cursor]) && str[cursor])
        cursor += 1;
    while (!is_operator(str[cursor]) && str[cursor])
        cursor += 1;
    result = malloc(sizeof(char) * (cursor + 1));
    while (size < cursor) {
        result[size] = str[size];
        size += 1;
    }
    result[size] = '\0';
    *endptr = &str[size];
    return (result);
}