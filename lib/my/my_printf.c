/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include "../../include/my.h"

static format_t tab[11] =
{
    {'s', my_print_s},
    {'c', my_print_c},
    {'d', my_print_d},
    {'i', my_print_d},
    {'p', my_print_p},
    {'x', my_print_x},
    {'X', my_print_upcase_x},
    {'o', my_print_o},
    {'b', my_print_b},
    {'u', my_print_u},
    {'S', my_print_upcase_s}
};

void my_print(char *str, va_list ap, ...)
{
    int test = 0;

    for (int i = 0; i <= 11; i += 1) {
        if (str[1] == tab[i].c) {
            test += 1;
            tab[i].ptr(ap);
        }
    }
    if (test == 1)
        return;
    my_putchar('%');
    if (str[1] != '%')
        my_putchar(str[1]);
    return;
}

void my_printf(char *format, ...)
{
    int cursor = 0;
    va_list ap;

    if (format[cursor + 1] != '3')
        va_start(ap, format);
    while (format[cursor]) {
        if (format[cursor] == '%' && format[cursor + 1]) {
            my_print(&format[cursor], ap);
            cursor += 2;
        } else {
            my_putchar(format[cursor]);
            cursor += 1;
        }
    }
    va_end(ap);
}