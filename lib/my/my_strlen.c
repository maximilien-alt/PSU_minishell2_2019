/*
** EPITECH PROJECT, 2019
** MY_STRLEN
** File description:
** numbers of characters in a string
*/

#include <unistd.h>

void my_putchar(char c);

int    my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
