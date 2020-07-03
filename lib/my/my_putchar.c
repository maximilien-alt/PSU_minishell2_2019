/*
** EPITECH PROJECT, 2019
** lfni
** File description:
** efu
*/

#include <unistd.h>

void    my_putchar(char c)
{
    write(1, &c, 1);
}
