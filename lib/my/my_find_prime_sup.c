/*
** EPITECH PROJECT, 2019
** MY_FIND_PRIME_SUP
** File description:
** return a prime number
*/

int    my_prime(int nb)
{
    int i = 2;

    if (nb <= 1) {
        return (0);
    }
    while (nb % i != 0) {
        i++;
    }
    if (i == nb) {
        return (1);
    }
    return (0);
}

int    my_find_prime_sup(int nb)
{
    int c = my_prime(nb);
    int u = nb;

    if (c == 0) {
        u++;
        my_find_prime_sup(u);
    }
    if (c == 1) {
        return (u);
    }

    return (0);
}
