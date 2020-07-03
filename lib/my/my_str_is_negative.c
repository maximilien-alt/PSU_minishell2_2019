/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** my_str_is_negative.c
*/

int    my_str_is_negative(char *str)
{
    if (str[0] == '-') {
        return (1);
    }
    return (0);
}