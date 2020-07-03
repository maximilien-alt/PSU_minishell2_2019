/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_add_x_zero.c
*/

#include <stdlib.h>

char    *my_add_x_zero(int cursor)
{
    char *res;
    int x = 0;

    res = malloc(sizeof(char) * (cursor + 1));
    while (cursor > 0) {
        res[x] = '0';
        cursor += -1;
        x += 1;
    }
    res[x] = '\0';
    return (res);
}