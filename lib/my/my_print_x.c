/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_x.c
*/

#include <stdarg.h>

void my_putnbr_base(int nbr, char *base);

int my_putstr(char *str);

void my_print_x(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
    return;
}