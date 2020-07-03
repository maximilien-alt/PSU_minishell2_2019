/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_u.c
*/

#include <stdarg.h>

void my_putchar(char c);

void my_put_long(long nbr)
{
    if (nbr >= 10) {
        my_put_long(nbr/10);
        my_putchar(nbr % 10 + '0');
    } else {
        my_putchar(nbr + '0');
    }
    return;
}

void my_print_u(va_list ap)
{
    long nbr = va_arg(ap, long);

    if (nbr >= 0) {
        my_put_long(nbr);
        return;
    }
    nbr *= -1;
    nbr = 4294967296 - nbr;
    my_put_long(nbr);
    return;
}