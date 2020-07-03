/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_s.c
*/

#include <stdarg.h>

int my_putstr(char const *str);

void my_print_s(va_list ap)
{
    my_putstr((char *) va_arg(ap, char *));
    va_end(ap);
    return;
}