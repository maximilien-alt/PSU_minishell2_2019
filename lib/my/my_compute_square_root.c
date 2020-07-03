/*
** EPITECH PROJECT, 2019
** MY_COMPUTE_SQUARE_ROOT
** File description:
** square root
*/

int    my_compute_square_root(int nb)
{
    int a = 0;

    while (a*a < nb) {
        a++;
            }
    if (a*a > nb) {
        return (0);
    }
    return (a);
}
