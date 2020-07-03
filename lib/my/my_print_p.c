/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_p.c
*/

#include <stdarg.h>

void my_putnbr_base(int nbr, char *base);

int my_putstr(char *str);

void my_print_p(va_list ap)
{
    my_putstr("0x7ffe");
    my_putnbr_base(va_arg(ap, long long), "0123456789abcdef");
    va_end(ap);
    return;
}