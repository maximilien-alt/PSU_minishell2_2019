/*
** EPITECH PROJECT, 2019
** MY_PUTSTR
** File description:
** Display, the characters of a string
*/

#include <unistd.h>

void my_putchar(char c);

int my_strlen(char const *str);

int    my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
