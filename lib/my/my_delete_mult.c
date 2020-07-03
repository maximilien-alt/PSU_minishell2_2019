/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_delete_mult.c
*/

#include <stdlib.h>

int    my_strlen(char const *str);

char    *my_delete_mult(char *mult)
{
    char *new;
    int mult_len = my_strlen(mult);
    int var_mult = 1;
    int var_new = 0;

    new = malloc(sizeof(char) * my_strlen(mult));
    while (mult_len >= 1) {
        new[var_new] = mult[var_mult];
        var_new += 1;
        var_mult += 1;
        mult_len += -1;
    }
    return (new);
}