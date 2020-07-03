/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** my_strstr
*/

#include <stdio.h>

char    *my_strstr(char *str, char const *to_find)
{
    int a = 0;
    int b = 0;

    while (str[a] != '\0') {
        while (str[a] == to_find[b] && str[a] != '\0') {
            a++;
            b++;
        }
        if (to_find[b] == '\0') {
            a = a - b;
            return (&str[a]);
        }
        b = 0;
        a++;
    }
    return (NULL);
}
