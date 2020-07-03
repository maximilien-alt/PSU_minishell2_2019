/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_delete_neg.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char    *my_delete_neg(char *str)
{
    int letter = 0;
    int str_len = my_strlen(str);
    char *cpy;
    int i = 0;

    if (str[letter] == '-') {
        cpy = malloc(sizeof(char) * str_len);
        letter += 1;
    } else {
        return (str);
    }
    while (str[letter]) {
        cpy[i] = str[letter];
        letter += 1;
        i += 1;
    }
    cpy[i] = '\0';
    return (cpy);
}