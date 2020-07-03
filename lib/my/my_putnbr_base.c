/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_putnbr_base.c
*/

void    my_putchar(char c);

int    my_strlen(char const *str);

int    my_putnbr_base(int nbr, char const *base)
{
    int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_base(nbr / len, base);
    }
    nbr = nbr % len;
    my_putchar(base[nbr]);

    return (0);
}
