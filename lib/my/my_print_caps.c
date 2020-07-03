/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_S.c
*/

#include <stdarg.h>

void my_putchar(char c);

void my_putnbr_base(int nbr, char *base);

void my_print_upcase_s(va_list ap)
{
    int letter = 0;
    char *result = va_arg(ap, char *);
    int n;

    while (result[letter]) {
        if (result[letter] >= 32 && result[letter] <= 126) {
            my_putchar(result[letter]);
        } else {
        my_putchar('\\');
        my_putchar('0');
        if (result[letter] < 10)
            my_putchar('0');
        n = result[letter];
        my_putnbr_base(n, "01234567");
        }
        letter += 1;
    }
}