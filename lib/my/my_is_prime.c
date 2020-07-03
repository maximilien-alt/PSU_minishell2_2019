/*
** EPITECH PROJECT, 2019
** MY_IS_PRIME
** File description:
** is_prime
*/

int    my_is_prime(int nb)
{
    int i = 2;

    if (nb == 1 || nb < 0) {
        return (0);
    }
    while ((nb % i) != 0) {
        i++;
    }
    if (i == nb) {
        return (1);
    } else {
        return (0);
    }
}
