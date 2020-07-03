/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_mult_zero.c
*/

int my_strlen(char const *str);

int    my_mult_zero(char *mult)
{
    int res = 0;
    int var = 1;
    int len = my_strlen(mult) - 1;

    while (len > 0) {
        res += var;
        var += 1;
        len += -1;
    }
    return (res);
}