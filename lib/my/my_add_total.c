/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_add_total.c
*/

int my_strlen(char *str);

int my_mult_zero(char *str);

int    my_clean_add_total(char *str, char *mult)
{
    int zeros = my_mult_zero(mult);
    int spaces = my_strlen(mult);
    int digits = (my_strlen(str) + 1) * my_strlen(mult);
    int size = zeros + spaces + digits + 1;

    return (size);
}