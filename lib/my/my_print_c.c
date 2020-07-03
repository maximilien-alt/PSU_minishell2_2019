/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_c.c
*/

#include <stdarg.h>

void my_putchar(char c);

void my_print_c(va_list ap)
{
    my_putchar(va_arg(ap, int));
    va_end(ap);
    return;
}