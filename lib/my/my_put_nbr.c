/*
** EPITECH PROJECT, 2019
** MY_PUT_NBR
** File description:
** Display the number given as a parameter
*/

void my_putchar(char c);

int    my_limit_int(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
    return (0);
}

int    my_put_nbr(int nb)
{
    if (nb == (-2147483648)) {
        my_limit_int();
        return (0);
    }
    if (nb <0){
        my_putchar('-');
        nb = -nb;
    }

    if (nb >= 10) {
        my_put_nbr(nb/10);
        my_putchar(nb % 10 + '0');
    } else {
        my_putchar(nb + '0');
    }
    return (0);
}
