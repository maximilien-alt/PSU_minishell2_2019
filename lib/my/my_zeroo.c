/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_zeroo.h
*/

#include <stdlib.h>

char    *my_zeroo(char *str, char *mult)
{
    char *res;
    int sign = 1;
    for (int icr = 0; str[icr] == '-'; icr += 1)
        sign = sign * (-1);
    for (int icr = 0; mult[icr] == '-'; icr += 1)
        sign = sign * (-1);
    if (sign > 0) {
        res = malloc(sizeof(char) * 2);
        res[0] = '0';
        res[1] = '\0';
    }
    else {
        res = malloc(sizeof(char) * 3);
        res[0] = '-';
        res[1] = '0';
        res [2] = '\0';
    }
    return (res);
}