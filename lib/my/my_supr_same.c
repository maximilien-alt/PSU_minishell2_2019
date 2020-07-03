/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_supr_same.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char    *my_supr_same(char *str, char *strtemp)
{
    char *result;
    int str_len = my_strlen(str);
    int strtemp_len = my_strlen(strtemp);
    int c = str_len - strtemp_len;
    int cursor = 0;

    if (c > 0) {
        result = malloc(sizeof(char) * (c + 1));
        while (str[strtemp_len]) {
            result[cursor] = str[strtemp_len];
            strtemp_len += 1;
            cursor += 1;
            result[cursor] = '\0';
        }
        return (result);
    }
    return ("\0");
}