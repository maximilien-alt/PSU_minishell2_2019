/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_d.c
*/

#include <stdarg.h>

void my_put_nbr(int nb);

void my_print_d(va_list ap)
{
    my_put_nbr((int) va_arg(ap, int));
    va_end(ap);
    return;
}