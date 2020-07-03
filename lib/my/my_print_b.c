/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_b.c
*/

#include <stdarg.h>

void my_putnbr_base(int nbr, char *base);

void my_print_b(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
}