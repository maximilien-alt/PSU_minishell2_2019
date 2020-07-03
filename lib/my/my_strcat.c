/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *str);

char     *my_strcat(char *src, char *dest, int check)
{
    char *str_cat = NULL;
    int cat = 0;

    if (!src || src[0] == '\0') {
        str_cat = malloc(sizeof(char) * (my_strlen(dest) + 1));
        if (!str_cat)
            return (NULL);
    } else {
        str_cat = malloc(sizeof(char) * my_strlen(dest) + \
        my_strlen(src) + 1);
        if (!str_cat)
            return (NULL);
    }
    for (cat = 0; src && src[cat]; cat += 1)
        str_cat[cat] = src[cat];
    for (int key = 0; dest && dest[key]; key += 1, cat += 1)
        str_cat[cat] = dest[key];
    str_cat[cat] = '\0';
    if (check == 0 && src)
        free (src);
    return (str_cat);
}