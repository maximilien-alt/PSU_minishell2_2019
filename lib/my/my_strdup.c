/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char    *my_strdup(char const *src)
{
    char *dup = NULL;
    int current = 0;

    dup = malloc(sizeof(char) * my_strlen(src) + 1);
    if (!dup)
        return (NULL);
    for (current = 0; src[current]; current += 1)
        dup[current] = src[current];
    dup[current] = '\0';
    return (dup);
}
