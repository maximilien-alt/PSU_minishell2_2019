/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_X.c
*/

#include <stdarg.h>

void my_putnbr_base(int nbr, char *base);

void my_print_upcase_x(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
    return;
}